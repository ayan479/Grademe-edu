
FILE='sort_list.c'
ASSIGN='sort_list'

# Copy the file list.h from GradeMe to the student's folder thanks to @Kuninoto Issue
cp .system/grading/list.h rendu/$ASSIGN/list.h

bash .system/auto_correc_main.sh $FILE $ASSIGN
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
    # Remove the file list.h from the student's folder
    rm -f rendu/$ASSIGN/list.h
	exit 1
fi

# Remove the file list.h from the student's folder
rm -f rendu/$ASSIGN/list.h

touch .system/grading/passed;
