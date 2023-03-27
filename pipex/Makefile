# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 17:53:16 by soohong           #+#    #+#              #
#    Updated: 2023/03/23 14:20:52 by soohong          ###   ########.fr        #
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

HEADER = includes

SRCDIR = ./srcs
OBJDIR = ./objects

SOURCES_M = pipex.c \
pipex_utils.c \

SOURCES_B = pipex_bonus.c \
pipex_utils_bonus.c \

SRCS_M = $(addprefix $(SRCDIR)/,$(SOURCES_M))
OBJS_M = $(addprefix $(OBJDIR)/,$(SOURCES_M:%.c=%.o))

SRCS_B = $(addprefix $(SRCDIR)/,$(SOURCES_B))
OBJS_B = $(addprefix $(OBJDIR)/,$(SOURCES_B:%.c=%.o))

LFT = -L libft -lft
GNL = -L get_next_line -lgnl

all : libraries makedir $(NAME)

$(NAME) : $(OBJS_M)
	@$(GCC) -o $(NAME) $(OBJS_M) $(LFT) $(GNL)
	@echo "$(BLUE)Linking object files -> $(WHITE)$(notdir $@)[Done]$(NOC)"

bonus : libraries makedir $(OBJS_B)
	@$(GCC) -o $(NAME) $(OBJS_B) $(LFT) $(GNL)
	@echo "$(BLUE)Linking object files -> $(WHITE)$(notdir $@)[Done]$(NOC)"

libraries :
	@echo "$(GREEN)Creating lib files$(CYAN)"
	@make -C $(GET_NEXT_LINE)
	@make -C $(LIBFT)

makedir:
	@mkdir -p objects

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(HEADER)/$(NAME).h
	@$(GCC) $(FLAG) -c $< -o $@
	@echo "$(BLUE)Compiling object file -> $(WHITE)$(notdir $@)[Done]$(NOC)"

clean:
	@echo "$(GREEN)Remove objects files and libraries.$(CYAN)"
	@rm -rf $(OBJDIR)
	@make clean -C $(LIBFT)
	@make clean -C $(GET_NEXT_LINE)

fclean: clean
	@echo "$(GREEN)Remove exec file.$(CYAN)"
	@make fclean -C $(LIBFT)
	@make fclean -C $(GET_NEXT_LINE)
	@rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
