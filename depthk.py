#!/usr/bin/env python
# -*- coding: latin1 -*-
# -------------------------------------------------
# DepthK v3.1
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
import random
import string
from pipes import quote
import platform
import time

# From project
from modules.run_ast import ast
from modules.invariant_tools.pips.translate_pips import translate_pips
from modules.invariant_tools.pagai.translate_inv_pagai import translate_pagai
from modules.invariant_tools.pagai.generate_inv_pagai import generate_inv_pagai
from modules.bmc_check import esbmccheck
from modules.gnu_extension import hack_extensions

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
        self.en_kparalell = False
        self.esbmcpath = ''
        self.esbmcsolver = ""
        self.esbmc_memlimit = ""
        self.esbmc_timeout = ""
        self.esbmc_extraop = ""
        self.esbmc_arch = ""
        self.maxk = 10
        self.maxdepthcheck = 25
        #self.disableuse_ce = False
        self.use_counter_example = False
        self.pipsscriptpath = os.path.abspath(".") + \
                              '/modules/invariant_tools/pips/script_template/' + \
                              'script_generate_precod.pips'
        self.pipscommand = "tpips"
        self.idresultpipsdb = random.choice(string.letters) + str(int(round(time.time() * 1000)))
        #self.pipsdatabaseresult = os.path.abspath(".") + '/precod' + self.idresultpipsdb + ''
        self.pipsdatabaseresult = 'precod' + self.idresultpipsdb + ''
        self.pipsdatabaseresultpath = ""
        self.debug_gh = False
        self.root_path = commands.getoutput("pwd")

        self.esbmc_is_memory_safety = False
        self.esbmc_is_termination = False
        self.esbmc_overflow_check = ""
        self.listproperty = ""
        self.start_time = time.time()


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


    def callesbmccheck(self, _cfilepath, _enableforceassume, _enablelastcheckbasecase):
        runesbmc = esbmccheck.DepthEsbmcCheck()
        runesbmc.esbmcpath = self.root_path + "/" + self.esbmcpath
        runesbmc.esbmcpath = self.esbmcpath
        runesbmc.maxk = self.maxk
        runesbmc.maxdepthverification = self.maxdepthcheck
        runesbmc.debug = self.debug_op
        runesbmc.esbmc_memlimit_op = self.esbmc_memlimit
        runesbmc.esbmc_timeout_op = self.esbmc_timeout
        runesbmc.esbmc_arch = self.esbmc_arch
        runesbmc.esbmc_extra_op = self.esbmc_extraop
        runesbmc.en_kparalell = self.en_kparalell
        rundepthk.use_counter_example = self.use_counter_example
        runesbmc.root_path = self.root_path

        runesbmc.is_memory_safety = self.esbmc_is_memory_safety
        runesbmc.is_termination = self.esbmc_is_termination
        runesbmc.overflow_check = self.esbmc_overflow_check
        runesbmc.original_file = self.cfilepath
        runesbmc.listproperty = self.listproperty
        runesbmc.start_time = self.start_time

        if _enableforceassume:
            runesbmc.forceassume = True
        else:
            runesbmc.forceassume = False
        
        if _enablelastcheckbasecase:
            runesbmc.moreonecheckbasecase = True
        else:
            runesbmc.moreonecheckbasecase = False
        # runesbmc.esbmc_extra_op = self.esbmc_extraop

        if not self.esbmcsolver == "z3":
            runesbmc.esbmc_solver_op = "--" + self.esbmcsolver.strip()

        print(runesbmc.kinductioncheck(_cfilepath))


    def generatepipsscript(self, _cfilepath):

        # Getting path from C file
        # cpathnamefile = os.path.dirname(_cfilepath)

        namefilescript = re.sub("\.c$|\.i$","", _cfilepath)

        # Generating pips script
        destscript = namefilescript + "_script_depthk.pips"
        shutil.copyfile(self.pipsscriptpath, destscript)

        # Write the name of the C program in the PIPS script
        os.system("sed -i \'s@<FILE.C_INPUT>@" + _cfilepath + "@g\' " + destscript)

        # Write the name of the PIPS DB in the PIPS script
        os.system("sed -i \'s@<PIPS.DB>@" + self.pipsdatabaseresult + "@g\' " + destscript)

        return destscript

    def runpips(self, _scriptpips, _cfilepath, _listfiles2delete):

        # getting only the name of the file
        namecfile = os.path.basename(_cfilepath)

        #if self.debug_op:
        #    print(">> Running PIPS to generate the invariants")

        # run script with tpips
        # TODO: Add a timout
        init_inv_t = time.time()
        #resultpips = commands.getoutput(self.pipscommand + " " + _scriptpips)
        resultpips = commands.getoutput("timeout --signal=9 8m " + self.pipscommand + " " + _scriptpips)
        #os.system("timeout --signal=9 8m " + self.pipscommand + " " + _scriptpips)
        #sys.exit()
        end_inv_t = time.time()

        # print(resultpips)

        # Checking errors from PIPS
        #matcherrorpips0 = re.search(r'(user error in)', resultpips)
        #matcherrorpips0not = re.search(r'(user error in parse_properties)', resultpips)
        # get the path of the file generated by PIPS
        codegeneratedbypips = os.path.abspath(".") + "/" + self.pipsdatabaseresult + ".database/Src/" + namecfile
        codegeneratedbypips_src = os.path.abspath(".") + "/" + self.pipsdatabaseresult + ".database/Src"
        # code from pips not generated
        matcherrorpips0 = False
        if not os.listdir(codegeneratedbypips_src):
            matcherrorpips0 = True

        matcherrorpips1 = re.search(r'(tpips_user_error: Abort on user error requested!)', resultpips)
        # Aborted                 (core dumped)
        matcherrorpips2 = re.search(r'(core dumped)', resultpips)
        # timeout: the monitored command dumped core
        matcherrorpips3 = re.search(r'(timeout: the monitored command dumped core)', resultpips)

        # Identify if happen a TO
        flag_TO_inv = False
        if (end_inv_t - init_inv_t) > 480:  # 8m
            flag_TO_inv = True


        if matcherrorpips0 or matcherrorpips1 or matcherrorpips2 or matcherrorpips3 or flag_TO_inv:
            if self.debug_op:
                if flag_TO_inv:
                    print("\t - TIMEOUT to generate the invariants.")
                else:
                    #print(matcherrorpips0.group(0))
                    print("\t - A problem was identified in PIPS.")

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
            #sys.exit()
            return ""


        # print(codegeneratedbypips)
        self.pipsdatabaseresultpath = os.path.abspath(".") + "/" + self.pipsdatabaseresult + ".database"

        # sys.exit()

        return codegeneratedbypips


    def cleantmpfiles(self, _listfiles2delete):

        if os.path.exists(self.pipsdatabaseresultpath):
            shutil.rmtree(self.pipsdatabaseresultpath)

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
        if _namesolver == "mathsat":
            return True
        else:
            return False


    def applygnuhack(self, _inputcfile):
        # Mini hack to allow PIPS handle with .i files
        # new_namefile = os.path.basename(_inputcfile).replace(".i", self.depthkname_ext)
        # pathnewfile = os.path.dirname(_inputcfile) + "/" + new_namefile

        filec = open(_inputcfile, 'r')

        # if self.debug_gh:
        #     print(_inputcfile)
        #     #os.system("cat " + _inputcfile)
        #     print(filec.read())
        #     sys.exit()

        str_filelines = hack_extensions.make_pycparser_compatible(filec.read())
        filec.close()

        #os.system("cat "+_inputcfile)
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

    parser = argparse.ArgumentParser(description='Run DepthK v3.1')
    parser.add_argument('-v', '--version', action='version', version="version 3.1 - Fri Jan  6 18:14:20 AMT 2018")
    parser.add_argument(dest='inputCProgram', metavar='file.c or file.i (experimental)', type=str,
                        help='the C program file to be analyzed')
    parser.add_argument('-k', '--max-k-step', metavar='nr', type=int, dest='setMaxK',
                        default=100, help='set the max k time step (default is 100)')
    parser.add_argument('-d', '--max-depth-check', metavar='nr', type=int, dest='setMaxDepthCheck',
                        default=25, help='set the max number of P\' to be generated (default is 25)')
    parser.add_argument('-p', '--generate-program-inv', action="store_true", dest='setOnlyGenInv',
                        help='generates the program with the invariants', default=False)
    parser.add_argument('-l', '--k-induction-parallel', action="store_true", dest='setKParallel',
                        help='prove by k-induction, ESBMC runs each step on a separate process', default=False)
    parser.add_argument('-c', '--force-check-base-case', action="store_true", dest='setForceBaseCase',
                        help='force a last check in the base case of the k-induction algorithm', default=True)
    parser.add_argument('-i', '--invariant-generation', metavar='name', type=str, dest='setInvariantTool',
                        help='set the invariant generation {pips, pagai, all} to be adopted (default is pips)', default="pagai")

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
                        help='set extra options to ESBMC '
                             'Usage way: -e=\"--bv --no-bounds-check\"')
    parser.add_argument('-g', '--debug', action="store_true", dest='setDebug',
                        help='generates debug information', default=False)

    #parser.add_argument('--disable-counter-example', action="store_true", dest='setDisableCEUse',
    #                    help='disable the adoption of the counterexample to generate the assumes', default=True)
    parser.add_argument('--not-remove-new-code', action="store_true", dest='setNotRemoveNewCode',
                        help='not remove the code generated by depthk', default=False)
    parser.add_argument('--only-counter-example', action="store_true", dest='setOnlyCEUse',
                        help='adopt only the counterexample to generate the assumes', default=False)

    parser.add_argument('-w', '--overflow-check', action="store_true", dest='setOverflowCheck', help='Checks overflow', default=False)

    parser.add_argument('-x', '--memory-safety-category', action="store_true", dest='setMemorySafetyCategory', help='Is memory safety category', default=False)

    parser.add_argument('-y', '--termination-category', action="store_true", dest='setTerminationCategory', help='Is termination category', default=False)

    parser.add_argument('-z', '--prp', metavar='name', type=str, dest='setProperty', help='path to property file (ALL.prp)', default="")

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
            originalFile = inputCFile

            rundepthk = DepthK(inputCFile)

            # Define ESBMC path
            rundepthk.esbmcpath = "./esbmc"

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
            if args.setKParallel:
                rundepthk.en_kparalell = args.setKParallel

            if args.setOverflowCheck:
                rundepthk.esbmc_overflow_check = " --overflow-check "
                
            if args.setMemorySafetyCategory:
                rundepthk.esbmc_is_memory_safety = args.setMemorySafetyCategory

            if args.setTerminationCategory:
                rundepthk.esbmc_is_termination = args.setTerminationCategory
                if rundepthk.debug_op:
                    print("Category: Termination Category!")

            if args.setProperty:
                fileDir = os.path.dirname(os.path.realpath('__file__'))
                if rundepthk.debug_op:
                    print("depthk.py path: " + fileDir)
                    print("PRP Relative Path: " + args.setProperty)
                    print("File to verification: " + inputCFile)
                rundepthk.listproperty = os.path.join(fileDir, args.setProperty)
                rundepthk.listproperty = os.path.abspath(os.path.relpath(rundepthk.listproperty))
                if rundepthk.debug_op:
                    print("PRP Absolute Path: " + rundepthk.listproperty)

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

            # useInvariants = True
            # if args.setNoInvariants:
            #     useInvariants = False
            #
            # if useInvariants:

            if args.setInvariantTool not in ["pips","pagai", "all"]:
                print("")
                print("ERROR. The invariant generation is not supported")
                print("")
                parser.parse_args(['-h'])
                sys.exit()

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


            if args.setInvariantTool == "pips" or args.setInvariantTool == "all":
                # Applying the preprocess code - Define a specific format to code
                inputCFile = rundepthk.rununcrustify(inputCFile)

                # Apply hacking to handle with GNU extensions
                # HackGNUext: Generate a copy the analyzed program to a tmp file
                # now with the extension replaced from .i to .c
                inputCFile = rundepthk.applygnuhack(inputCFile)

            #if args.setOnlyCEUse or args.setInvariantTool == "all":
            rundepthk.use_counter_example = True


            if args.setOnlyCEUse and rundepthk.debug_op:
                print(">> Adopting only the ESBMC counterexample to generate assumes")

            if(args.setInvariantTool == "all"):
                print(">> Adopting PIPS, Pagai and CounterExample to generate assumes")

            codewithinv = ""
            __invgeneration = args.setInvariantTool
            pathcodeinvtranslated = ""
            ERROR_FLAG = False
            if (not args.setOnlyCEUse or args.setInvariantTool == "all") and  (not rundepthk.esbmc_is_termination and not rundepthk.esbmc_is_memory_safety):
                try:
                    # Choose invariant generation __invgeneration
                    # Applying steps of DepthK
                    runtranspagai = translate_pagai.TranslatePagai()
                    if __invgeneration == "pagai" or __invgeneration == "all":
                        # Generate invariants
                        if rundepthk.debug_op:
                            print(">> Running PAGAI to generate the invariants")
                        geninvpagai = generate_inv_pagai.GeneratePagaiInv()
                        codewithinv = geninvpagai.generate_inv(inputCFile)

                        # Translate invariants
                        if rundepthk.debug_op:
                            print(">> Running PAGAI translation")

                        runtranspagai.pathprogram = codewithinv
                        if codewithinv:
                            if runtranspagai.identifyInv(runtranspagai.pathprogram):
                                # Program invariants were detected
                                newprogram = runtranspagai.writeInvPAGAI(runtranspagai.pathprogram, False)
                                newprogram = runtranspagai.removenotprintable(newprogram)
                                newfileinv = open(codewithinv, "w")
                                for line in newprogram:
                                    newfileinv.write(line)
                                    #print(line, end="")
                                newfileinv.close()

                                pathcodeinvtranslated = codewithinv
                                list_paths_to_delete.append(pathcodeinvtranslated)
                                inputCFile = runtranspagai.pathprogram
                            else:
                                if rundepthk.debug_op:
                                    print("ERROR. Program invariants were NOT detected with PAGAI")
                                rundepthk.cleantmpfiles(list_paths_to_delete)
                                ERROR_FLAG = True
                                #pathcodeinvtranslated = inputCFile
                                #sys.exit()
                        else:
                            ERROR_FLAG = True

                    if __invgeneration == "pips" or __invgeneration == "all":
                        # Generating pips script
                        if rundepthk.debug_op:
                            print(">> Generating PIPS script")
                        scriptpipspath = rundepthk.generatepipsscript(inputCFile)
                        list_paths_to_delete.append(scriptpipspath)

                        # Generating invariants with PIPS
                        if rundepthk.debug_op:
                            print(">> Running PIPS to generate the invariants")
                        codewithinv = rundepthk.runpips(scriptpipspath, inputCFile, list_paths_to_delete)

                        if codewithinv:
                            # rundepthk.debug_gh = True
                            if rundepthk.debug_op:
                                print(">> Applying GNU hack")
                            codewithinv = rundepthk.applygnuhack(codewithinv)

                            # Identify #init from PIPS in the code with invariants
                            if rundepthk.debug_op:
                                print(">> Running PIPS Translation")
                            dict_init = rundepthk.identify_initpips(codewithinv)
                            # Generate auxiliary code to support the translation of #init from PIPS
                            pathcodeinit = rundepthk.generatecodewithinit(codewithinv, inputCFile, dict_init)
                            # Translate the invariants generated by PIPS
                            pathcodeinvtranslated = rundepthk.translatepipsannot(pathcodeinit)
                        else:
                            print("ERROR. Program invariants with PIPS")
                            rundepthk.cleantmpfiles(list_paths_to_delete)
                            ERROR_FLAG = True

                    includespath = os.path.dirname(pathcodeinvtranslated)

                    if rundepthk.onlygeninvs_p:
                        if ERROR_FLAG:
                            if rundepthk.debug_op:
                                print("\t ERROR. Generating code with invariants")
                            # Removing tmp files
                            rundepthk.cleantmpfiles(list_paths_to_delete)
                            sys.exit()
                        else:
                            os.system("cat " + pathcodeinvtranslated)
                            # Removing tmp files
                            rundepthk.cleantmpfiles(list_paths_to_delete)
                            sys.exit()
                    else:
                        # Execute the k-induction with ESBMC
                        # Last test to validated the new code generated
                        if rundepthk.debug_op and not ERROR_FLAG:
                            print(">> ESBMC PARSING CHECKING")
                        if not ERROR_FLAG:
                            resultparse = commands.getoutput(rundepthk.esbmcpath + " -I "+ includespath + " " + rundepthk.esbmc_arch + " --show-claims " + pathcodeinvtranslated)
                            matchparseerror = re.search(r'PARSING ERROR', resultparse)
                            if matchparseerror:
                                if rundepthk.debug_op:
                                    print("\t ERROR. PARSING ERROR")
                                ERROR_FLAG = True

                        if ERROR_FLAG: # Some ERROR in invariant generation
                            rundepthk.callesbmccheck(originalFile, True, args.setForceBaseCase)
                        else:
                            rundepthk.callesbmccheck(pathcodeinvtranslated, True, args.setForceBaseCase)
                except:
                    rundepthk.callesbmccheck(originalFile, True, args.setForceBaseCase)
            else:
                # Execute the k-induction with ESBMC
                rundepthk.callesbmccheck(originalFile, True, args.setForceBaseCase)
            # Removing tmp files
            rundepthk.cleantmpfiles(list_paths_to_delete)

