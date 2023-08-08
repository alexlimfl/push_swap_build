/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mega_sort_utils_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:54:27 by folim             #+#    #+#             */
/*   Updated: 2023/08/07 23:54:28 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_target_p_a(t_node **A, int curr_B_rank)
{
	int	target_p_a;

	label_position(A);
	if ((*A) != NULL && c_n(*A) > 1)
	{
		if (curr_B_rank > get_highest_rank(A))
			target_p_a = target_a_largest_b(A, curr_B_rank);
		else if (curr_B_rank < get_lowest_rank(A))
			target_p_a = target_a_smallest_b(A, curr_B_rank);
		else
			target_p_a = target_a(A, curr_B_rank);
	}
	return (target_p_a);
}

void	top_a_one(t_node **A, t_var *op, int target_p_a, int curr_B_rank)
{
	if (curr_B_rank > get_highest_rank(A))
	{
		if (op->tail_a_p != target_p_a && target_p_a < c_n(*A) / 2)
			op->ra = 1;
		else if (op->tail_a_p != target_p_a && target_p_a >= c_n(*A) / 2)
			op->rra = 1;
		else
			op->stop = 1;
	}
	else if (curr_B_rank < get_lowest_rank(A))
	{
		if ((*A)->position != target_p_a && target_p_a <= c_n(*A) / 2)
			op->ra = 1;
		else if ((*A)->position != target_p_a && target_p_a > c_n(*A) / 2)
			op->rra = 1;
		else
			op->stop = 1;
	}
}

void	top_a_two(t_node **A, t_var *op, int target_p_a, int curr_B_rank)
{
	if (find_rank_of_position(A, target_p_a) < curr_B_rank)
	{
		if (op->tail_a_p != target_p_a && target_p_a < c_n(*A) / 2)
			op->ra = 1;
		else if (op->tail_a_p != target_p_a && target_p_a >= c_n(*A) / 2)
			op->rra = 1;
		else
			op->stop = 1;
	}
	else if (find_rank_of_position(A, target_p_a) > curr_B_rank)
	{
		if ((*A)->position != target_p_a && target_p_a <= c_n(*A) / 2)
			op->ra = 1;
		else if ((*A)->position != target_p_a && target_p_a > c_n(*A) / 2)
			op->rra = 1;
		else
			op->stop = 1;
	}
}


void	reset_op(t_var *op)
{
	op->ra = 0;
	op->rb = 0;
	op->rra = 0;
	op->rrb = 0;
}

void	push_a(t_node **A, t_node **B, t_node **otpt, int target_p_a)
{
	t_node	*tail_a;
	t_var	op;

	op.stop = 0;
	while ((*otpt)->curr_b != NULL && (*B)->rank != (*otpt)->curr_b->rank
		|| op.stop == 0)
	{
		tail_a = double_ll_convert(A);
		op.tail_a_p = tail_a->position;
		reset_op(&op);
		if ((*otpt)->curr_b != NULL && (*B)->rank != (*otpt)->curr_b->rank
			&& (*otpt)->curr_b->position <= c_n(*B) / 2)
			op.rb = 1;
		else if ((*otpt)->curr_b != NULL && (*B)->rank != (*otpt)->curr_b->rank)
			op.rrb = 1;
		if (op.stop == 0 && ((*otpt)->curr_b->rank > get_highest_rank(A)
				|| (*otpt)->curr_b->rank < get_lowest_rank(A)))
			top_a_one(A, &op, target_p_a, (*otpt)->curr_b->rank);
		else if (op.stop == 0)
			top_a_two(A, &op, target_p_a, (*otpt)->curr_b->rank);
		rotate(A, B, &op, otpt);
		reverse_rotate(A, B, &op, otpt);
	}
}