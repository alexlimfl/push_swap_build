/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim   <folim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 22:53:54 by folim             #+#    #+#             */
/*   Updated: 2023/05/06 22:53:55 by folim            ###   ########.kl       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((int)(unsigned char)str1[i] - (int)(unsigned)str2[i]);
		if (str1[i] == 0 || str2 == 0)
			return (0);
		i++;
	}
	return (0);
}

/*
int main()
{

    char *s1 = "Hello";
    char *s2 = "HelAo";
    int n = 15;

    printf("%d\n",ft_strncmp(s1,s2,n));
    printf("%d\n",strncmp(s1,s2,n));
    return 0;
}
*/