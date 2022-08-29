# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youchenn <youchenn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 16:41:15 by iomayr            #+#    #+#              #
#    Updated: 2022/08/29 11:54:30 by youchenn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -g -Wall -Wextra -Werror -I $(shell brew --prefix readline)/include

CC = gcc

SRC = lexer/expand_dollar_utiles.c lexer/join_word.c \
		lexer/quotes.c lexer/expand_dollar.c \
		lexer/lexer.c lexer/get_symbol.c \
		lexer/get_delimiter.c \
		syntax/syntax_error.c syntax/error_message.c \
		parse/parse.c parse/parse_utiles.c\
		libft1/libft1.c libft1/libft.c\
		env/get_env.c \
		herdoc/treat_herdoc.c \
		shell/main.c \
		redirections/redirections.c \
		builtins/builtin_cd.c     \
		builtins/is_it_a_builtin.c \
		builtins/builtin_echo.c   \
		builtins/builtin_env.c    \
		builtins/builtin_export.c \
		builtins/builtin_pwd.c    \
		builtins/builtin_unset.c  \
		builtins/builtins.c       \
		builtins/built_exit.c       \
		builtins/handel_env.c     \
		builtins/utils_for_env.c \
		excution/find_path.c 		\
		excution/utils.c 		\
		excution/excute_multi_cmds.c  		\
		excution/simple_command.c 		\

OBJ = ${SRC:%.c=%.o}

LIB_PATH = ./libft/libft.a

NAME = minishell

all : ${NAME}

${NAME} : ${OBJ} includes/minishell.h
	make -C libft
	@${CC} ${CFLAGS} ${OBJ} -o ${NAME} ${LIB_PATH} -L $(shell brew --prefix readline)/lib -lreadline
	@echo "\033[1;32m##########COMPILED SUCCESSFULY##########\033[0m"


clean:
	make fclean -C libft
	@rm -rf ${OBJ}

fclean: clean
	@rm -rf ${NAME}
	@echo "\033[1;32m##########CLEANED SUCCESSFULY##########\033[0m"


re: fclean all