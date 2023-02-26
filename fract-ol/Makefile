# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 17:43:02 by soohong           #+#    #+#              #
#    Updated: 2023/02/26 12:59:18 by soohong          ###   ########.fr        #
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

CC = cc
FLAG = -Wall -Wextra -Werror -g
# FLAG = -w

NAME = fractol

MLX = libmlx
LIBFT  = libft
HEADER = includes
SRCDIR  = ./srcs
OBJDIR  = ./objects

LMLX =  -Llibmlx -lmlx -framework OpenGl -framework Appkit
LFT = -L libft -lft

SOURCES = main.c \
fractals.c \
drawer.c \
color.c \
mouse_hooks.c \
key_hooks.c \

SRCS = $(addprefix $(SRCDIR)/,$(SOURCES))
OBJS = $(addprefix $(OBJDIR)/,$(SOURCES:%.c=%.o))

all: libraries makedir $(NAME)

libraries:
	@echo "$(GREEN)Creating lib files$(CYAN)"
	@make -C $(LIBFT)
	@make -C $(MLX)

makedir:
	@mkdir -p objects

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LMLX) $(LFT)
	@echo "$(GREEN)Project successfully compiled"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER)/$(NAME).h
	@$(CC) $(FLAG) -c $< -o $@
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(NOC)"

clean:
	@echo "$(GREEN)Supressing libraries files$(CYAN)"
	@make clean -C $(LIBFT)
	@make clean -C $(MLX)
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(GREEN)Supressing libraries files$(CYAN)"
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re:
	make fclean
	@$(MAKE) all

.PHONY: all clean fclean re
