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

int main(int argc, char *argv[])
{
	t_node	*A;
	t_node	*B;
	t_node	*output;
	char	**str;

	A = NULL;
	B = NULL;
	output = NULL;
	if (argc < 2)
		exit_message();
	no_space_and_character_allowed(argv);
	if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		A = ll_convert(str);
	}
	else
		A = ll_convert(argv+1);
	sorting_type_assign(&A, &B, &output);
	print_output(&output);
	delete_list(&output);
	delete_list(&A);
	delete_list(&B);
	// system("leaks -q push_swap");
	return (0);
}