FILE='ft_printf.c'
ASSIGN='ft_printf/ft_printf.c'
MAIN='main.c'
MAIN1='../.system/grading/main.c'

index=0

if [ -e traceback ]
then
    rm traceback
fi

cd .system/grading
gcc -Wall -Wextra -Werror  -o source $FILE $MAIN
./source | cat -e > sourcexam       #TESTING
rm source
cd ../../rendu
{
gcc -Wall -Wextra -Werror  -o final $ASSIGN $MAIN1
}  &>../.system/grading/traceback
{
./final | cat -e > finalexam        #TESTING
mv finalexam ../.system/grading/
rm final
}  &>/dev/null
cd ../.system/grading
DIFF=$(diff sourcexam finalexam)
echo "" >> traceback
if [ "$DIFF" != "" ]
then
		index=$(($index + 1))
		echo "<--------------~-~-~-~-~-~-~-~-~------------>" >> traceback
		cat sourcexam >> traceback
		echo '\n' >> traceback
		if [ -e finalexam ]
		then
		echo "<--------------~-~-~-~-~-~-~-~-~------------>\n\n" >> traceback
		echo "<--------------~-~-~-~-~-~-~-~-~------------>" >> traceback
		cat finalexam >> traceback
		else
		echo "" >> traceback
		fi
		echo '\n' >> traceback
		echo "<--------------~-~-~-~-~-~-~-~-~------------>" >> traceback
fi
rm finalexam


if [ $index -eq 0 ]
then
	touch passed
fi
{
mv traceback ../../traceback
}	&>/dev/null
rm sourcexam
