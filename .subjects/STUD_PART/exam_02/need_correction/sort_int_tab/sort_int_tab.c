// Passed Moulinette 2019.09.01

void	swap_values(int *a, int *b)
{
	int swap = *a;
	*a = *b;
	*b = swap;
}

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;
	int swapped = 1;

	while (swapped == 1)
	{
		i = 1;
		swapped = 0;
		while (i < size)
		{
			if (tab[i - 1] > tab[i])
			{
				swap_values(&tab[i - 1], &tab[i]);
				swapped = 1;
			}
			++i;
		}
	}
}
