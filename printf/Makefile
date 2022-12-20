# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 15:58:18 by soohong           #+#    #+#              #
#    Updated: 2022/12/20 16:15:10 by soohong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc

FLAG = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ft_printf.c\
	  ft_~~.c\

OBJ = $(SRC:%.c=%.o)

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)

all : $(NAME)

%.o : %.c
	$(GCC) $(FLAG) -c $< -o $@

clean :
	re -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : libftprintf.a

