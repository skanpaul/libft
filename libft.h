/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:11:04 by ski               #+#    #+#             */
/*   Updated: 2022/02/02 08:53:33 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H
/* ************************************************************************** */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
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
/* ---- CHAINLIST for 42 Lausanne ------------------------------------------- */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
/* ---- CHAINLIST for Sorakann Ki------------------------------------------- */
typedef struct s_elem
{
	void			*content;
	struct s_elem	*next;
	struct s_elem	*previous;
}	t_elem;
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
/* ------------------------------------------------------ */
int		ft_toupper(int c);
int		ft_tolower(int c);
/* ************************************************************************** */
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
/* ------------------------------------------------------ */
size_t	ft_strlen(const char *s);	// improved: 18.01.2022
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
/* ------------------------------------------------------ */
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
/* ------------------------------------------------------ */
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
/* ------------------------------------------------------ */
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
void	ft_split_free(char **split_table);	// added 10.02.2022
int		ft_split_count(char **split_table);	// added 10.02.2022
/* ------------------------------------------------------ */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
/* ------------------------------------------------------ */
size_t	ft_putchar_fd(char c, int fd);	// improved: 18.01.2022
size_t	ft_putstr_fd(char *s, int fd);	// improved: 18.01.2022
void	ft_putendl_fd(char *s, int fd);
size_t	ft_putnbr_fd(int number, int fd);// improved: 18.01.2022

/* **** CHAINLIST from 42 Lausanne ****************************************** */
t_list	*ft_lstnew(void *content);
/* ft_lstdelone: delete the content of the element and the element itself */
void	ft_lstdelone(t_list *lst, void (*del)(void *));
/* ft_lstadd_front: put element on the TOP of the list */
void	ft_lstadd_front(t_list **alst, t_list *new);
/* ft_lstadd_back: put element on the BOTTOM of the list */
void	ft_lstadd_back(t_list **alst, t_list *new);
/* ft_lstlast: return pointer on the LAST ELEMENT */
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
/* ft_lstclear: delete list and content of all elements */
void	ft_lstclear(t_list **lst, void (*del)(void *));
/* ft_lstiter: modifie content of all elements with f */
void	ft_lstiter(t_list *lst, void (*f)(void *));
/* ft_lstmap: copy the list and assign the content f */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* **** CHAINLIST from Sorakann Ki ****************************************** */
t_elem	*ll_new_elem(void *content);
void	ll_del_elem(t_elem *elem, void (*del_content)(void *));
void	ll_add_elem_to_top(t_elem **top_elem, t_elem *new_elem);
void	ll_add_elem_to_bottom(t_elem **top_elem, t_elem *new_elem);
t_elem	*ll_get_last_elem(t_elem *top_elem);

// t_elem	*ll_get_elem(t_elem *top_elem);

int		ll_size(t_elem *top_elem);
void	ll_del_list(t_elem **top_elem, void (*del_content)(void *));
void	ll_change_content_list(t_elem *top_elem, void (*f)(void *));
t_elem	*ll_copy_list(t_elem *top_elem, void *(*f)(void *), void (*d)(void *));

/* **** PRINTF() ************************************************************ */
int		ft_printf(const char *text, ...);

size_t	ft_printf_fd_s(char *s, int fd);			// add: 18.01.2022
size_t	ft_printf_fd_ptr(unsigned long n, int fd);	// add: 18.01.2022
size_t	ft_putnbr_fd_u(unsigned int u, int fd);		// add: 18.01.2022
size_t	ft_printf_fd_xlow(int n, int fd);		// add: 19.01.2022
size_t	ft_printf_fd_xup(int n, int fd);		// add: 19.01.2022
/* **** GET_NEXT_LINE() ***************************************************** */
char	*get_next_line(int fd);

/* ************************************************************************** */
/* int		ft_isspace(int c); */

/* ************************************************************************** */
#endif
