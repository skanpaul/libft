/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:09:27 by ski               #+#    #+#             */
/*   Updated: 2021/12/06 18:09:30 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */
static char	*make_seg(int fd, char *buf, int *line_done, ssize_t *char_read);

/* ************************************************************************** */
char	*get_next_line(int fd)
{
	static t_gnl	g;
	static char		buf[BUFFER_SIZE];
	static ssize_t	char_read = BUFFER_SIZE;

	g.line_done = 0;
	g.line = ft_substr("", 0, 0);
	while (g.line_done == 0)
	{
		g.new = make_seg(fd, buf, &g.line_done, &char_read);
		if (g.new == NULL)
		{
			if ((char_read == 0) && (g.line[0] != '\0'))
				return (g.line);
			free (g.line);
			return (NULL);
		}
		g.old = g.line;
		g.line = ft_strjoin(g.old, g.new);
		free (g.old);
		free (g.new);
		if (!g.line)
			return (NULL);
	}
	return (g.line);
}

/* ************************************************************************** */
static char	*make_seg(int fd, char *buf, int *line_done, ssize_t *char_read)
{
	char			*new;
	static ssize_t	start = BUFFER_SIZE;
	ssize_t			end;

	if (start == *char_read)
	{
		start = 0;
		*char_read = read(fd, buf, BUFFER_SIZE);
		if ((*char_read == 0) || (*char_read == -1))
			return (NULL);
	}
	end = start;
	while ((buf[end] != '\n') && (end < (*char_read - 1)))
		end++;
	if (buf[end] == '\n')
		*line_done = 1;
	new = ft_substr(buf, start, (end - start + 1));
	if (end >= *char_read - 1)
		start = *char_read;
	else
		start = ++end;
	return (new);
}

/* ************************************************************************** */
// char *make_seg(int fd, char *buf, int *line_done, ssize_t *char_read) 
// {
// 	char			*new;
// 	static ssize_t	start = BUFFER_SIZE;
// 	ssize_t			end;
// 	// ---------------------------------------------------------
// 	// Est-ce que tout le buffer a été complètement analysé ?
// 	if (start == *char_read)
// 	{
// 		start = 0;
// 		*char_read = read(fd, buf, BUFFER_SIZE);
// si fin de fichier ou problem
// 		if ((*char_read == 0) || (*char_read == -1)) 
// 			return (NULL);
// 	}
// 	// Cherche la fin de segment pour le "new" string
// 	end = start;
// 	while ((buf[end] != '\n') && (end < (*char_read - 1)))
// 		end++;
// 	// Si RETOUR-A-LA-LIGNE trouvé
// 	if (buf[end] == '\n')
// 		*line_done = 1;	// Alors FIN-LIGNE trouvé 
// 	// Extrait la ligne trouvée (complète ou tronqué)
// 	new = ft_substr(buf, start, (end - start + 1));		// crée un "new" string 
// SI:		tous les caractère du buffer ont été analysé
// 	if (end >= *char_read - 1)	
// 		start = *char_read;		// ALORS:	prêt a remplir un nouveau le buffer	
// 	else 
// 		start = ++end;			// SINON:	préparte le prochain START et END
// 	// ----------------------------------------------------------------------
// 	return (new);	
// }
	// char			*line;
	// char			*new;
	// char			*old;
	// static char		buf[BUFFER_SIZE];
	// static ssize_t	char_read = BUFFER_SIZE;
	// int				line_done;