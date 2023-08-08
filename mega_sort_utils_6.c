/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mega_sort_utils_6.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:57:21 by folim             #+#    #+#             */
/*   Updated: 2023/08/07 23:57:25 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	decend_top(t_node **a, t_node **b, t_node **otpt, int until_chunk)
{
	t_node	*tail_a;
	int		target_p_a;
	int		num_chunk;

	num_chunk = (*otpt)->num_chunk;
	while ((*b) != NULL && chunkid_avalable(b, until_chunk))
	{
		label_position(b);
		if (is_even(num_chunk) || until_chunk < 5)
			(*otpt)->curr_b = *b;
		else if (!is_even(num_chunk))
			(*otpt)->curr_b = double_ll_convert(b);
		target_p_a = get_target_p_a(a, (*otpt)->curr_b->rank);
		push_a(a, b, otpt, target_p_a);
		pa(a, b, otpt, 1);
		if (!chunkid_avalable(b, num_chunk))
			num_chunk--;
	}
}

void	decending_bot(t_node **a, t_node **b, t_node **otpt, int until_chunk)
{
	t_node	*tail_a;
	int		target_p_a;
	int		num_chunk;

	num_chunk = (*otpt)->num_chunk;
	while ((*b) != NULL && chunkid_avalable(b, until_chunk))
	{					
		label_position(b);
		(*otpt)->curr_b = double_ll_convert(b);
		target_p_a = get_target_p_a(a, (*otpt)->curr_b->rank);
		push_a(a, b, otpt, target_p_a);
		pa(a, b, otpt, 1);
	}
}

int	get_median_rank_within_chunk(t_node **lst, int chunkid)
{
	t_node	*curr;
	int		total;
	int		number_of_rank;

	total = 0;
	number_of_rank = 0;
	curr = *lst;
	while (curr != NULL)
	{
		if (curr->chunk_id == chunkid)
		{
			number_of_rank += 1;
			total += curr->rank;
		}
		curr = curr->next;
	}
	return (total / number_of_rank);
}

void	rot_b_median_top(t_node **a, t_node **b, t_node **otpt, int chunkid)
{
	t_node	*curr_b;

	while (*b != NULL && (*b)->chunk_id == chunkid
		&& (*b)->rank <= (*otpt)->median)
		rb(a, b, otpt, 1);
}

void	rot_b_median_bot(t_node **a, t_node **b, t_node **otpt, int chunkid)
{
	t_node	*curr_b;

	curr_b = double_ll_convert(b);
	while (*b != NULL && curr_b->chunk_id == chunkid
		&& curr_b->rank <= (*otpt)->median)
	{
		rrb(a, b, otpt, 1);
		curr_b = double_ll_convert(b);
	}
}