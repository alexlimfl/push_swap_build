/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mega_sort_utils_8.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:57:39 by folim             #+#    #+#             */
/*   Updated: 2023/08/07 23:57:40 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	above_median_available(t_node **lst, int median)
{
	t_node	*curr;

	curr = *lst;
	while (curr != NULL)
	{
		if (curr->rank > median)
			return (1);
		curr = curr->next;
	}
	return (0);
}

void	finalization_attach(t_node **a, t_node **b, t_node **otpt, int m)
{
	int		target_p_a;

	(*otpt)->curr_b = *b;
	while (*b != NULL && (*b)->rank > m)
	{
		label_position(b);
		(*otpt)->curr_b = *b;
		target_p_a = get_target_p_a(a, (*otpt)->curr_b->rank);
		push_a(a, b, otpt, target_p_a);
		pa(a, b, otpt, 1);
	}
}

void	finalization(t_node **a, t_node **b, t_node **otpt)
{
	int	m[4];
	int	i;

	m[0] = 0;
	m[1] = get_three_median(b, 1, 1);
	m[2] = get_three_median(b, 1, 2);
	m[3] = get_three_median(b, 1, 3);
	i = 3;
	while (*b != NULL)
	{
		while ((*b)->rank <= m[i] && c_n(*b) > 1)
			rb(a, b, otpt, 1);
		finalization_attach(a, b, otpt, m[i]);
		if (!above_median_available(b, m[i]))
			i--;
	}
}

void	quick_sort(t_node **a, t_node **b, t_node **otpt)
{
	decend_top(a, b, otpt, 5);
	(*otpt)->median = get_median_rank_within_chunk(b, 4);
	split_chunk_top(a, b, otpt, 4);
	decending_bot(a, b, otpt, 4);
	(*otpt)->median = get_median_rank_within_chunk(b, 3);
	split_chunk_bottom(a, b, otpt, 3);
	decend_top(a, b, otpt, 3);
	(*otpt)->median = get_three_median(b, 2, 3);
	split_chunk_top(a, b, otpt, 2);
	(*otpt)->median = get_three_median(b, 2, 2);
	split_chunk_bottom(a, b, otpt, 2);
	decend_top(a, b, otpt, 2);
	finalization(a, b, otpt);
}

void	final_sort(t_node **a, t_node **b, t_node **otpt)
{
	t_node	*curr;

	label_position(a);
	curr = *a;
	while (curr != NULL)
	{
		if (curr->rank == get_lowest_rank(a))
			break ;
		curr = curr->next;
	}
	while ((*a)->position != curr->position)
	{
		if (curr->position <= c_n(*a) / 2)
			ra(a, b, otpt, 1);
		else
			rra(a, b, otpt, 1);
	}
}
