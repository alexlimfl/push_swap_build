/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:28:04 by folim             #+#    #+#             */
/*   Updated: 2023/06/07 14:28:05 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*f_calloc(size_t	nmemb, size_t	size)
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

int	ft_convesion(va_list args, char c, int count)
{
	if (c == 'c')
		count = ft_putchar(va_arg(args, int), count);
	else if (c == 's')
		count = ft_putstr(va_arg(args, char *), count);
	else if (c == 'i' || c == 'd')
		count = ft_putnbr(va_arg(args, int), count);
	else if (c == 'u')
		count = ft_un_int_putnbr(va_arg(args, unsigned int), count);
	else if (c == 'x' || c == 'X')
		count = ft_hexadecimal(va_arg(args, unsigned int), c, count);
	else if (c == 'p')
		count = ft_pointer(va_arg(args, void *), count);
	else if (c == '%')
		count = ft_putchar('%', count);
	return (count);
}

int	ft_printf(const char	*str, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, str);
	if (!str)
		return (0);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count = ft_convesion(args, str[i + 1], count);
			i += 2;
		}
		else
			count = ft_putchar(str[i++], count);
	}
	va_end (args);
	return (count);
}

// int main()
// {
//     char *str = "World";
// 	char c = 'a';
// 	int nbD = 0;
// 	int nbI = 0;
// 	unsigned int u_nb = 4297295;
// 	unsigned int u_nb1 = 0;

// 	printf("count printf = %d\n",
// 		printf("44%%Hello\nC = (%c)\nS= (%s)\nD = (%d%%)\n
// I = (%i)\nU = (%u)\nx = (%x)\nX = (%X)\nP = (%p)\n",
// 		 c, str, nbD, nbI, u_nb, u_nb, u_nb, str));
// 	printf("count ft_printf = %d\n",
// 		ft_printf("44%%Hello\nC = (%c)\nS= (%s)\nD = (%d%%)\n
// I = (%i)\nU = (%u)\nx = (%x)\nX = (%X)\nP = (%p)\n",
// 		 c, str, nbD, nbI, u_nb, u_nb, u_nb, str));

// 	//check hexadecimal
// 	while (u_nb1 <= 30)
// 	{
// 		printf("x = (%x)\nX = (%X)\n\n", 0, 0);
// 		ft_printf("num = (%u)\nx = (%x)\nX = (%X)\n", u_nb1, 0, 0);
// 		u_nb1++;
// 	}

// 	system("leaks -q debug.out");
//     return (0);
// }

// cspdiuxX%