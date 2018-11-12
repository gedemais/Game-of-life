/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demaisonclaire <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 22:54:49 by demaisonc         #+#    #+#             */
/*   Updated: 2018/11/11 12:00:00 by demaisonc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putstr("-2");
		nb = 147483648;
	}
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar('-');
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void	ft_print_table(char **tab)
{
	int		i;

	i = 0;
	while (tab[i][0] != -1)
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}
