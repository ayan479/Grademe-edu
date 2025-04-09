#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd);

int main(void)
{
	char	*line;

	while ((line = get_next_line(0)) != NULL)
	{
		printf("%s", line);
		free(line);
		line = NULL;
	}
	printf("%s", line);
	free(line);
	system("leaks stud > studleak 2>&1");
	return(0);
}
