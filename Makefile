# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 17:34:55 by fleblanc          #+#    #+#              #
#    Updated: 2022/04/21 18:01:28 by fleblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS		= ft_printf.c \
			  ft_init_struct.c \
			  ft_check_args.c \
			  ft_printf_char.c \
			  ft_printf_string.c

OBJS		= ${SRCS:.c=.o}

HEADER		= ft_printf.h

DLIB		= ./libft/

NLIB		= libft.a

CC			= gcc

CFLAGS		= -g -Werror -Wextra -Wall

RM			= rm -rf

.c.o:
			${CC} ${CFLAGS} -c -I.${HEADER} $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			make -C ${DLIB} ${NLIB}
			cp $(DLIB)$(NLIB) .
			mv $(NLIB) $(NAME)
			ar rcs ${NAME} ${OBJS}

all:		$(NAME)

bonus:		all

clean:	
			make -C ${DLIB} clean
			${RM} ${OBJS}
			

fclean:		clean
			${RM} ${DLIB}${NLIB}
			${RM} ${NAME}

re: 		fclean all

test:		
			make all 
			make clean

.PHONY: all fclean clean re test
