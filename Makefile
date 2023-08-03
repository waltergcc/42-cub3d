# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 08:04:49 by wcorrea-          #+#    #+#              #
#    Updated: 2023/08/03 21:08:37 by wcorrea-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OUT = cub3D

SRC = src/main.c \
		src/utils.c \
		src/parse.c src/parse_utils.c \
		src/clean_exit.c

OBJS = ${SRC:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I include
MAKE = make -C
LIBFT_PATH = lib/libft
LIBFT = -L ${LIBFT_PATH} -lft

.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(OUT): ${OBJS}
		${MAKE} ${LIBFT_PATH}
		${CC} ${OBJS} ${LIBFT} -o ${OUT}

all:	${OUT}

clean:
		${MAKE} ${LIBFT_PATH} clean
		${RM} ${OBJS}

fclean: clean
		${MAKE} ${LIBFT_PATH} fclean
		${RM} ${OUT}

re: fclean all

.PHONY: all clean fclean re