FILE='ft_strcpy.c'
ASSIGN='ft_strcpy'

bash .system/auto_correc_main.sh $FILE $ASSIGN "Ceci permet de decouvrir le fonctionnement de ton ft_strcpy."
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_main.sh $FILE $ASSIGN "OH ! Tu devrais avoir reussi ce test."
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

touch .system/grading/passed;
