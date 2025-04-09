FILE='rev_wstr.c'
ASSIGN='rev_wstr'

bash .system/auto_correc_program.sh $FILE $ASSIGN "order in us put"
if [ -e ./.system/grading/traceback ];then
	mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN "done! well it, did You"
if [ -e ./.system/grading/traceback ];then
	mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN "You hate people! But I love gatherings. Isn't it ironic?"
if [ -e ./.system/grading/traceback ];then
	mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN "abcdefghijklm"
if [ -e ./.system/grading/traceback ];then
	mv .system/grading/traceback .
	exit 1
fi

touch .system/grading/passed;
