#!/usr/bin/env python
# -*- coding: latin1 -*-
# -------------------------------------------------
# DepthK v1.0
# by Herbert Rocha
#
# e-mail: herberthb12@gmail.com
#
#
# The input should be .i already preprocessed by CIL
# -------------------------------------------------

from __future__ import print_function

import argparse
import shutil
import sys
import os
import commands
import re
import time
from pipes import quote
import platform



# From project
from modules.run_ast import ast
from modules.invariant_tools.pips.translate_pips import translate_pips
from modules.bmc_check import esbmccheck
from modules.gnu_extension import hack_extensions




# TODO:
# Precondition to usage:
# - all variables should be declared in top of the function [todo]
# - it is necessary to generate the invariante to the code
# (1) [DONE] Identify each variable and it type
# (2) [DONE] Read the code.pips identify #init, save the VAR#init and the function where it was find
# (3) [DONE] write new code where for each function identified in (2) we should add the new vars to VAR#init
# (4) [DONE] Read the code.pips and translate the annotations to __ESBMC. WARNNING: replace VAR#init to VAR_init
# (5) Checking the new code with ESBMC k-induction
# (6) From counterexample added a new ASSUME in the code



class DepthK(object):
    def __init__(self, _cfilepath):
        self.cfilepath = _cfilepath
        self.inputisexti = False
        self.listnumbeginfunc = []
        self.nameoforicprogram = os.path.basename(_cfilepath)
        self.actual_cprogramname = ""
        self.depthkname_ext = "_new_depthk_" + str(time.strftime('%H:%M:%S').replace(":", "_")) + ".c"
        self.debug_op = False
        self.uncrustify_cfg = os.path.dirname(os.path.abspath(__file__)) + \
                              "/modules/preprocessing/uncrustify_files/ben.cfg"
        self.onlygeninvs_p = False
        self.esbmcpath = ''
        self.esbmcsolver = ""
        self.esbmc_memlimit = ""
        self.esbmc_timeout = ""
        self.esbmc_extraop = ""
        self.esbmc_arch = ""
        self.maxk = 10
        self.maxdepthcheck = 25
        self.disableuse_ce = False
        self.pipsscriptpath = os.path.abspath(".") + \
                              '/modules/invariant_tools/pips/script_template/' + \
                              'script_generate_precod.pips'
        self.pipscommand = "tpips"
        self.pipsdatabaseresult = os.path.abspath(".") + '/precod.database'


    def identify_initpips(self, _cfilepath):
        """
        Read the code.pips identify #init, save the VAR#init and the function
        where it was find
        :param _cfilepath:
        :return:
        """

        # result
        dict_varinitandloc = {}

        # Get the number line where each function begin
        self.listnumbeginfunc = self.getnumbeginfuncts(_cfilepath)
        if not self.listnumbeginfunc:
            print("ERROR. Identifying functions")
            sys.exit()

        filec = open(_cfilepath, "r")
        linescfile = filec.readlines()
        filec.close()

        currentnumfunct = 0
        lastnumfunct = 0
        listsavevar_tmp = []
        flaginit = False
        flagchangefunc = False
        countfunct = 0

        for index, line in enumerate(linescfile):

            # identify the function that has been analyzed
            # How identify that we change of function
            if (index + 1) in self.listnumbeginfunc:
                countfunct += 0

                currentnumfunct = index + 1


                # we create a entry for each function
                # where each line function number receive a list
                # with the variables init identified
                dict_varinitandloc[currentnumfunct] = []


                # if flaginit:
                # flaginit = False
                # listsavevar_tmp = list(set(listsavevar_tmp))
                # print(lastnumfunct, listsavevar_tmp)
                # listsavevar_tmp = []
                #     #dict_varinitandloc[lastnumfunct] = listsavevar_tmp
                # else:
                #     lastnumfunct = currentnumfunct
                #     listsavevar_tmp = []
                #dict_varinitandloc[lastnumfunct] = []


            # elif countfunct > 0:


            # check if is a comment
            matchpipscommt = re.search(r'^//[ ]+', line)
            if matchpipscommt:

                matchpipsinit = re.findall(r'([a-zA-Z0-9_]+)#init', line)
                if matchpipsinit:
                    flaginit = True
                    # print(matchpipsinit," ---- FUNCT: ", currentnumfunct)
                    # remove variables duplicated
                    listcleanvar = list(set(matchpipsinit))
                    for var in listcleanvar:
                        # listsavevar_tmp.append(var)
                        # Checkig if we have math operation with the variable, e.g., 8num#init
                        matchmathmult = re.search(r'^[0-9]+(.*)', var)
                        if matchmathmult:
                            var = matchmathmult.group(1)

                        matchmathoperation = re.search(r'^[0-9]+[+-\\*/](.*)', var)
                        if matchmathoperation:
                            var = matchmathoperation.group(1)

                        dict_varinitandloc[currentnumfunct].append(var)

                    dict_varinitandloc[currentnumfunct] = list(set(dict_varinitandloc[currentnumfunct]))


        # removing key without values
        # for key, value in dict_varinitandloc.items():
        # if not value:
        # del dict_varinitandloc[key]
        #
        # for key, value in dict_varinitandloc.items():
        # print(key, value)
        # print("")
        #
        # sys.exit()
        return dict_varinitandloc


    def generatecodewithinit(self, _cfilepath_from_pipsdb, _cfileanalyzed, _dicvarinitandloc):
        """
        write new code where for each function identified in (2) we should add
        the new vars to VAR#init

        :param _cfilepath_from_pipsdb:
        :param _dicvarinitandloc:
        :return: pathcodewithinit
        """

        # generating path to save this new code generated
        # new_namefile = os.path.basename(_cfilepath).replace(".i", "_depthk_t.c")
        #pathnewfile = os.path.dirname(_cfilepath) + "/" + new_namefile
        #pathcodewithinit = "/tmp/" + str(os.path.basename(_cfilepath_from_pipsdb).replace(".c", "_init.c"))
        pathcodewithinit = _cfileanalyzed
        filewithinit = open(pathcodewithinit, "w")

        flag_initpips = True
        if not _dicvarinitandloc:
            flag_initpips = False


        # Get lines from C file
        filec = open(_cfilepath_from_pipsdb, "r")
        linescfile = filec.readlines()
        filec.close()

        # Get all variable declaration data
        r = ast.RunAstDecl(_cfilepath_from_pipsdb)
        # output: {'z_val': [['int'], '164']}
        dict_varsdata = r.identify_decl()

        count = 0
        while count < len(linescfile):

            # print(linescfile[count],end="")
            filewithinit.write(linescfile[count])

            nextline = count + 1
            if nextline in self.listnumbeginfunc:
                # print delimiter
                # print(linescfile[nextline],end="")
                filewithinit.write(linescfile[nextline])
                count = nextline

                if _dicvarinitandloc.has_key(nextline):
                    for var in _dicvarinitandloc[nextline]:
                        # print("INIT: ", var)
                        # Creating INIT vars
                        #print(">>>>>> ", dict_varsdata[var][0])
                        #print(var)
                        #print("INIT: ", dict_varsdata[var][0], var+"_init")
                        nametype = ' '.join(dict_varsdata[var][0])
                        #print(nametype+str(" " + var + "_init = " + var + ";"))
                        filewithinit.write(nametype + str(" " + var + "_init = " + var + "; \n"))

                        #sys.exit()

            count += 1

        filewithinit.close()

        return pathcodewithinit


    def translatepipsannot(self, _cpathpipscode):

        # Get the number line where each function begin
        listnumbeginfunc = self.getnumbeginfuncts(_cpathpipscode)
        if not self.listnumbeginfunc:
            print("ERROR. Identifying functions")
            sys.exit()

        if self.debug_op:
            print(">> Translating the PIPS annotation with the invariants")
        # Call class to translate PIPS annotation
        runtranslatepips = translate_pips.PipsTranslateAnnot()
        #runtranslatepips.nameoforicprogram = self.nameoforicprogram
        runtranslatepips.list_beginnumfuct = listnumbeginfunc

        # print(runtranslatepips.instprecondinprog(_cpathpipscode))
        # sys.exit()
        return runtranslatepips.instprecondinprog(_cpathpipscode)


    @staticmethod
    def getnumbeginfuncts(_cfilepath):

        # result
        listbeginnumfuct = []

        # get data functions using ctags
        textdata = commands.getoutput("ctags -x --c-kinds=f " + _cfilepath)

        # generate a list with the data funct
        listdatafunct = textdata.split("\n")
        for linedfunct in listdatafunct:
            # split by space
            matchlinefuct = re.search(r'function[ ]+([0-9]+)', linedfunct)
            if matchlinefuct:
                # consider the line number of index program in the list
                listbeginnumfuct.append(int(matchlinefuct.group(1).strip()))

        return listbeginnumfuct


    def callesbmccheck(self, _cfilepath, _enableforceassume):
        runesbmc = esbmccheck.DepthEsbmcCheck()
        runesbmc.esbmcpath = self.esbmcpath
        runesbmc.maxk = self.maxk
        runesbmc.maxdepthverification = self.maxdepthcheck
        runesbmc.debug = self.debug_op
        runesbmc.esbmc_memlimit_op = self.esbmc_memlimit
        runesbmc.esbmc_timeout_op = self.esbmc_timeout
        runesbmc.esbmc_arch = self.esbmc_arch
        runesbmc.esbmc_extra_op = self.esbmc_extraop
        runesbmc.disableuse_ce = self.disableuse_ce
        if _enableforceassume:
            runesbmc.forceassume = True
        else:
            runesbmc.forceassume = False
        # runesbmc.esbmc_extra_op = self.esbmc_extraop

        if not self.esbmcsolver == "z3":
            runesbmc.esbmc_solver_op = "--" + self.esbmcsolver.strip()

        print(runesbmc.kinductioncheck(_cfilepath))


    def generatepipsscript(self, _cfilepath):

        # Getting path from C file
        cpathnamefile = os.path.dirname(_cfilepath)

        # Generating pips script
        destscript = cpathnamefile + "/script_depthk.pips"
        shutil.copyfile(self.pipsscriptpath, destscript)

        # Write the name of the C program in the PIPS script
        os.system("sed -i \'s@<FILE.C_INPUT>@" + _cfilepath + "@g\' " + destscript)

        return destscript

    def runpips(self, _scriptpips, _cfilepath, _listfiles2delete):

        # getting only the name of the file
        namecfile = os.path.basename(_cfilepath)

        if self.debug_op:
            print(">> Running PIPS to generate the invariants")
        # run script with tpips
        resultpips = commands.getoutput(self.pipscommand + " " + _scriptpips)

        # Checking errors from PIPS
        matcherrorpips1 = re.search(r'tpips_user_error: Abort on user error requested!', resultpips)
        # Aborted                 (core dumped)
        matcherrorpips2 = re.search(r'(core dumped)', resultpips)
        if matcherrorpips1 or matcherrorpips2:
            if self.debug_op:
                print("\t - A problem was identified in PIPS.\n\t - Trying check by counterexample")
            # print(resultpips)
            # # Identify parser errors
            # # C syntax errors in file
            # matcherrorparser = re.search(r"C syntax errors in file", resultpips)
            # if matcherrorparser:
            # print(" ")
            # print("ERROR. C syntax errors in C file. ")
            # else:
            #     print(" ")
            #     print("ERROR. Generating invariants with PIPS. ")
            #
            # self.cleantmpfiles(_listfiles2delete)
            # sys.exit()

            # >> In this, some problem was identified in PIPS.
            #    This way, we try to check the program adopting only
            #    the counterexample of ESBMC
            # The syntax erros and others should be identified by ESBMC
            return ""




        # get the path of the file generated by PIPS
        codegeneratedbypips = self.pipsdatabaseresult + "/Src/" + namecfile

        # sys.exit()

        return codegeneratedbypips


    def cleantmpfiles(self, _listfiles2delete):

        # delete the PIPS database
        if os.path.exists(self.pipsdatabaseresult):
            shutil.rmtree(self.pipsdatabaseresult)

        for filepath in _listfiles2delete:
            if os.path.exists(filepath):
                os.remove(filepath)

                # delete script to generate the invariants
                # if os.path.exists(_scriptpips):
                # os.remove(_scriptpips)
                #
                # # delete code with auxiliary code to #init
                # if os.path.exists(_pathcodeinit):
                # os.remove(_pathcodeinit)

    @staticmethod
    def checkesbmcsolversupport(_namesolver):
        if _namesolver == "z3":
            return True
        if _namesolver == "boolector":
            return True
        else:
            return False


    def applygnuhack(self, _inputcfile):
        # Mini hack to allow PIPS handle with .i files
        # new_namefile = os.path.basename(_inputcfile).replace(".i", self.depthkname_ext)
        # pathnewfile = os.path.dirname(_inputcfile) + "/" + new_namefile
        filec = open(inputCFile, 'r')
        str_filelines = hack_extensions.make_pycparser_compatible(filec.read())
        filec.close()

        # writing new c file after GNU hacking
        newfile = open(_inputcfile, "w")
        newfile.write(str_filelines)
        newfile.close()

        return _inputcfile


    def rununcrustify(self, _cfilepath):
        # if self.inputisexti:
        # new_namefile = os.path.basename(_cfilepath).replace("_depthk_t.c", "_depthk_u.c")
        # else:
        #     new_namefile = os.path.basename(_cfilepath).replace(".c", "_depthk_u.c")
        #
        # pathnewfile = os.path.dirname(_cfilepath) + "/" + new_namefile

        result_uncrustify = commands.getoutput('uncrustify -q -l C -c ' + quote(self.uncrustify_cfg) +
                                               ' -f ' + quote(_cfilepath))

        filewriteunc = open(_cfilepath, "w")
        filewriteunc.write(result_uncrustify)
        filewriteunc.close()

        return _cfilepath


