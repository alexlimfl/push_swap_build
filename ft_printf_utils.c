/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:52:33 by folim             #+#    #+#             */
/*   Updated: 2023/06/07 18:52:34 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putchar(int c, int count)
{
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_putstr(char *str, int count)
{
	size_t	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)", count));
	while (str[i])
	{
		count = (ft_putchar(str[i], count));
		i++;
	}
	return (count);
}

int	ft_putnbr(int nb, int count)
{
	if (nb < 0 && nb != -2147483648)
	{
		count = ft_putchar('-', count);
		nb *= -1;
	}
	if (nb == -2147483648)
		count = ft_putstr("-2147483648", count);
	else if (nb >= 10)
	{
		count = ft_putnbr(nb / 10, count);
		count = ft_putnbr(nb % 10, count);
	}
	else
		count = ft_putchar(nb + '0', count);
	return (count);
}

int	ft_un_int_putnbr(unsigned int nb, int count)
{
	if (nb >= 10)
	{
		count = ft_putnbr(nb / 10, count);
		count = ft_putnbr(nb % 10, count);
	}
	else
		count = ft_putchar(nb + '0', count);
	return (count);
}

void	*ft_bzero(void	*str, size_t	n)
{	
	unsigned char	*ptr;
	size_t			i;

	ptr = str;
	i = -1;
	while (i < n)
		ptr[++i] = 0;
	return (ptr);
}
