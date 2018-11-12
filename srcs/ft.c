/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demaisonclaire <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 23:27:55 by demaisonc         #+#    #+#             */
/*   Updated: 2018/10/20 01:50:54 by demaisonc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

int		ft_atoi(char *str)
{
	int		i;
	int		nb;
	int		neg;

	i = 0;
	nb = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i]<= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10;
		nb = nb + (str[i] - '0');
		i++;
	}
	return (nb);
}

int		ft_count_neighbours(char **tab, int i, int j)
{
	int		x;
	int		y;
	int		nb;

	x = i - 1;
	y = j - 1;
	x = (x < 0) ? 0 : x;
	y = (y < 0) ? 0 : y;
	nb = 0;
	while (x <= (i + 1))
	{
		while (y <= (j + 1))
		{
			if (tab[i][j] == 'O')
			{
				if (tab[x][y] == 'O' && (x != i || y != j))
					nb++;
			}
			else 
			{
				if (tab[x][y] == 'O')
					nb++;
			}
			y++;
		}
		y = j - 1;
		x++;
	}
	return (nb);
}

int		*ft_to_do(char **tab, int size_map)
{
	int		*to_do;
	int		i;
	int		j;
	int		k;
	int		nb;

	i = 0;
	j = 0;
	k = 0;
	if (!(to_do = (int*)malloc(sizeof(int) * (size_map * size_map))))
		return (NULL);
	while (i < size_map)
	{
		while (j < size_map)
		{
			nb = ft_count_neighbours(tab, i, j);
			if (tab[i][j] == 'O')
			{
				if (nb == 2 || nb == 3)
					to_do[k] = 1;
				else if (nb < 2 ||nb > 3)
					to_do[k] = 0;	
			}
			else if (tab[i][j] == '.')
			{
				if (nb == 3)
					to_do[k] = 1;
				else
					to_do[k] = 0;
			}
			k++;
			j++;
		}
		j = 0;
		i++;
	}
	to_do[k] = -1;
	return (to_do);
}

char	**ft_modify(char **tab, int size_map)
{
	int		*to_do;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	to_do = ft_to_do(tab, size_map);
	while (to_do[k] != -1)
	{
		while (j < size_map)
		{
			if (to_do[k] == 1)
				tab[i][j] = 'O';
			else
				tab[i][j] = '.';
			j++;
			k++;
		}
		j = 0;
		i++;
	}
	free(to_do);
	return (tab);
}

