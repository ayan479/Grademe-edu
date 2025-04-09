
FILE='ft_list_size.c'
ASSIGN='ft_list_size'

bash .system/auto_correc_main.sh $FILE $ASSIGN
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

touch .system/grading/passed;
