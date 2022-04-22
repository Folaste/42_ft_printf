# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fleblanc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 13:19:35 by fleblanc          #+#    #+#              #
#    Updated: 2022/04/19 11:46:39 by fleblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strchr.c ft_strlen.c ft_tolower.c ft_toupper.c ft_atoi.c ft_strncmp.c ft_memset.c ft_bzero.c ft_strrchr.c ft_strdup.c ft_strnstr.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_memcpy.c ft_strlcat.c ft_strlcpy.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_strmapi.c ft_striteri.c ft_intlen.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_putnbr_base_fd.c

HEADER	= libft.h

OBJS	= ${SRCS:.c=.o}

CC	= gcc -g

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

$(NAME):	${OBJS}
			ar rcs ${NAME} ${OBJS}

.c.o:
		${CC} ${CFLAGS} -c -I.${HEADER} $< -o ${<:.c=.o}

all:	$(NAME) 

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:		fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) $(SRCSB)
	gcc -nostartfiles -shared -o libft.so $(OBJS) $(OBJSB)

.PHONY: all clean fclean re bonus
