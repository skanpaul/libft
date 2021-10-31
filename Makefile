# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/28 09:45:53 by ski               #+#    #+#              #
#    Updated: 2021/10/28 09:46:09 by ski              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sorakann
CFLAGS = -Wall -Wextra -Werror

LIBNAME1 = libft.a
SRC_LIB = $(wildcard *.c)

#LIBNAME2 = ft
#LIBPATH2 = .

all: $(NAME)

$(NAME): cli

# **************************************************************************** #
cli: cl
	ranlib $(LIBNAME1)

cl: co
	ar rc $(LIBNAME1) *.o

co:
	gcc $(CFLAGS) -c $(SRC_LIB)
# **************************************************************************** #

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
