# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 17:43:02 by soohong           #+#    #+#              #
#    Updated: 2023/01/13 16:39:33 by soohong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc

FLAG = -Wall -Wextra -Werror

NAME = push_swap

BONUS_NAME = checker

SRCDIR = ./src

BONUS_DIR = ./ps_checker

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

BONUS_SRC = $(BONUS_DIR)/checker_rules/pushes.c\
      $(BONUS_DIR)/checker_rules/reverses.c\
      $(BONUS_DIR)/checker_rules/rotates.c\
      $(BONUS_DIR)/checker_rules/swaps.c\
      $(BONUS_DIR)/ps_libft/atoi.c\
      $(BONUS_DIR)/ps_libft/get_next_line.c\
      $(BONUS_DIR)/ps_libft/get_next_line_utils.c\
      $(BONUS_DIR)/ps_libft/ps_strcmp.c\
      $(BONUS_DIR)/ps_libft/split.c\
      $(BONUS_DIR)/checker.c\
      $(BONUS_DIR)/init_dequeue.c\
      $(BONUS_DIR)/terminator.c\

OBJ = $(SRC:%.c=%.o)

BONUS_OBJ = $(BONUS_SRC:%.c=%.o)

$(NAME) : $(OBJ)
	$(GCC) -o $(NAME) $(OBJ)

$(BONUS_NAME) : $(BONUS_OBJ)
	$(GCC) -o $(BONUS_INCLUDES) $(BONUS_NAME) $(BONUS_OBJ)

all : $(NAME)

bonus : $(BONUS_NAME)

%.o : %.c
	$(GCC) $(FLAG) $(INCLUDES) -c $< -o $@ -g

clean :
	rm -f $(OBJ) $(BONUS_OBJ)

fclean : clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY : all clean fclean re
