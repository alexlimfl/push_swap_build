/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mega_sort_utils_7.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:57:31 by folim             #+#    #+#             */
/*   Updated: 2023/08/07 23:57:33 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_chunk_top(t_node **A, t_node **B, t_node **output, int chunkID)
{
	int		target_p_a;

	label_position(A);
	label_position(B);
	while ((*B) != NULL && (*B)->chunk_id == chunkID)
	{
		rotate_below_median_top(A, B, output, chunkID);
		if ((*B)->chunk_id == chunkID)
		{
			target_p_a =  get_target_p_A(A, (*B)->rank);
			(*output)->curr_b = *B;
			push_a(A, B, output, target_p_a);
			pa(A, B, output, 1);
		}
	}
}

int	split_chunk_bottom(t_node **A, t_node **B, t_node **output, int chunkID)
{
	int		target_p_a;

	label_position(A);
	label_position(B);
	(*output)->curr_b = double_ll_convert(B);
	while ((*B) != NULL && (*output)->curr_b->chunk_id == chunkID)
	{
		(*output)->curr_b = double_ll_convert(B);
		rotate_below_median_bottom(A, B, output, chunkID);
		(*output)->curr_b = double_ll_convert(B);
		if ((*output)->curr_b->chunk_id == chunkID)
		{
			target_p_a = get_target_p_A(A, (*output)->curr_b->rank);
			push_a(A, B, output, target_p_a);
			pa(A, B, output, 1);
		}
		(*output)->curr_b = double_ll_convert(B);
	}
}


int ghighest_rankwithin_chunk(t_node **lst, int chunkID)
{
	t_node	*curr;
	int		highest;

	highest = (*lst)->rank;
	curr = (*lst)->next;
	while (curr != NULL)
	{
		if (curr->chunk_id == chunkID && curr->rank > highest)
				highest = curr->rank;
		curr = curr->next;
	}
	return (highest);
}

int glowest_rankwithin_chunk(t_node **lst, int chunkID)
{
	t_node	*curr;
	int		lowest;

	lowest = (*lst)->rank;
	curr = (*lst)->next;
	while (curr != NULL)
	{
		if (curr->chunk_id == chunkID && curr->rank < lowest)
				lowest = curr->rank;
		curr = curr->next;
	}
	return (lowest);
}

int	get_three_median(t_node **B, int chunkID, int choose)
{
	t_node	*curr_b;
	int		m1;
	int		m2;
	int		m3;

	m2 = get_median_rank_within_chunk(B, chunkID);
	m1 = ((m2 + glowest_rankwithin_chunk(B, chunkID)) / 2);
	m3 = ((m2 + ghighest_rankwithin_chunk(B, chunkID)) / 2);
	if (choose == 1)
		return (m1);
	else if (choose == 2)
		return (m2);
	else
		return (m3);
}