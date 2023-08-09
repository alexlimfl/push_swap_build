/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim   <folim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:25:02 by folim             #+#    #+#             */
/*   Updated: 2023/05/31 15:25:03 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_get_line_after_newline(char *s_str)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (s_str[i] && s_str[i] != '\n')
		i++;
	if (!s_str[i])
	{	
		free (s_str);
		return (NULL);
	}
	str = ft_calloc(1, ft_strlen(s_str) - i);
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (s_str[i])
		str[j++] = s_str[i++];
	free(s_str);
	return (str);
}

char	*ft_get_line_before_newline(char *s_str)
{
	char	*str;
	int		len;

	if (!s_str[0])
		return (NULL);
	len = 0;
	while (s_str[len] != '\n' && s_str[len])
		len++;
	str = ft_calloc(1, len + 2);
	if (!str)
		return (NULL);
	len = 0;
	while (s_str[len] != '\n' && s_str[len])
	{
		str[len] = s_str[len];
		len++;
	}
	if (s_str[len] == '\n')
		str[len] = '\n';
	return (str);
}

char	*ft_get_line_read(int fd, char *s_str)
{
	char	*str;
	ssize_t	bytes_read;

	str = ft_calloc(1, BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	bytes_read = 1;
	while (bytes_read != 0 && !ft_strchr(s_str, '\n'))
	{
		bytes_read = read(fd, str, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (str);
			return (NULL);
		}
		if (bytes_read != BUFFER_SIZE)
			str[bytes_read] = '\0';
		s_str = ft_strjoin(s_str, str);
	}
	free (str);
	return (s_str);
}

char	*get_next_line(int fd)
{
	static char	*s_str;
	char		*line_now;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s_str = ft_get_line_read(fd, s_str);
	if (!s_str)
		return (NULL);
	line_now = ft_get_line_before_newline(s_str);
	s_str = ft_get_line_after_newline(s_str);
	return (line_now);
}
