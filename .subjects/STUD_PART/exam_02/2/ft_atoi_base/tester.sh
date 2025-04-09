FILE='ft_atoi_base.c'
ASSIGN='ft_atoi_base'

bash .system/auto_correc_main.sh $FILE $ASSIGN "Ceci permet de decouvrir le fonctionnement de ton ft_atoi_base." "16"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_main.sh $FILE $ASSIGN "13268!" "16"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_main.sh $FILE $ASSIGN "-13268!" "10"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

touch .system/grading/passed;
