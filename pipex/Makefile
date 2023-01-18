# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 17:53:16 by soohong           #+#    #+#              #
#    Updated: 2023/01/18 14:47:30 by soohong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc

FLAG = -Wall -Wextra -Werror

NAME = pipex

SRCDIR = ./src

SRC = $(SRCDIR)/pipex.c\

OBJ = $(SRC:%.c=%.o)

$(NAME) : $(OBJ)
	$(GCC) -o $(NAME) $(OBJ)

$(BONUS_NAME) : $(BONUS_OBJ)
	$(GCC) -o $(BONUS_NAME) $(BONUS_OBJ)

all : $(NAME)

bonus : $(BONUS_NAME)

%.o : %.c
	$(GCC) $(FLAG) -c $< -o $@ -g

clean :
	rm -f $(OBJ) $(BONUS_OBJ)

fclean : clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY : all clean fclean re
