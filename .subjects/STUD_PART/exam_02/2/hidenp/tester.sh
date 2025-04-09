
FILE='hidenp.c'
ASSIGN='hidenp'

bash .system/auto_correc_program.sh $FILE $ASSIGN 
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN  "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN "abc" "2altrb53c.sse"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN "abc" "btarc"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN "mais non!" "mais non!"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi


touch .system/grading/passed;
