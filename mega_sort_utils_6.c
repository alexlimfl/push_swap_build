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

void	decending_from_top(t_node **A, t_node **B, t_node **output, int until_chunk) //, int *chunk, int num_chunk, int until_chunk)
{
	// t_node	*curr_b;
	t_node	*tail_A;
	int		target_p_a;
	int		num_chunk;

	num_chunk = (*output)->num_chunk;
	while ((*B) != NULL && chunkID_avalable(B, until_chunk))
	{
		label_position(B);
		if (is_even(num_chunk) || until_chunk < 5)
			(*output)->curr_b = *B;
		else if (!is_even(num_chunk))
			(*output)->curr_b = double_ll_convert(B);
		target_p_a = get_target_p_A(A, (*output)->curr_b->rank);
		push_a(A, B, output, target_p_a);
		pa(A, B, output, 1);
		if (!chunkID_avalable(B, num_chunk))
			num_chunk--;
	}
}

void	decending_from_bottom(t_node **A, t_node **B, t_node **output, int until_chunk) //, int *chunk, int chunkID)
{
	// t_node *curr_b;
	t_node *tail_A;
	int target_p_a;
	int num_chunk;

	num_chunk = (*output)->num_chunk;
	while((*B) != NULL && chunkID_avalable(B, until_chunk))
	{					
		label_position(B);
		(*output)->curr_b = double_ll_convert(B);
		target_p_a =  get_target_p_A(A, (*output)->curr_b->rank);
		push_a(A, B, output, target_p_a);
		pa(A, B, output, 1);
	}
}

int get_median_rank_within_chunk(t_node **lst, int chunkID)
{
	t_node *curr;
	int total;
	int number_of_rank;

	total = 0;
	number_of_rank = 0;
	curr =  *lst;
	while(curr != NULL)
	{
		if (curr->chunk_id == chunkID)
		{
			number_of_rank += 1;
			total += curr->rank;
		}
		curr = curr->next;
	}
	return (total/number_of_rank);
}

void rotate_below_median_top(t_node **A, t_node **B, t_node **output, int chunkID)
{
	t_node *curr_b;

	while (*B != NULL && (*B)->chunk_id == chunkID && (*B)->rank <= (*output)->median)
		rb(B, output, 1);
}

void rotate_below_median_bottom(t_node **A, t_node **B, t_node **output, int chunkID)
{
	t_node *curr_b;

	curr_b = double_ll_convert(B);
	while (*B != NULL && curr_b->chunk_id == chunkID
		&& curr_b->rank <= (*output)->median)
	{
		rrb(B, output, 1);
		curr_b = double_ll_convert(B);
	}
}