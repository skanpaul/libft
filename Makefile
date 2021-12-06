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
CC			= gcc
CFLAGS 		= -Wall -Wextra -Werror
AR 			= ar -rcs
RM			= rm -f
NORM		= norminette -R CheckForbiddenSourceHeader
# **************************************************************************** #
NAME		= libft.a
# ----------------------------------------------------------------------------
PATH_LIBFT	= ./
HD_LIBFT	= libft.h
SRC_LIBFT	= \
		ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isascii.c \
		ft_isprint.c	ft_strlen.c		ft_memset.c		ft_bzero.c \
		ft_memcpy.c		ft_memmove.c	ft_strlcpy.c	ft_strlcat.c \
		ft_toupper.c	ft_tolower.c	ft_strchr.c		ft_strrchr.c \
		ft_strncmp.c	ft_memchr.c		ft_memcmp.c		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c		ft_strdup.c \
		ft_substr.c		ft_strjoin.c	ft_strtrim.c	ft_split.c \
		ft_itoa.c		ft_strmapi.c	ft_striteri.c	ft_putchar_fd.c \
		ft_putstr_fd.c	ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c \
		ft_lstlast.c 	ft_lstadd_back.c	ft_lstdelone.c \
		ft_lstclear.c	ft_lstiter.c		ft_lstmap.c
OBJ_LIBFT	= ${SRC_LIBFT:.c=.o}
# **************************************************************************** #
PATH_SUBMAKE	= ${PATH_LIBFT}
SRC_NORM		= ${SRC_LIBFT}
HD_NORM			= ${HD_LIBFT}

# **************************************************************************** #
all: $(NAME)

$(NAME): $(OBJ_LIBFT)
	${AR} $(NAME) $(OBJ_LIBFT)

clean:
	${RM} $(OBJ_LIBFT)

fclean: clean
	${RM} $(NAME)

re: fclean all

.PHONY: all clean fclean re

nono:
	${NORM} ${SRC_NORM}
	${NORM} ${HD_NORM}

# **************************************************************************** #
#so:
#	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC_LIBFT)
#	gcc -nostartfiles -shared -o libft.so $(OBJ_LIBFT) ${OBJ_LIBFT_BONUS} 