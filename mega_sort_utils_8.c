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

void	finalization_attach(t_node **A, t_node **B, t_node **otpt, int m)
{
	int		target_p_a;

	(*otpt)->curr_b = *B;
	while (*B != NULL && (*B)->rank > m)
	{
		label_position(B);
		(*otpt)->curr_b = *B;
		target_p_a = get_target_p_a(A, (*otpt)->curr_b->rank);
		push_a(A, B, otpt, target_p_a);
		pa(A, B, otpt, 1);
	}
}

void	finalization(t_node **A, t_node **B, t_node **otpt)
{
	int	m[4];
	int	i;

	m[0] = 0;
	m[1] = get_three_median(B, 1, 1);
	m[2] = get_three_median(B, 1, 2);
	m[3] = get_three_median(B, 1, 3);
	i = 3;
	while (*B != NULL)
	{
		while ((*B)->rank <= m[i] && c_n(*B) > 1)
			rb(B, otpt, 1);
		finalization_attach(A, B, otpt, m[i]);
		if (!above_median_available(B, m[i]))
			i--;
	}
}

void	quick_sort(t_node **A, t_node **B, t_node **otpt)
{
	decend_top(A, B, otpt, 5);
	(*otpt)->median = get_median_rank_within_chunk(B, 4);
	split_chunk_top(A, B, otpt, 4);
	decending_bot(A, B, otpt, 4);
	(*otpt)->median = get_median_rank_within_chunk(B, 3);
	split_chunk_bottom(A, B, otpt, 3);
	decend_top(A, B, otpt, 3);

	(*otpt)->median = get_three_median(B, 2, 3);
	split_chunk_top(A, B, otpt, 2);
	(*otpt)->median = get_three_median(B, 2, 2);
	split_chunk_bottom(A, B, otpt, 2);
	decend_top(A, B, otpt, 2);

	finalization(A, B, otpt);
}

void	final_sort(t_node **A, t_node **otpt)
{
	t_node	*curr;

	label_position(A);
	curr = *A;
	while (curr != NULL)
	{
		if (curr->rank == get_lowest_rank(A))
			break ;
		curr = curr->next;
	}
	while ((*A)->position != curr->position)
	{
		if (curr->position <= c_n(*A) / 2)
			ra(A, otpt, 1);
		else
			rra(A, otpt, 1);
	}
}