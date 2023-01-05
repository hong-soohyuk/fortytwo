# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 17:43:02 by soohong           #+#    #+#              #
#    Updated: 2023/01/03 17:47:50 by soohong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc

FLAG = -Wall -Wextra -Werror

NAME = push_swap

SRC = ps_atoi.c\
      ps_split.c\
	  ps_putstr.c\
	  push_swap.c\
      ps_initializer.c\
      ps_terminator.c\

OBJ = $(SRC:%.c=%.o)

$(NAME) : $(OBJ)
	$(GCC) -o $(NAME) $(OBJ)

all : $(NAME)

%.o : %.c
	$(GCC) $(FLAG) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
