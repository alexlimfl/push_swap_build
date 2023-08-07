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

int above_median_available(t_node **lst, int median)
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

int finalization_attach(t_node **A, t_node **B, t_node **output, int m)
{
	// t_node	*curr_b;
	int		target_p_a;

	(*output)->curr_b = *B;
	while (*B != NULL && (*B)->rank > m)
	{
		label_position(B);
		(*output)->curr_b = *B;
		target_p_a = get_target_p_A(A, (*output)->curr_b->rank);
		push_a(A, B, output, target_p_a);
		pa(A, B, output, 1);
	}
}

int	finalization(t_node **A, t_node **B, t_node **output)
{
	int 	m[4];
	int		i;

	m[0] = 0;
	m[1] = get_three_median(B, 1, 1);
	m[2] = get_three_median(B, 1, 2);
	m[3] = get_three_median(B, 1, 3);
	i = 3;
	while (*B != NULL)
	{
		while ((*B)->rank <= m[i] && c_node(*B) > 1)
			rb(B, output, 1);
		finalization_attach(A, B, output, m[i]);
		if (!above_median_available(B, m[i]))
			i--;
	}
}

void	quick_sort(t_node **A, t_node **B, t_node **output)
{
	decending_from_top(A, B, output, 5);
	(*output)->median = get_median_rank_within_chunk(B, 4);
	split_chunk_top(A, B, output, 4);
	decending_from_bottom(A, B, output, 4);
	(*output)->median = get_median_rank_within_chunk(B, 3);
	split_chunk_bottom(A, B, output, 3);
	decending_from_top(A, B, output, 3);

	(*output)->median = get_three_median(B, 2, 3);
	split_chunk_top(A, B, output, 2);
	(*output)->median = get_three_median(B, 2, 2);
	split_chunk_bottom(A, B, output, 2);
	// (*output)->median = get_three_median(B, 2, 1);
	// split_chunk_top(A, B, output, 2);
	// decending_from_bottom(A, B, output, 2);
	decending_from_top(A, B, output, 2);

	finalization(A, B, output);
}

int	final_sort(t_node **A, t_node **output)
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
		if (curr->position <= c_node(*A) / 2)
			ra(A, output, 1);
		else
			rra(A, output, 1);
	}
}