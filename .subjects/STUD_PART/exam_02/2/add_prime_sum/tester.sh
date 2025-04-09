FILE='add_prime_sum.c'
ASSIGN='add_prime_sum'

bash .system/auto_correc_program.sh $FILE $ASSIGN 
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN "5"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN "Too" "Many" "Arguments"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN "7"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

touch .system/grading/passed;
