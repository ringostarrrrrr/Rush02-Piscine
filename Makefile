# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takokamo <takokamo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/08 22:16:36 by takokamo          #+#    #+#              #
#    Updated: 2022/05/08 22:18:47 by takokamo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= cut_space.c dict_struct.c main.c nketa.c parse.c split.c functions.c miketa.c

OBJS	= ${SRCS:.c=.o}

NAME	= rush-02

CC+FLAGS		= gcc -Werror -Wall -Wextra -o
RM		= rm -f

${NAME}:	${OBJS}
			${CC+FLAGS}  ${NAME}  ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}