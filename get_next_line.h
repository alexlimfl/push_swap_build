/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim   <folim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:31:55 by folim             #+#    #+#             */
/*   Updated: 2023/05/31 16:31:57 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

size_t		ft_strlen(const char *str);
void		*ft_bzero(void	*str, size_t	n);
void		*ft_calloc(size_t	nmemb, size_t	size);
char		*ft_strchr(const char *str, int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_get_line_after_newline(char *s_str);
char		*ft_get_line_before_newline(char *s_str);
char		*ft_get_line_read(int fd, char *s_str);
char		*get_next_line(int fd);

#endif