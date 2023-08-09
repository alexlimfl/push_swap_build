/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim   <folim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:29:40 by folim             #+#    #+#             */
/*   Updated: 2023/05/31 16:29:41 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t	nmemb, size_t	size)
{
	size_t			*ptr;
	size_t			total_size;

	total_size = nmemb * size;
	if (nmemb == SIZE_MAX || size == SIZE_MAX)
		return (0);
	ptr = malloc(total_size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, total_size);
	return (ptr);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == (char) c)
			return ((char *)str + i);
		i++;
	}
	if (c == 0)
		return ((char *)str + i);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_out;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen((char *) s1);
	len2 = ft_strlen((char *) s2);
	s_out = ft_calloc(1, len1 + len2 + 1);
	if (!s_out)
		return (NULL);
	i = -1;
	while (++i < len1)
		s_out[i] = s1[i];
	i = -1;
	while (++i < len2)
		s_out[len1 + i] = s2[i];
	s_out[len1 + i] = 0;
	free ((void *)s1);
	return (s_out);
}
