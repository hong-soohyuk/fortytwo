# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 15:58:18 by soohong           #+#    #+#              #
#    Updated: 2022/12/23 19:51:33 by soohong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc

FLAG = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ft_printf.c\
      ft_printf_utils.c\
      ft_putnbr_base.c

OBJ = $(SRC:%.c=%.o)

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)

all : $(NAME)

%.o : %.c
	$(GCC) $(FLAG) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
