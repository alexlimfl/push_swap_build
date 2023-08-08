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

int	get_target_p_a(t_node **a, int curr_B_rank)
{
	int	target_p_a;

	label_position(a);
	if ((*a) != NULL && c_n(*a) > 1)
	{
		if (curr_B_rank > get_highest_rank(a))
			target_p_a = target_a_largest_b(a, curr_B_rank);
		else if (curr_B_rank < get_lowest_rank(a))
			target_p_a = target_a_smallest_b(a, curr_B_rank);
		else
			target_p_a = target_a(a, curr_B_rank);
	}
	return (target_p_a);
}

void	top_a_one(t_node **a, t_var *op, int target_p_a, int curr_B_rank)
{
	if (curr_B_rank > get_highest_rank(a))
	{
		if (op->tail_a_p != target_p_a && target_p_a < c_n(*a) / 2)
			op->ra = 1;
		else if (op->tail_a_p != target_p_a && target_p_a >= c_n(*a) / 2)
			op->rra = 1;
		else
			op->stop = 1;
	}
	else if (curr_B_rank < get_lowest_rank(a))
	{
		if ((*a)->position != target_p_a && target_p_a <= c_n(*a) / 2)
			op->ra = 1;
		else if ((*a)->position != target_p_a && target_p_a > c_n(*a) / 2)
			op->rra = 1;
		else
			op->stop = 1;
	}
}

void	top_a_two(t_node **a, t_var *op, int target_p_a, int curr_B_rank)
{
	if (find_rank_of_position(a, target_p_a) < curr_B_rank)
	{
		if (op->tail_a_p != target_p_a && target_p_a < c_n(*a) / 2)
			op->ra = 1;
		else if (op->tail_a_p != target_p_a && target_p_a >= c_n(*a) / 2)
			op->rra = 1;
		else
			op->stop = 1;
	}
	else if (find_rank_of_position(a, target_p_a) > curr_B_rank)
	{
		if ((*a)->position != target_p_a && target_p_a <= c_n(*a) / 2)
			op->ra = 1;
		else if ((*a)->position != target_p_a && target_p_a > c_n(*a) / 2)
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

void	push_a(t_node **a, t_node **b, t_node **otpt, int target_p_a)
{
	t_node	*tail_a;
	t_var	op;

	op.stop = 0;
	while ((*otpt)->curr_b != NULL && (*b)->rank != (*otpt)->curr_b->rank
		|| op.stop == 0)
	{
		tail_a = double_ll_convert(a);
		op.tail_a_p = tail_a->position;
		reset_op(&op);
		if ((*otpt)->curr_b != NULL && (*b)->rank != (*otpt)->curr_b->rank
			&& (*otpt)->curr_b->position <= c_n(*b) / 2)
			op.rb = 1;
		else if ((*otpt)->curr_b != NULL && (*b)->rank != (*otpt)->curr_b->rank)
			op.rrb = 1;
		if (op.stop == 0 && ((*otpt)->curr_b->rank > get_highest_rank(a)
				|| (*otpt)->curr_b->rank < get_lowest_rank(a)))
			top_a_one(a, &op, target_p_a, (*otpt)->curr_b->rank);
		else if (op.stop == 0)
			top_a_two(a, &op, target_p_a, (*otpt)->curr_b->rank);
		rotate(a, b, &op, otpt);
		reverse_rotate(a, b, &op, otpt);
	}
}