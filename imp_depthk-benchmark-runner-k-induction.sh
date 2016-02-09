#!/bin/bash
#
# ESBMC - Benchmark Runner (Single-Core)
#
#               Universidade Federal do Amazonas - UFAM
# Author:       Hussama Ismail <hussamaismail@gmail.com>
#
# ------------------------------------------------------
#
# Script that generate a benchmark report using competition style.
# 
# Usage Example:
# $ sh script folder/testcase
#
# ------------------------------------------------------
#
# History:
#
#  v0.1 2014-04-14, Hussama Ismail: 
#     - Initial Version
#  v0.2 2014-04-25, Hussama Ismail:
#     - Adding Requirements 
#  v0.3 2014-04-29, Hussama Ismail:
#     - Adjust html to order by columns
#  v0.3-k-induction, Hussama Ismail:
#     - Adding k-induction requirements
#  v0.4-k-induction 2015-01-05, Hussama Ismail:
#     - Modification to check .i instead of
#       .c files (when exists)
#

# DEPENDENCY PARAMETERS
ESBMC_WRAPPER_SCRIPT='depthk.py -s boolector -e="--error-label ERROR" /opt/iCAV/categories/BitVectors/bitvector/gcd_1_true-unreach-call.i ';
OUTPUT_REPORT_FILE="report.html";
SCRIPT_VERSION="0.4-k-induction";

