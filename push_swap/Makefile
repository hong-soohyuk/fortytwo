# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 17:43:02 by soohong           #+#    #+#              #
#    Updated: 2023/01/13 14:06:47 by soohong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc

FLAG = -Wall -Wextra -Werror

NAME = push_swap

SRCDIR = ./src

SRC = $(SRCDIR)/ps_libft/atoi.c\
      $(SRCDIR)/ps_libft/split.c\
      $(SRCDIR)/ps_greedy_sort/greedy_utils.c\
      $(SRCDIR)/ps_greedy_sort/greedy.c\
      $(SRCDIR)/ps_utils/cmds.c\
      $(SRCDIR)/ps_utils/init_dequeue.c\
	$(SRCDIR)/ps_utils/partition.c\
      $(SRCDIR)/ps_utils/sort_under_six.c\
      $(SRCDIR)/ps_utils/terminator.c\
      $(SRCDIR)/ps_rules/pushes.c\
      $(SRCDIR)/ps_rules/reverses.c\
      $(SRCDIR)/ps_rules/rotates.c\
      $(SRCDIR)/ps_rules/swaps.c\
	$(SRCDIR)/push_swap.c\

INCLUDES = -I $(SRCDIR)/includes

OBJ = $(SRC:%.c=%.o)

$(NAME) : $(OBJ)
	$(GCC) -o $(NAME) $(OBJ)

all : $(NAME)

%.o : %.c
	$(GCC) $(FLAG) -c $< -o $@ -g

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
