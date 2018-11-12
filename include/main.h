/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demaisonclaire <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 22:42:56 by demaisonc         #+#    #+#             */
/*   Updated: 2018/11/11 11:56:39 by demaisonc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <time.h>

void	ft_print(int **tab);

char	**ft_set_table(int size_map);
void	ft_jdlv(char **argv);
char	**ft_aleatab(char **tab, int fill, int size_map);

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_print_table(char **tab);

int		ft_atoi(char *str);
char	**ft_modify(char **tab, int size_map);
int		*ft_to_do(char **tab, int size_map);
int		ft_count_neighbours(char **tab, int i, int j);

#endif
