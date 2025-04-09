
FILE='max.c'
ASSIGN='max'

bash .system/auto_correc_main.sh $FILE $ASSIGN "7" "-42" "0" "-5" "-64" "-2" "-68" "-1"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_main.sh $FILE $ASSIGN "6" "-42" "0" "-5" "-64" "-2" "-68"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_main.sh $FILE $ASSIGN "4" "7" "42" "0" "-5"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

touch .system/grading/passed;
