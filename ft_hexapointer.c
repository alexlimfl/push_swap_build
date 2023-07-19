/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexapointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:35:44 by folim             #+#    #+#             */
/*   Updated: 2023/06/21 16:28:13 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_hexadecimal(unsigned int nb, int c, int count)
{
	const char	strlo[16] = "0123456789abcdef";
	const char	strup[16] = "0123456789ABCDEF";
	char		*arr;
	int			rem;
	int			i;

	if (nb == 0)
		return (ft_putchar('0', count));
	arr = f_calloc(1, sizeof(char *));
	if (!arr)
		return (0);
	i = 0;
	while (nb > 0)
	{
		rem = nb % 16;
		nb = nb / 16;
		if (c == 'x')
			arr[i++] = strlo[rem];
		if (c == 'X')
			arr[i++] = strup[rem];
	}
	while (i--)
		count = ft_putchar(arr[i], count);
	free(arr);
	return (count);
}

int	ft_puthexadecimal(uintptr_t address, int count)
{
	if (address >= 16)
	{
		count = ft_puthexadecimal(address / 16, count);
		count = ft_puthexadecimal(address % 16, count);
	}
	else
	{
		if (address + '0' >= '0' && address + '0' <= '9')
			count = ft_putchar(address + '0', count);
		else
			count = ft_putchar(address + 87, count);
	}
	return (count);
}
	//97-49+39

int	ft_pointer(void *ptr, int count)
{
	count = ft_putstr("0x", count);
	count = ft_puthexadecimal((uintptr_t) ptr, count);
	return (count);
}
