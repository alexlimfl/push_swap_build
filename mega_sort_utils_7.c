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

void	split_chunk_top(t_node **a, t_node **b, t_node **otpt, int chunkid)
{
	int		target_p_a;

	label_position(a);
	label_position(b);
	while ((*b) != NULL && (*b)->chunk_id == chunkid)
	{
		rot_b_median_top(a, b, otpt, chunkid);
		if ((*b)->chunk_id == chunkid)
		{
			target_p_a = get_target_p_a(a, (*b)->rank);
			(*otpt)->curr_b = *b;
			push_a(a, b, otpt, target_p_a);
			pa(a, b, otpt, 1);
		}
	}
}

void	split_chunk_bottom(t_node **a, t_node **b, t_node **otpt, int chunkid)
{
	int		target_p_a;

	label_position(a);
	label_position(b);
	(*otpt)->curr_b = double_ll_convert(b);
	while ((*b) != NULL && (*otpt)->curr_b->chunk_id == chunkid)
	{
		(*otpt)->curr_b = double_ll_convert(b);
		rot_b_median_bot(a, b, otpt, chunkid);
		(*otpt)->curr_b = double_ll_convert(b);
		if ((*otpt)->curr_b->chunk_id == chunkid)
		{
			target_p_a = get_target_p_a(a, (*otpt)->curr_b->rank);
			push_a(a, b, otpt, target_p_a);
			pa(a, b, otpt, 1);
		}
		(*otpt)->curr_b = double_ll_convert(b);
	}
}


int	ghighest_rankwithin_chunk(t_node **lst, int chunkid)
{
	t_node	*curr;
	int		highest;

	highest = (*lst)->rank;
	curr = (*lst)->next;
	while (curr != NULL)
	{
		if (curr->chunk_id == chunkid && curr->rank > highest)
				highest = curr->rank;
		curr = curr->next;
	}
	return (highest);
}

int	glowest_rankwithin_chunk(t_node **lst, int chunkid)
{
	t_node	*curr;
	int		lowest;

	lowest = (*lst)->rank;
	curr = (*lst)->next;
	while (curr != NULL)
	{
		if (curr->chunk_id == chunkid && curr->rank < lowest)
				lowest = curr->rank;
		curr = curr->next;
	}
	return (lowest);
}

int	get_three_median(t_node **b, int chunkid, int choose)
{
	int		m1;
	int		m2;
	int		m3;
	t_node	*curr_b;

	m2 = get_median_rank_within_chunk(b, chunkid);
	m1 = ((m2 + glowest_rankwithin_chunk(b, chunkid)) / 2);
	m3 = ((m2 + ghighest_rankwithin_chunk(b, chunkid)) / 2);
	if (choose == 1)
		return (m1);
	else if (choose == 2)
		return (m2);
	else
		return (m3);
}