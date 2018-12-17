#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


int		ft_quicksort(int *tab, int start, int end);

void	ft_puttab(int *tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		printf("%d\n", tab[i]);
		i++;
	}
}

void	ft_swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		ft_guess_pivot(int *tab, int start, int end)
{
	int		med[3];
	int		i;
	int		j;

	i = 0;
	j = -1;
	if (end - start > 10)
	{
		med[0] = tab[start];
		med[1] = tab[end - 1];
		med[2] = tab[end / 2];
		ft_quicksort(med, 0, 3);
		if (med[1] == tab[start])
			return (start);
		return ((med[1] == tab[end - 1]) ? tab[end - 1] : tab[end / 2]);
	}
	else
		return (end - 1);
}

int		ft_partition(int *tab, int start, int end)
{
	int		i;
	int		j;
	int		pivot;

	i = start - 1;
	j = start;
	pivot = end - 1;
	if (end - start == 2)
	{
		if (tab[start] > tab[end - 1])
			ft_swap(&tab[start], &tab[end - 1]);
		return (0);
	}
	while (i < end - 1 && j < end - 1)
	{
		if (tab[j] <= tab[pivot])
		{
			i++;
			ft_swap(&tab[i], &tab[j]);
		}
		j++;
	}
	ft_swap(&tab[i + 1], &tab[pivot]);
	return (i + 1);
}

int		ft_quicksort(int *tab, int start, int end)
{
	int		j;

	if (start < end - 1)
	{
		j = ft_partition(tab, start, end);
		ft_quicksort(&tab[start], 0, j);
		ft_quicksort(&tab[j + 1], 0, (end - j - 1));
	}
	return (0);
}

int		main(void)
{
	int		*tab;
	int		i;
	int		size;

	srand(time(NULL));
	i = 0;
	size = 100000;
	tab = malloc(size);
	while(i < size)
	{
		tab[i] = (rand() % (size - 1 + 1)) + 1;
		i++;
	}
	ft_quicksort(tab, 0, size);
//	ft_puttab(tab, size);
	return (0);
}
