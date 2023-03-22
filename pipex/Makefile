# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 17:53:16 by soohong           #+#    #+#              #
#    Updated: 2023/03/22 19:58:45 by soohong          ###   ########.fr        #
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

FLAG = -Wall -Wextra -Werror

LIBFT = libft

GET_NEXT_LINE = get_next_line

NAME = pipex

BONUS = pipex_bonus

HEADER = includes

SRCDIR = ./srcs
OBJDIR = ./objects

SOURCES = pipex.c \
pipex_utils.c \

BONUS_SOURCES = pipex_bonus.c \
pipex_utils_bonus.c \

SRCS = $(addprefix $(SRCDIR)/,$(SOURCES))
OBJS = $(addprefix $(OBJDIR)/,$(SOURCES:%.c=%.o))

BONUS_SRCS = $(addprefix $(SRCDIR)/,$(BONUS_SOURCES))
BONUS_OBJS = $(addprefix $(OBJDIR)/,$(BONUS_SOURCES:%.c=%.o))

LFT = -L libft -lft
GNL = -L get_next_line -lgnl

all : libraries makedir $(NAME)

bonus : bonus_libraries makedir $(BONUS)

$(NAME) : $(OBJS)
	@$(GCC) -o $(NAME) $(OBJS) $(LFT)
	@echo "$(BLUE)Linking object files -> $(WHITE)$(notdir $@)... $(RED)[Done]$(NOC)"

$(BONUS) : $(BONUS_OBJS)
	@$(GCC) -o $(BONUS) $(BONUS_OBJS) $(LFT) $(GNL)
	@echo "$(BLUE)Linking object files -> $(WHITE)$(notdir $@)... $(RED)[Done]$(NOC)"

libraries :
	@echo "$(GREEN)Creating lib files$(CYAN)"
	@make -C $(LIBFT)

bonus_libraries :
	@echo "$(GREEN)Creating lib files$(CYAN)"
	@make -C $(LIBFT)
	@make -C $(GET_NEXT_LINE)

makedir:
	@mkdir -p objects

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(HEADER)/$(NAME).h
	@$(GCC) $(FLAG) -c $< -o $@
	@echo "$(BLUE)Compiling object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(NOC)"

clean:
	@echo "$(GREEN)Supressing libraries files$(CYAN)"
	@make clean -C $(LIBFT)
	@make clean -C $(GET_NEXT_LINE)
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(GREEN)Supressing libraries files$(CYAN)"
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)
	@rm -f $(BONUS)
	@make fclean -C $(LIBFT)
	@make fclean -C $(GET_NEXT_LINE)

re: fclean all

.PHONY : all clean fclean re
