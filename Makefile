# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 12:01:25 by aguezzi           #+#    #+#              #
#    Updated: 2023/07/11 11:41:03 by aguezzi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= so_long

NAME_BONUS	= so_long_bonus

SRCS	= so_long.c so_long_utils.c display.c check_map_1.c check_map_2.c move.c

BONUS	= bonus/so_long_bonus.c bonus/so_long_utils_bonus.c bonus/move_bonus.c \
          bonus/display.c bonus/display_Canim.c bonus/persos_image.c \
		  bonus/run.c bonus/check_map_bonus_1.c bonus/check_map_bonus_2.c \
		  bonus/enemy_1.c bonus/enemy_2.c

CC	= gcc

FLAGS	= -Wall -Wextra -Werror

OBJS	= ${SRCS:.c=.o}

BONUS_OBJS	= ${BONUS:.c=.o}

RM	= rm -f

all:	${NAME}

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		make -C libft
		${CC} ${FLAGS} -Llibft -lft -lmlx -framework AppKit -framework OpenGL ${OBJS} -o ${NAME}

bonus:	${BONUS_OBJS}
		make -C libft
		${CC} ${FLAGS} -Llibft -lft -lmlx -framework AppKit -framework OpenGL ${BONUS_OBJS} -o ${NAME_BONUS}

clean:
		${RM} ${OBJS} ${BONUS_OBJS}
		make clean -C libft

fclean:	clean
		${RM} ${NAME} ${NAME_BONUS}
		${RM} libft/libft.a

re:	fclean all

.PHONY:	all clean fclean re