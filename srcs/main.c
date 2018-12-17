/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demaisonclaire <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 22:41:19 by demaisonc         #+#    #+#             */
/*   Updated: 2018/11/18 19:08:42 by demaisonc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

char	**ft_set_table(int size_map)
{
	char 	**tab;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (size_map + 1))))
		return (NULL);
	while (++i <= size_map)
		if (!(tab[i] = (char*)malloc(sizeof(char) * (size_map + 1))))
			return (NULL);
	i = 0;
	while (i < size_map)
	{
		while (j <= size_map)
		{
			tab[i][j] = '.';
			j++;
		}
		tab[i][j] = '\0';
		j = 0;
		i++;
	}
	tab[i][0] = -1;
	return (tab);
}

char	**ft_aleatab(char **tab, int fill, int size_map)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	srand(time(NULL));
	while (k < fill)
	{
		i = (rand() % (size_map - 0 + 1)) + 0;
		j = (rand() % (size_map - 0 + 1)) + 0;
		tab[i][j] = 'O';
		k++;
	}
	return (tab);
}

void	ft_jdlv(char **argv)
{
	char	**tab;
	int		i;
	int		nb_cycles;
	struct	timespec tim, tim2;

	i = 0;
	nb_cycles = ft_atoi(argv[5]);
	tim.tv_sec = ft_atoi(argv[3]);
	tim.tv_nsec = ft_atoi(argv[4]) * 1000000;
	tab = ft_set_table(ft_atoi(argv[1]));
	tab = ft_aleatab(tab, ft_atoi(argv[2]), ft_atoi(argv[1]));
	while (i <= nb_cycles)
	{
		ft_print_table(tab);
		ft_putstr("Cycle :");
		ft_putnbr(i);
		ft_putchar('\n');
		tab = ft_modify(tab, ft_atoi(argv[1]));
		nanosleep(&tim, &tim2);
		i++;
	}
	free(tab);
}

int		main(int argc, char **argv)
{
	if (argc == 6)
		ft_jdlv(argv);
	while(1);
	return (0);
}
