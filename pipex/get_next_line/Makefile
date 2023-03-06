# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 19:47:43 by soohong           #+#    #+#              #
#    Updated: 2023/03/06 19:59:23 by soohong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = libgnl.a

OBJDIR = objects/

SRC = get_next_line.c get_next_line_utils.c

OBJ = $(addprefix ${OBJDIR}, ${SRC:%.c=%.o})

all : $(NAME)
	@echo ${G}Success"	"[${NAME}${x}]

$(NAME) : ${OBJ}
	@ar rcs ${NAME} ${OBJ}
	@echo ${B}Compiling [${NAME}]...${X}

${OBJDIR}%.o : ./%.c get_next_line.h
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./includes -c -o $@ $<
	@printf ${UP}${CUT}

clean:
	@echo ${R}Cleaning"  "[${OBJDIR}]...${X}
	@/bin/rm -Rf ${OBJDIR}

fclean: clean
	@echo ${R}Cleaning"  "[${NAME}]...${X}
	@/bin/rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
