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

LIBNAME2 = ft
LIBPATH2 = .

# **************************************************************************** #
cli: cl
	ranlib $(LIBNAME1)

cl: co
	ar rc $(LIBNAME1) *.o

co:
	gcc $(CFLAGS) -c $(SRC_LIB)

# **************************************************************************** #
all: $(NAME)

$(NAME):
	echo bonjour
#	gcc $(CFLAGS) -o $(NAME) $(SRC) -L$(LIBPATH2) -l$(LIBNAME2)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

dall:
	echo $(SRC_LIB)
