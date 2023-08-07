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

int	get_target_p_A(t_node **A, int curr_B_rank)
{
	int	target_p_a;

	label_position(A);
	if ((*A) != NULL && c_node(*A) > 1)
	{
		if (curr_B_rank > get_highest_rank(A))
			target_p_a = target_A_largest_B(A, curr_B_rank);
		else if (curr_B_rank < get_lowest_rank(A))
			target_p_a = target_A_smallest_B(A, curr_B_rank);
		else
			target_p_a = target_A(A, curr_B_rank);
	}
	return (target_p_a);
}

void top_A_one(t_node **A, t_var *op, int target_p_a, int curr_B_rank) //, int tail_A_position, t_var *op)//int *RA, int *RRA, int *stop)
{
	if (curr_B_rank > get_highest_rank(A))
	{
		if (op->tail_a_p != target_p_a && target_p_a < c_node(*A) / 2)
			op->ra = 1;
		else if (op->tail_a_p != target_p_a && target_p_a >= c_node(*A) / 2)
			op->rra = 1;
		else
			op->stop = 1;
	}
	else if (curr_B_rank < get_lowest_rank(A))
	{
		if ((*A)->position != target_p_a && target_p_a <= c_node(*A) / 2)
			op->ra = 1;
		else if ((*A)->position != target_p_a && target_p_a > c_node(*A) / 2)
			op->rra = 1;
		else
			op->stop = 1;
	}
}

void top_A_two(t_node **A, t_var *op, int target_p_a, int curr_B_rank)
{
	if (find_rank_of_position(A, target_p_a) < curr_B_rank)
	{
		if (op->tail_a_p != target_p_a && target_p_a < c_node(*A) / 2)
			op->ra = 1;
		else if (op->tail_a_p != target_p_a && target_p_a >= c_node(*A) / 2)
			op->rra = 1;
		else
			op->stop = 1;
	}
	else if (find_rank_of_position(A, target_p_a) > curr_B_rank)
	{
		if ((*A)->position != target_p_a && target_p_a <= c_node(*A) / 2)
			op->ra = 1;
		else if ((*A)->position != target_p_a && target_p_a > c_node(*A) / 2)
			op->rra = 1;
		else
			op->stop = 1;
	}
}


void reset_op(t_var *op)
{
	op->ra = 0;
	op->rb = 0;
	op->rra = 0;
	op->rrb = 0;
}

void push_a(t_node **A, t_node **B, t_node **output, int target_p_a)
{
	t_node	*tail_A;
	t_var	op;

	op.stop = 0;
	while((*output)->curr_b != NULL && (*B)->rank != (*output)->curr_b->rank || op.stop == 0)
	{
		tail_A = double_ll_convert(A);
		op.tail_a_p = tail_A->position;
		reset_op(&op);
		if ((*output)->curr_b != NULL && (*B)->rank != (*output)->curr_b->rank && (*output)->curr_b->position <= c_node(*B) / 2)
			op.rb = 1;
		else if ((*output)->curr_b != NULL && (*B)->rank != (*output)->curr_b->rank)
			op.rrb = 1;
		if (op.stop == 0 && ((*output)->curr_b->rank > get_highest_rank(A) || (*output)->curr_b->rank < get_lowest_rank(A)))
			top_A_one(A, &op, target_p_a, (*output)->curr_b->rank);
		else if (op.stop == 0)
			top_A_two(A, &op, target_p_a, (*output)->curr_b->rank); //, tail_A->position, &op);// RA, RRA, &stop);
		rotate(A, B, &op, output);//, op.ra, op.rb);
		reverse_rotate(A, B, &op, output);//, op.rra, op.rrb);
	}
}