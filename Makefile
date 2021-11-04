# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/28 09:45:53 by ski               #+#    #+#              #
#    Updated: 2021/11/04 16:34:14 by ski              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS 	= -Wall -Wextra -Werror

AR 		= ar rc
RM		= rm -f 

SRC 	= $(wildcard *.c)
OBJS 	= ${SRC:.c=.o}

NAME 	= libft.a

all: $(NAME)
# **************************************************************************** #
%.o: %.c
	$(CC) -o $@ -c $^

# **************************************************************************** #

$(NAME): $(OBJS)
	${AR} $(NAME) $(OBJS)
	ranlib $(NAME)
# **************************************************************************** #

clean:
	${RM} *.o

fclean: clean
	${RM} $(NAME)

re: fclean all

.PHONY: all clean fclean re