# CHECK PARAMETERS
if [ ${#@} -eq 0 ]; then
    echo "Is necessary specify a benchmark or a folder. (use: $0 benchmarks)";
    exit 0;
fi

SOURCES="";
for current_source in "$@"; do
    FILES_I=$(find $current_source  -type f \( -iname "*.i" \));
    FILES_C=$(find $current_source -type f \( -iname "*.c" \))
    SOURCES=$(echo $SOURCES $FILES_I);  
    for c_file in ${FILES_C[@]}; do
	# check if exist a same .i file
        c_filename_lenght=${#c_file};
	c_filename_without_extension=${c_file:0:$((c_filename_lenght - 2))};	       
       	already_exists_i_file=$(echo ${FILES_I[@]} | grep -i ${c_filename_without_extension} | wc -l);	
	if [ $already_exists_i_file -eq 0 ]; then
	   SOURCES=$(echo $SOURCES $c_file);
        fi
    done
done

QTD_I_FILES=$(echo $SOURCES | grep -o "\.i$" | wc -l);
QTD_C_FILES=$(echo $SOURCES | grep -o "\.c$" | wc -l);
QTD_FILES=$((QTD_I_FILES + QTD_C_FILES));
if [ $QTD_FILES -eq 1 ]; then
   IS_SINGLE_FILE=1;
else 
   IS_SINGLE_FILE=0;
fi

# ESBMC PARAMS
#ESBMC_EXECUTABLE=$(cat $ESBMC_WRAPPER_SCRIPT | grep "path_to_esbmc" | head -n1 | cut -d"=" -f2)
ESBMC_VERSION="DepthK"
#ESBMC_PARAMS=$(cat $ESBMC_WRAPPER_SCRIPT | grep global_cmd_line | head -n1 | cut -d '"' -f2)
ESBMC_PARAMS=" --debug --disable-counter-example --solver z3 --memlimit 15g --extra-option-esbmc=\"--error-label ERROR\""

# SYSTEM INFO
DATE_EXECUTION=$(date)
INITIAL_TIMESTAMP=$(date +%s)
CPU_CORE_NUMBER=$(cat /proc/cpuinfo | grep processor | wc -l)
CPU_INFO="CPU:$(cat /proc/cpuinfo | grep "model name" | tail -n1 | cut -d ":" -f2)"
MEM_INFO="RAM: $(cat /proc/meminfo | grep "MemTotal" | cut -d ":" -f2 | cut -d " " -f8) kB"

# HTML CONTENT
HTML_TABLE_HEADER="<table style=\"width: 100%\"><thead><tr id=\"tool\"><td style=\"width: 60%\">Tool</td><td colspan=\"2\">$ESBMC_VERSION</td></tr><tr id=\"limits\"><td>Limits</td><td colspan=\"2\"></td></tr><tr id=\"system\"><td>System</td><td colspan=\"2\">$CPU_INFO - $MEM_INFO</td></tr><tr id=\"date\"><td>Date of run</td><td colspan=\"2\">$DATE_EXECUTION</td></tr><tr id=\"options\"><td>Options</td><td colspan=\"2\">$ESBMC_PARAMS</td></tr></thead></table><table id=\"datatable\" class=\"tablesorter\" style=\"width: 100%; margin-top: 3px\"><thead><tr id=\"columnTitles\"><th style=\"width: 60%; text-align: left\" class=\"clickable\"><span style=\"font-size: x-small; font-weight: normal; text-align: left;\">$(echo $@ | sed -e "s/ /<br>/g")</span></th><th style=\"width: 20%\" colspan=\"1\" class=\"clickable\">status</th><th colspan=\"1\" class=\"clickable\">time(s)</th><th style=\"display: none\">is Failed?</th></tr></thead><tbody>"

# REPORT CONTROL
TOTAL_FILES=0
CORRECT_RESULTS=0
CORRECT_TRUES=0
CORRECT_FALSES=0
FALSE_POSITIVES=0
FALSE_NEGATIVES=0
MAX_SCORE=0
TOTAL_POINTS=0
TOTAL_ERRORS=0

FAILED_USING_BASE_CASE=0
SUCCESS_USING_FORWARD_CONDITION=0
SUCCESS_USING_INDUCTIVE_STEP=0
TOTAL_UNKNOWN=0;

#cp ./REPORT/header.html $OUTPUT_REPORT_FILE
echo $HTML_TABLE_HEADER >> $OUTPUT_REPORT_FILE

echo "*** ESBMC Benchmark Runner (Single-Core) v$SCRIPT_VERSION ***"
echo ""
echo "Tool: $ESBMC_VERSION"
echo "Date of run: $(date)"
echo "System: $CPU_INFO $MEM_INFO"
echo "Options: $ESBMC_PARAMS"
echo "Source: $@ "
echo "";

for file in $SOURCES; do
   TOTAL_FILES=$((TOTAL_FILES + 1));
   FILENAME=$file

   if [ $IS_SINGLE_FILE -eq 0 ]; then
      FILENAME=$(echo $file);
      for current_source in "$@" ; do
         ACC=$(echo $current_source | grep -o "\<c\>" | wc -l);
         ACI=$(echo $current_source | grep -o "\<i\>" | wc -l);
         AC=$((ACC+ACI));
         if [ $AC -ge 1 ]; then
            continue;
         fi
         TEMP=$(echo $file | sed -e "s:$current_source::")       
  	 if [ $(expr length $TEMP) -lt $(expr length $FILENAME) ]; then 
            FILENAME=$(echo $TEMP);
         fi
      done
   fi
  
   echo "RUNNING: " $FILENAME
   
   EXPECTED_FAILED_RESULT=$(echo $file | egrep -i "unsafe|false-unreach" | wc -l);  
   if [ $EXPECTED_FAILED_RESULT -eq 1 ]; then
      MAX_SCORE=$((MAX_SCORE + 1));
   else
      MAX_SCORE=$((MAX_SCORE + 2));
   fi   

   INITIAL_EXECUTION_TIMESTAMP=$(date +%s)
   OUT=$(timeout --signal=9 16m python depthk.py --debug --disable-counter-example --solver z3 --memlimit 15g --extra-option-esbmc="--error-label ERROR" $file 2> /tmp/dephtk-error)
   FINAL_EXECUTION_TIMESTAMP=$(date +%s)

   ERROR=$(echo "$OUT" | grep "ERROR" | wc -l); 
   PARSE_ERROR=$(cat /tmp/dephtk-error | wc -l);
   FAILED=$(echo $OUT | grep "FALSE" | wc -l); 
   SUCCESS=$(echo $OUT | grep "TRUE" | wc -l);  
   UNKNOWN=$(echo $OUT | grep "UNKNOWN" | wc -l);  
   TIME_OUT=$(echo $OUT | grep "TIMEOUT" | wc -l);  
   TIME_OUT=$(echo $OUT | grep "Killed" | wc -l);  
   INCORRECT_RESULT=0;  
   TIME=$((FINAL_EXECUTION_TIMESTAMP - INITIAL_EXECUTION_TIMESTAMP));
 
   CSS_CLASS="";
   RESULT_TEXT=""; 


   if ([ $ERROR -gt 0 ] || [ $PARSE_ERROR -gt 0 ]); then
      CSS_CLASS="status error";
      RESULT_TEXT="ERROR";
      INCORRECT_RESULT=1
      TOTAL_ERRORS=$((TOTAL_ERRORS + 1))
      echo $(echo -e "\033[1;35mERROR\033[0m" | cut -d " " -f2) "in $TIME""s";
   elif [ $TIME_OUT -eq 1 ] || ([ $FAILED -eq 0 ] && [ $SUCCESS -eq 0 ] && [ $UNKNOWN -eq 0 ]); then
      CSS_CLASS="status error";
      RESULT_TEXT="timeout"; 
      INCORRECT_RESULT=1
      echo $(echo -e "\033[1;35mtimeout\033[0m" | cut -d " " -f2) "in $TIME""s";
   elif [ $UNKNOWN -eq 1 ] || ([ $FAILED -eq 0 ] && [ $SUCCESS -eq 0 ] && [ $TIME_OUT -eq 0 ]); then
      CSS_CLASS="status unknown";
      RESULT_TEXT="unknown"; 
      echo $(echo -e "\033[0;33munknown\033[0m" | cut -d " " -f2) "in $TIME""s";
      INCORRECT_RESULT=1;
      TOTAL_UNKNOWN=$((TOTAL_UNKNOWN + 1));
   elif [ $EXPECTED_FAILED_RESULT -eq 1 ] && [ $FAILED -eq 1 ]; then
      CSS_CLASS="correctProperty";
      RESULT_TEXT="false(label)";
      CORRECT_RESULTS=$((CORRECT_RESULTS + 1));
      CORRECT_FALSES=$((CORRECT_FALSES + 1));

      if [ $(echo $OUT | grep -o "base case" | wc -l) -eq 1 ]; then
         FAILED_USING_BASE_CASE=$((FAILED_USING_BASE_CASE + 1)); 	
      fi

      echo $(echo -e "\033[0;32mfalse(label)\033[0m" | cut -d " " -f2) "in $TIME""s";
   elif [ $EXPECTED_FAILED_RESULT -eq 1 ] && [ $FAILED -eq 0 ]; then
      CSS_CLASS="wrongProperty";
      RESULT_TEXT="true";
      FALSE_POSITIVES=$((FALSE_POSITIVES + 1));
      echo $(echo -e "\033[0;31mtrue\033[0m" | cut -d " " -f2) "in $TIME""s";
      INCORRECT_RESULT=1;
   elif [ $EXPECTED_FAILED_RESULT -eq 0 ] && [ $FAILED -eq 1 ]; then
      CSS_CLASS="wrongProperty";
      RESULT_TEXT="false(label)";
      FALSE_NEGATIVES=$((FALSE_NEGATIVES + 1));
      echo $(echo -e "\033[0;31mfalse(label)\033[0m" | cut -d " " -f2) "in $TIME""s";
      INCORRECT_RESULT=1;
   elif [ $EXPECTED_FAILED_RESULT -eq 0 ] && [ $FAILED -eq 0 ]; then
      CSS_CLASS="correctProperty";
      RESULT_TEXT="true";
      CORRECT_RESULTS=$((CORRECT_RESULTS + 1));
      CORRECT_TRUES=$((CORRECT_TRUES + 1 ));

      METHOD=$(echo "$OUT" | tail -n 5 | head -n 1);
      if [ $(echo $OUT | grep -o "forward condition" | wc -l) -eq 1 ]; then
         SUCCESS_USING_FORWARD_CONDITION=$((SUCCESS_USING_FORWARD_CONDITION + 1));
      elif [ $(echo "$OUT" | grep -o "inductive step" | wc -l) -eq 1 ]; then
         SUCCESS_USING_INDUCTIVE_STEP=$((SUCCESS_USING_INDUCTIVE_STEP + 1));
      fi

      echo $(echo -e "\033[0;32mtrue\033[0m" | cut -d " " -f2) "in $TIME""s" "using$METHOD";
   fi

   HTML_ENTRY="<tr><td>$FILENAME</td><td class=\"$CSS_CLASS\">$RESULT_TEXT</td><td class=\"unknownValue\">$TIME&nbsp;</td><td style=\"display: none\">$INCORRECT_RESULT</td></tr>"
   echo $HTML_ENTRY >> $OUTPUT_REPORT_FILE
done
FINAL_TIMESTAMP=$(date +%s)

# CALCULATE POINTS
TOTAL_POINTS=$((TOTAL_POINTS + 2 * CORRECT_TRUES));
TOTAL_POINTS=$((TOTAL_POINTS + CORRECT_FALSES));
TOTAL_POINTS=$((TOTAL_POINTS - 8 * FALSE_POSITIVES));
TOTAL_POINTS=$((TOTAL_POINTS - 4 * FALSE_NEGATIVES));
TOTAL_EXECUTION_TIME=$((FINAL_TIMESTAMP - INITIAL_TIMESTAMP));

# HTML CONTENT
HTML_TABLE_FOOTER="</tbody></table><table style=\"width: 100%; margin-top: 2px\"><tfoot><tr><td style=\"width: 60%\">total files</td><td>$TOTAL_FILES</td><td class=\"unknownValue\" style=\"width: 20%\">$TOTAL_EXECUTION_TIME&nbsp;</td></tr><tr><td title=\"(no bug exists + result is SAFE) OR (bug exists + result is UNSAFE) OR (property is violated + violation is found)\">correct results</td><td>$CORRECT_RESULTS</td><td>-</td></tr><tr><td title=\"bug exists + result is SAFE\">false negatives</td><td>$FALSE_NEGATIVES</td><td>-</td></tr><tr><td title=\"no bug exists + result is UNSAFE\">false positives</td><td>$FALSE_POSITIVES</td><td>-</td></tr><tr><td title=\"bug exists + result is SAFE\">total fails using base case</td><td>$FAILED_USING_BASE_CASE</td><td>-</td></tr> <tr><td title=\"bug exists + result is SAFE\">success using forward condition</td><td>$SUCCESS_USING_FORWARD_CONDITION</td><td>-</td></tr> <tr><td title=\"bug exists + result is SAFE\">success using inductive step</td><td>$SUCCESS_USING_INDUCTIVE_STEP</td><td>-</td></tr> <tr><td title=\"bug exists + result is SAFE\">total unknown</td><td>$TOTAL_UNKNOWN</td><td>-</td></tr> <tr><td title=\"bug exists + result is SAFE\">total errors</td><td>$TOTAL_ERRORS</td><td>-</td></tr> <tr><td title=\"17 safe files, 15 unsafe files\">score ($TOTAL_FILES files, max score: $MAX_SCORE)</td><td class=\"score\">$TOTAL_POINTS</td><td class=\"score\"></td></tr></tfoot></table></center><br><a href=\"#\" onclick=\"javascript:orderByCorrectIncorrectResults()\">order by correct / incorrect results</a></body></html>"

echo "";
echo "*** RESULTS *** ";
echo "Total Files: $TOTAL_FILES in $TOTAL_EXECUTION_TIME""s";
echo "Correct Results: $CORRECT_RESULTS";
echo "False Negatives: $FALSE_NEGATIVES";
echo "False Positives: $FALSE_POSITIVES";

echo "";
echo "Total Fails Using Base Case: $FAILED_USING_BASE_CASE";
echo "Total Unknown: $TOTAL_UNKNOWN";
echo "Total Success Using Forward Condition: $SUCCESS_USING_FORWARD_CONDITION";
echo "Total Success Using Inductive Step: $SUCCESS_USING_INDUCTIVE_STEP";
echo "Total Errors: $TOTAL_ERRORS";

echo "";
echo "Score ($TOTAL_FILES files, max score: $MAX_SCORE): $TOTAL_POINTS";

echo $HTML_TABLE_FOOTER >> $OUTPUT_REPORT_FILE
echo "Report file generated: $OUTPUT_REPORT_FILE";