# -------------------------------------------------
# Main python program
# -------------------------------------------------

if __name__ == "__main__":

    # ############ Parse args options

    parser = argparse.ArgumentParser(description='Run DepthK v1.0')
    parser.add_argument('-v', '--version', action='version', version="version 1.0")
    parser.add_argument(dest='inputCProgram', metavar='file.c or file.i (experimental)', type=str,
                        help='the C program file to be analyzed')
    parser.add_argument('-k', '--max-k-step', metavar='nr', type=int, dest='setMaxK',
                        default=15, help='set the max k time step (default is 15)')
    parser.add_argument('-d', '--max-depth-check', metavar='nr', type=int, dest='setMaxDepthCheck',
                        default=25, help='set the max number of P\' to be generated (default is 25)')
    parser.add_argument('-p', '--generate-program-inv', action="store_true", dest='setOnlyGenInv',
                        help='generates the program with the invariants', default=False)
    parser.add_argument('-o', '--only-counter-example', action="store_true", dest='setOnlyCEUse',
                        help='adopt only the counterexample to generate the assumes', default=False)
    parser.add_argument('-i', '--disable-counter-example', action="store_true", dest='setDisableCEUse',
                        help='disable the adoption of the counterexample to generate the assumes', default=False)
    parser.add_argument('-n', '--not-remove-new-code', action="store_true", dest='setNotRemoveNewCode',
                        help='not remove the code generated by depthk', default=False)
    # --16, --32, --64             set width of machine word
    parser.add_argument('-a', '--arch', metavar='nr', type=int, dest='setArchCheck',
                        default="64", help='set width of machine word (16, 32 or 64) to ESBMC (default is 64)')
    parser.add_argument('-s', '--solver', metavar='name', type=str, dest='setESBMCSolver',
                        help='set the solver to adopted by ESBMC (default is Z3)', default="z3")
    parser.add_argument('-m', '--memlimit', metavar='nr', type=str, dest='setMemESBMC',
                        help='configure memory limit to ESBMC, of form \"100m\" or \"2g\"', default="")
    parser.add_argument('-t', '--timeout', metavar='nr', type=str, dest='setTOESBMC',
                        help='configure time limit  to ESBMC (default is 15m), integer followed by {s,m,h}',
                        default="15m")
    parser.add_argument('-e', '--extra-option-esbmc', metavar='options', type=str, dest='setOpESBMC',
                        help='set extra options to ESBMC (default --no-library). '
                             'Usage way: -e=\"--bv --no-bounds-check\"', default="--no-library")
    parser.add_argument('-g', '--debug', action="store_true", dest='setDebug',
                        help='generates debug information', default=False)
    # parser.add_argument('-s', '--statistics', action="store_true", dest='setInfo',
    # help='generate data about the DepthK execution', default=False)



    args = parser.parse_args()

    inputCFile = ''
    if args.inputCProgram:
        if not os.path.isfile(args.inputCProgram):
            print('Error: unable to open input file (%s)' % quote(args.inputCProgram))
            parser.parse_args(['-h'])
            sys.exit()
        else:
            list_paths_to_delete = []

            inputCFile = os.path.abspath(quote(args.inputCProgram))

            rundepthk = DepthK(inputCFile)

            # Define ESBMC path
            rundepthk.esbmcpath = "esbmc"
            # rundepthk.esbmcpath = "~/Downloads/ESBMC/bin/esbmc_v24"
            if args.setMaxK:
                rundepthk.maxk = args.setMaxK
            if args.setMaxDepthCheck:
                rundepthk.maxdepthcheck = args.setMaxDepthCheck
            if args.setDebug:
                rundepthk.debug_op = args.setDebug
            if args.setOnlyGenInv:
                rundepthk.onlygeninvs_p = args.setOnlyGenInv
            if args.setMemESBMC:
                rundepthk.esbmc_memlimit = args.setMemESBMC
            if args.setTOESBMC:
                rundepthk.esbmc_timeout = args.setTOESBMC
            if args.setOpESBMC:
                rundepthk.esbmc_extraop = args.setOpESBMC
            if args.setDisableCEUse:
                rundepthk.disableuse_ce = args.setDisableCEUse
            if args.setESBMCSolver:
                # Checking if this solver is supported by ESBMC
                if rundepthk.checkesbmcsolversupport(args.setESBMCSolver):
                    rundepthk.esbmcsolver = args.setESBMCSolver
                else:
                    print("ERROR. This solver is not supported yet.")
                    sys.exit()
            # setArchCheck
            if not args.setArchCheck == 64:
                if args.setArchCheck == 16 or args.setArchCheck == 32:
                    rundepthk.esbmc_arch = "--" + str(args.setArchCheck)
                else:
                    print("")
                    print("ERROR. The width of machine word is not valid")
                    print("")
                    parser.parse_args(['-h'])
                    sys.exit()
            else:
                #64bits
                rundepthk.esbmc_arch = "--" + str(args.setArchCheck)

            # Identify the extension of the C program .c or .i
            if inputCFile.endswith(".i"):
                # Warnning: This is experimental cuz PIPS actually
                # have some problem with CIL format

                # Creating a copy of the analyzed program
                new_namefile = os.path.basename(inputCFile).replace(".i", rundepthk.depthkname_ext)
                pathnewinstance_depthk = os.path.dirname(inputCFile) + "/" + new_namefile
                shutil.copyfile(inputCFile, pathnewinstance_depthk)
                inputCFile = pathnewinstance_depthk
                if not args.setNotRemoveNewCode:
                    list_paths_to_delete.append(inputCFile)

                rundepthk.inputisexti = True

            else:
                # Creating a copy of the analyzed program
                new_namefile = os.path.basename(inputCFile).replace(".c", rundepthk.depthkname_ext)
                pathnewinstance_depthk = os.path.dirname(inputCFile) + "/" + new_namefile
                shutil.copyfile(inputCFile, pathnewinstance_depthk)
                inputCFile = pathnewinstance_depthk
                if not args.setNotRemoveNewCode:
                    list_paths_to_delete.append(inputCFile)


            # Apply hacking to handle with GNU extensions
            # HackGNUext: Generate a copy the analyzed program to a tmp file
            # now with the extension replaced from .i to .c
            inputCFile = rundepthk.applygnuhack(inputCFile)
            #print(inputCFile)
            #sys.exit()

            # Applying the preprocess code - Define a specific format to code
            inputCFile = rundepthk.rununcrustify(inputCFile)


            codewithinv = ""
            if not args.setOnlyCEUse:
                # Applying steps of DepthK
                # Generating pips script
                scriptpipspath = rundepthk.generatepipsscript(inputCFile)
                list_paths_to_delete.append(scriptpipspath)

                # Generating invariants with PIPS
                codewithinv = rundepthk.runpips(scriptpipspath, inputCFile, list_paths_to_delete)

            if args.setOnlyCEUse and rundepthk.debug_op:
                print(">> Adopting only the ESBMC counterexample to generate assumes")

            if codewithinv:
                # Identify #init from PIPS in the code with invariants
                dict_init = rundepthk.identify_initpips(codewithinv)

                # Generate auxiliary code to support the translation of #init from PIPS
                pathcodeinit = rundepthk.generatecodewithinit(codewithinv, inputCFile, dict_init)

                # Translate the invariants generated by PIPS
                pathcodepipstranslated = rundepthk.translatepipsannot(pathcodeinit)

                if rundepthk.onlygeninvs_p:
                    # Removing tmp files
                    os.system("cat " + pathcodepipstranslated)
                    rundepthk.cleantmpfiles(list_paths_to_delete)
                    sys.exit()

                # Execute the k-induction with ESBMC
                rundepthk.callesbmccheck(pathcodepipstranslated, False)

            else:
                # Execute the k-induction with ESBMC
                rundepthk.callesbmccheck(inputCFile, True)

            # Removing tmp files
            rundepthk.cleantmpfiles(list_paths_to_delete)





