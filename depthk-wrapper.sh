#!/bin/bash

# ------------- DepthK wrapper script to tests
# Usage: ./wrapper_script_tests.sh <file.c|file.i>

# Path to the DepthK tool
path_to_depthk="./depthk.py"


while getopts "c:mh" arg; do
    case $arg in
        h)
            echo "Usage: $0 [options] path_to_benchmark
Options:
-h             Print this message
-c propfile    Specifythe given property file"
            ;;
        c)
            # Given the lack of variation in the property file... we don't
            # actually interpret it. Instead we have the same options to all
            # tests.
            ;;
    esac
done


# Command line, common to all tests.
depthk_options="--debug --disable-counter-example --solver z3 --memlimit 15g --extra-option-esbmc=\"--error-label ERROR\""
#depthk_options="--debug --disable-counter-example --solver boolector  --memlimit 15g --extra-option-esbmc=\"--error-label ERROR\""


# Store the path to the file we're going to be checking.
benchmark=$1
# Store the path to the file to write the witness if the sourcefile
# contains a bug and the tool returns False (Error found)
witnesspath=$2

if test "${benchmark}" = ""; then
    echo "No benchmark given" >&2
    exit 1
fi


# Creating Dir to save the logs
#LOGS_depthk="LOGS_depthk"
#if [ ! -d "$LOGS_depthk" ]; then
#    mkdir "$LOGS_depthk"
#fi


# The complete command to be executed
run_cmdline="${path_to_depthk} ${depthk_options} \"${benchmark}\";"

# Invoke our command, wrapped in a timeout so that we can
# postprocess the results. `timeout` is part of coreutils on debian and fedora.
result_check=`timeout 895 bash -c "$run_cmdline"`

# Saving logs
echo "$result_check" &> "${benchmark}"".log"
# mv "${benchmark}"".log" "$LOGS_depthk"
# Getting K adopted by ESBMC
bound="-"
bond_check1=`tac  "${benchmark}"".log" | grep -o "^\*\*\* K-Induction Loop Iteration.*" | grep -o "[0-9]*[^ ]*" -m 1`
bond_check2=`tac  "${benchmark}"".log" | grep -o "^Unwinding loop.*" | grep -o "iteration[ ]*[0-9]*[^ ]*" | grep -o "[0-9]*$" -m 1`
if [ ! -z "$bond_check1" ]; then
   bound=$bond_check1
fi

if [ ! -z "$bond_check2" ]; then
   bound=$bond_check2
fi

rm "${benchmark}"".log"

echo "Bound k:$bound"


# Identify problems with invariants generation
# Not supported by PIPS
PIPSerror=`echo ${result_check} | grep -c "A problem was identified in PIPS"`
# When it is not possible generate the invariants
invTO=`echo ${result_check} | grep -c "TIMEOUT to generate the invariants"`

# Checking approach to force last check with base case
forcelastcheckbc=`echo ${result_check} | grep -c "> Forcing last check in base case"`


# Postprocessing: first, collect some facts
failed=`echo ${result_check} | grep -c "VERIFICATION FAILED"`
success=`echo ${result_check} | grep -c "TRUE"`

# Decide which result we determined here.
if [ $failed -gt 0 ]; then
    # Error path found
    echo "FAILED"
elif [ $success -gt 0 ]; then
    echo "TRUE"
else
    echo "UNKNOWN"

fi

# Print log about invariants generation
#if [ $PIPSerror -gt 0 ]; then
    #echo "[PIPS] A problem was identified"
#fi

#if [ $invTO -gt 0 ]; then
    #echo "[PIPS] TIMEOUT to generate the invariants"
#fi

#if [ $forcelastcheckbc -gt 0 ]; then
    #echo "[DEPTHK] Forcing last check in base case"
#fi