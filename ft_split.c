/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:15:23 by folim             #+#    #+#             */
/*   Updated: 2023/05/11 16:15:24 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_delimiter(char str_char, char delimiter)
{
	if (str_char == delimiter)
		return (1);
	return (0);
}

static int	word_occurance(char const *str, char delimiter)
{
	unsigned int	i;
	unsigned int	word_c;

	if (!str)
		return (0);
	i = 0;
	word_c = 0;
	while (str[i])
	{
		while (str[i] && str[i] == delimiter)
			i++;
		if (str[i] && !is_delimiter(str[i], delimiter))
			word_c++;
		while (str[i] && !is_delimiter(str[i], delimiter))
			i++;
	}
	return (word_c);
}

static int	word_length(char const *str, unsigned int i, char delimiter)
{
	unsigned int	j;
	unsigned int	wordlen;

	if (!str)
		return (0);
	j = 0;
	wordlen = 0;
	while (str[i + j] && !is_delimiter(str[i + j], delimiter))
	{
		wordlen++;
		j++;
	}
	return (wordlen);
}

char	**ft_split(char const *s, char c)
{
	char			**output;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	output = malloc(sizeof(char *) * (word_occurance(s, c) + 1));
	if (!s || !output)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && is_delimiter(s[i], c))
			i++;
		if (!s[i])
			break ;
		output[j] = malloc(sizeof(char) * (word_length(s, i, c)) + 1);
		k = 0;
		while (s[i] && !is_delimiter(s[i], c))
			output[j][k++] = s[i++];
		output[j++][k] = '\0';
	}
	output[j] = 0;
	return (output);
}

// char *stringmaker(char const *s, char c)
// {
// 	unsigned int i;
// 	unsigned int j;
// 	unsigned int
// }