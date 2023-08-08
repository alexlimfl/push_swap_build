/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mega_sort_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:53:09 by folim             #+#    #+#             */
/*   Updated: 2023/08/07 23:53:10 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_m_f_cid(t_node **A, t_node **B, t_node **otpt, t_var *c)
{
	int	position_s;

	label_position(A);
	if (ps_c_id(A, c->c1, c->c2) <= (c_n(*A) - ps_c_id_r(A, c->c1, c->c2)))
	{
		position_s = ps_c_id(A, c->c1, c->c2);
		while (position_s != -1 && (*A)->position != position_s)
			ra(A, otpt, 1);
	}
	else if (ps_c_id(A, c->c1, c->c2) > (c_n(*A) - ps_c_id_r(A, c->c1, c->c2)))
	{
		position_s = ps_c_id_r(A, c->c1, c->c2);
		while (position_s != -1 && (*A)->position != position_s)
			rra(A, otpt, 1);
	}
	if (position_s > 0)
		pb(A, B, otpt, 1);
}

void	lable_chunk(t_node **lst, t_node **otpt)
{
	t_node	*curr;
	int		i;

	i = 0;
	while (i < (*otpt)->num_chunk)
	{
		curr = *lst;
		while (curr != NULL)
		{
			if (va_wi_ch_av(lst, (*otpt)->outer_chunk, i)
				&& curr->rank > ((*otpt)->outer_chunk[i])
				&& curr->rank <= (*otpt)->outer_chunk[i + 1])
				curr->chunk_id = i + 1;
			curr = curr->next;
		}
		if (curr == NULL)
			i++;
	}
}

void	rotate(t_node **A, t_node **B, t_var *op, t_node **otpt)
{
	if (op->ra == 1 && op->rb == 1)
		rr(A, B, otpt, 1);
	else if (op->ra == 1 && op->rb == 0)
		ra(A, otpt, 1);
	else if (op->ra == 0 && op->rb == 1)
		rb(B, otpt, 1);
}

void	reverse_rotate(t_node **A, t_node **B, t_var *op, t_node **otpt)
{
	if (op->rra == 1 && op->rrb == 1)
		rrr(A, B, otpt, 1);
	else if (op->rra == 1 && op->rrb == 0)
		rra(A, otpt, 1);
	else if (op->rra == 0 && op->rrb == 1)
		rrb(B, otpt, 1);
}

int	check_sorted_h_tail(t_node **lst)
{
	t_node	*curr;
	int		before;

	curr = (*lst)->next;
	before = (*lst)->x;
	while (curr != NULL)
	{

		if (curr->x >= before)
		{
			before = curr->x;
			curr = curr->next;
		}
		else
		{
			curr->sorted_h_tail = 1;
			before = curr->x;
			curr = curr->next;
		}
	}
	return (1);
}