# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 00:27:24 by soohong           #+#    #+#              #
#    Updated: 2023/02/21 19:24:09 by soohong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC_INPUT_OUTPUT = \
ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c

SRC_LIST = \
ft_lstadd_back.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
ft_lstsize.c ft_lstadd_front.c ft_lstdelone.c ft_lstlast.c \
ft_lstnew.c

SRC_MATH = \
ft_abs.c ft_atoi.c ft_pow.c ft_sqrt.c

SRC_MEM = \
ft_bzero.c ft_memchr.c ft_memcpy.c ft_memset.c \
ft_calloc.c ft_memcmp.c ft_memmove.c

SRC_STRING = \
ft_isalnum.c ft_isprint.c ft_strdup.c ft_strlcpy.c \
ft_strnstr.c ft_tolower.c ft_isalpha.c ft_itoa.c \
ft_striteri.c ft_strlen.c ft_strrchr.c ft_toupper.c \
ft_isascii.c ft_split.c ft_strjoin.c ft_strmapi.c \
ft_strtrim.c ft_isdigit.c ft_strchr.c ft_strlcat.c \
ft_strncmp.c ft_strcmp.c ft_substr.c

OBJDIR = objects/

OBJ_INPUT_OUTPUT = $(addprefix ${OBJDIR}, ${SRC_INPUT_OUTPUT:%.c=%.o})
OBJ_LIST= $(addprefix ${OBJDIR}, ${SRC_LIST:%.c=%.o})
OBJ_MATH = $(addprefix ${OBJDIR}, ${SRC_MATH:%.c=%.o})
OBJ_MEM= $(addprefix ${OBJDIR}, ${SRC_MEM:%.c=%.o})
OBJ_STRING = $(addprefix ${OBJDIR}, ${SRC_STRING:%.c=%.o})

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all : $(NAME)
	@echo ${G}Success"	"[${NAME}${x}]

$(NAME) : ${OBJ_INPUT_OUTPUT} ${OBJ_LIST} ${OBJ_MATH} ${OBJ_MEM} ${OBJ_STRING}
	@ar rcs ${NAME} ${OBJ_INPUT_OUTPUT} ${OBJ_LIST} ${OBJ_MATH} ${OBJ_MEM} ${OBJ_STRING}
	@echo ${B}Compiling [${NAME}]...${X}

${OBJDIR}%.o : ./src/input_output/%.c includes/libft.h
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./includes -c -o $@ $<
	@printf ${UP}${CUT}

${OBJDIR}%.o : ./src/list/%.c includes/libft.h
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./includes -c -o $@ $<
	@printf ${UP}${CUT}

${OBJDIR}%.o : ./src/math/%.c includes/libft.h
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./includes -c -o $@ $<
	@printf ${UP}${CUT}

${OBJDIR}%.o : ./src/mem/%.c includes/libft.h
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./includes -c -o $@ $<
	@printf ${UP}${CUT}

${OBJDIR}%.o : ./src/string/%.c includes/libft.h
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
