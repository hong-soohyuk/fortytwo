# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 17:53:16 by soohong           #+#    #+#              #
#    Updated: 2023/03/03 14:33:37 by soohong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

GCC = gcc

# FLAG = -Wall -Wextra -Werror
FLAG = -w

LIBFT = libft

NAME = pipex

HEADER = includes

SRCDIR = ./srcs
OBJDIR = ./objects

SOURCES = pipex.c \
pipex_utils.c \

SRCS = $(addprefix $(SRCDIR)/,$(SOURCES))
OBJS = $(addprefix $(OBJDIR)/,$(SOURCES:%.c=%.o))

LFT = -L libft -lft

all : libraries makedir $(NAME)

$(NAME) : $(OBJS)
	$(GCC) -o $(NAME) $(OBJS) $(LFT)

$(BONUS_NAME) : $(BONUS_OBJ)
	$(GCC) -o $(BONUS_NAME) $(BONUS_OBJ)

libraries :
	@echo "$(GREEN)Creating lib files$(CYAN)"
	@make -C $(LIBFT)

makedir:
	@mkdir -p objects

bonus : $(BONUS_NAME)

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(HEADER)/$(NAME).h
	$(GCC) $(FLAG) -c $< -o $@
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(NOC)"

clean:
	@echo "$(GREEN)Supressing libraries files$(CYAN)"
	@make clean -C $(LIBFT)
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(GREEN)Supressing libraries files$(CYAN)"
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY : all clean fclean re
