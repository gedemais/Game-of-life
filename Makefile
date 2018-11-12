#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: demaisonclaire <marvin@42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/29 18:53:24 by demaisonc         #+#    #+#              #
#    Updated: 2018/10/20 01:12:35 by demaisonc        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GWW = @gcc -Wall -Werror -Wextra

HH = include/main.h

CC = srcs/main.c srcs/ft.c srcs/ft_print.c

OO = main.o ft.o ft_print.o

all :
	@make jdlv

jdlv : $(OO) 
	$(GWW) -o jdlv $(OO)

$(OO) : $(CC)
	$(GWW) -c $(CC)

clean : 
	@rm -rf $(OO)

fclean : clean
	@rm -rf jdlv

re : fclean all
