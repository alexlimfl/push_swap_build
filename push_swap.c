/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:36:17 by folim             #+#    #+#             */
/*   Updated: 2023/07/05 21:36:18 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;
	t_node	*otpt;
	char	**str;

	a = NULL;
	b = NULL;
	otpt = NULL;
	if (argc < 2)
		exit_message();
	no_space_and_character_allowed(argv);
	if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		a = ll_convert(str);
	}
	else
		a = ll_convert(argv + 1);
	sorting_type_assign(&a, &b, &otpt);
	print_output(&otpt);
	delete_list(&otpt);
	delete_list(&a);
	delete_list(&b);
	return (0);
}
	// system("leaks -q push_swap");