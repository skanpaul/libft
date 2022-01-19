/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:11:04 by ski               #+#    #+#             */
/*   Updated: 2021/10/28 14:11:09 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H
/* ************************************************************************** */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
/* ************************************************************************** */
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <fcntl.h>

/* ************************************************************************** */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
/* -------------------------------------------------------------------------- */
typedef struct s_gnl
{
	char			*line;
	char			*new;
	char			*old;
	int				line_done;
}t_gnl;

/* ************************************************************************** */
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);	// improved: 18.01.2022
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);

void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
/* ------------------------------------------------------ */
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

size_t	ft_putchar_fd(char c, int fd);	// improved: 18.01.2022
size_t	ft_putstr_fd(char *s, int fd);	// improved: 18.01.2022
void	ft_putendl_fd(char *s, int fd);
size_t	ft_putnbr_fd(int number, int fd);// improved: 18.01.2022
/* ------------------------------------------------------ */
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
/* ---- PRINTF() ------------------------------------------------ */
int		ft_printf(const char *text, ...);

size_t	ft_printf_fd_s(char *s, int fd);			// add: 18.01.2022
size_t	ft_printf_fd_ptr(unsigned long n, int fd);	// add: 18.01.2022
size_t	ft_putnbr_fd_u(unsigned int u, int fd);		// add: 18.01.2022
size_t	ft_printf_fd_xlow(int n, int fd);		// add: 19.01.2022
size_t	ft_printf_fd_xup(int n, int fd);		// add: 19.01.2022
/* ---- GET_NEXT_LINE() ------------------------------------------------ */
char	*get_next_line(int fd);

/* ************************************************************************** */
/* int		ft_isspace(int c); */

/* ************************************************************************** */
#endif