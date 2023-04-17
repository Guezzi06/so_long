# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 12:01:25 by aguezzi           #+#    #+#              #
#    Updated: 2023/04/16 11:40:06 by aguezzi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= so_long

SRCS	= so_long.c init.c check_error.c move.c

CC	= gcc

FLAGS	= -Wall -Wextra -Werror

OBJS	= ${SRCS:.c=.o}

RM	= rm -f

all:	${NAME}

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		make -C libft
		${CC} ${FLAGS} -Llibft -lft -lmlx -framework AppKit -framework OpenGL ${OBJS} -o ${NAME}

clean:
		${RM} ${OBJS}
		make clean -C libft

fclean:	clean
		${RM} ${NAME}
		${RM} libft/libft.a

re:	fclean all

.PHONY:	all clean fclean re