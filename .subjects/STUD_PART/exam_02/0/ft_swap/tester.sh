FILE='ft_swap.c'
ASSIGN='ft_swap'

bash .system/auto_correc_main.sh $FILE $ASSIGN
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi


touch .system/grading/passed;
