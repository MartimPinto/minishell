# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 17:38:36 by gabrrodr          #+#    #+#              #
#    Updated: 2024/02/01 12:18:07 by mcarneir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

NAME = minishell

SRC = 	src/main.c \
		src/init.c \
		src/frees.c \
		src/utils_1.c \
		src/utils_2.c \
		src/utils_3.c \
		src/utils_4.c \
		src/utils_5.c \
		src/lexer.c \
		src/lexer_utils.c \
		src/lexer_lst.c \
		src/lexer_append.c \
		src/parser.c \
		src/parser_utils.c \
		src/parser_utils2.c \
		src/builtins.c \
		src/builtins_utils.c \
		src/unset.c \
		src/env.c \
		src/export.c \
		src/export_utils.c \
		src/export_utils_2.c \
		src/str_expander_utils.c \
		src/errors.c \
		src/execute.c \
		src/redirects.c \
		src/signals.c \
		src/cd.c \
		src/exit.c \
		src/cmds.c \
		src/cmds_utils.c \
		src/exit_codes.c \
		src/heredocs.c \
		src/redirection_error.c \
		src/is_expandable.c \

OBJ_SRC = $(SRC:.c=.o)

LIBFT = libs/libft/libft.a

all: deps $(NAME)

deps:
	$(MAKE) -C ./libs/libft

$(NAME): $(OBJ_SRC) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ_SRC) $(LIBFT) -lreadline -o $(NAME)

clean:
	$(MAKE) clean -C ./libs/libft
	@$(RM) $(OBJ_SRC)

fclean: clean
	@$(RM) $(LIBFT) $(NAME)
	@$(RM) .tmp*

re: fclean all