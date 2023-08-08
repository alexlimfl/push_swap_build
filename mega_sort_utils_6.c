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

void	decend_top(t_node **A, t_node **B, t_node **otpt, int until_chunk)
{
	t_node	*tail_a;
	int		target_p_a;
	int		num_chunk;

	num_chunk = (*otpt)->num_chunk;
	while ((*B) != NULL && chunkid_avalable(B, until_chunk))
	{
		label_position(B);
		if (is_even(num_chunk) || until_chunk < 5)
			(*otpt)->curr_b = *B;
		else if (!is_even(num_chunk))
			(*otpt)->curr_b = double_ll_convert(B);
		target_p_a = get_target_p_a(A, (*otpt)->curr_b->rank);
		push_a(A, B, otpt, target_p_a);
		pa(A, B, otpt, 1);
		if (!chunkid_avalable(B, num_chunk))
			num_chunk--;
	}
}

void	decending_bot(t_node **A, t_node **B, t_node **otpt, int until_chunk)
{
	t_node	*tail_a;
	int		target_p_a;
	int		num_chunk;

	num_chunk = (*otpt)->num_chunk;
	while ((*B) != NULL && chunkid_avalable(B, until_chunk))
	{					
		label_position(B);
		(*otpt)->curr_b = double_ll_convert(B);
		target_p_a = get_target_p_a(A, (*otpt)->curr_b->rank);
		push_a(A, B, otpt, target_p_a);
		pa(A, B, otpt, 1);
	}
}

int	get_median_rank_within_chunk(t_node **lst, int chunkID)
{
	t_node	*curr;
	int		total;
	int		number_of_rank;

	total = 0;
	number_of_rank = 0;
	curr = *lst;
	while (curr != NULL)
	{
		if (curr->chunk_id == chunkID)
		{
			number_of_rank += 1;
			total += curr->rank;
		}
		curr = curr->next;
	}
	return (total / number_of_rank);
}

void	rot_b_median_top(t_node **A, t_node **B, t_node **otpt, int chunkID)
{
	t_node	*curr_b;

	while (*B != NULL && (*B)->chunk_id == chunkID
		&& (*B)->rank <= (*otpt)->median)
		rb(B, otpt, 1);
}

void	rot_b_median_bot(t_node **A, t_node **B, t_node **otpt, int chunkID)
{
	t_node	*curr_b;

	curr_b = double_ll_convert(B);
	while (*B != NULL && curr_b->chunk_id == chunkID
		&& curr_b->rank <= (*otpt)->median)
	{
		rrb(B, otpt, 1);
		curr_b = double_ll_convert(B);
	}
}