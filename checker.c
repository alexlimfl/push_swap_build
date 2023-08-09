/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 21:54:04 by folim             #+#    #+#             */
/*   Updated: 2023/08/08 21:54:05 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	operation_attach(t_node **a, t_node **b, t_node **otpt, char *s)
{
	if (s[0] == 's' && s[1] == 'a')
		sa(a, b, otpt, 1);
	else if (s[0] == 's' && s[1] == 'b')
		sb(a, b, otpt, 1);
	else if (s[0] == 's' && s[1] == 's')
		ss(a, b, otpt, 1);
	if (s[0] == 'r' && s[1] == 'a')
		ra(a, b, otpt, 1);
	else if (s[0] == 'r' && s[1] == 'b')
		rb(a, b, otpt, 1);
	else if (s[0] == 'r' && s[1] == 'r')
		rr(a, b, otpt, 1);
}

void	operation(t_node **a, t_node **b, t_node **otpt, char *s)
{
	if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a')
		rra(a, b, otpt, 1);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b')
		rrb(a, b, otpt, 1);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r')
		rrr(a, b, otpt, 1);
	else if (s[0] == 'p' && s[1] == 'a')
		pa(a, b, otpt, 1);
	else if (s[0] == 'p' && s[1] == 'b')
		pb(a, b, otpt, 1);
	else
		operation_attach(a, b, otpt, s);
}

void	control(t_node **a, t_node **b, t_node **otpt)
{
	int		initial_total;
	char	*input;

	initial_total = c_n(*a);
	check_duplicate(a);
	while (!(c_n(*a) == initial_total && check_sorted(a)))
	{
		input = get_next_line(0);
		if (ft_strncmp(input, "quit", 4) == 0)
			clear_ll_exit(a, b, otpt, 2);
		if (ft_strncmp(input, "view", 4) == 0)
			view_all(*a, *b);
		operation(a, b, otpt, input);
	}
	view_all(*a, *b);
	clear_ll_exit(a, b, otpt, 1);
}

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
	control(&a, &b, &otpt);
	return (0);
}
