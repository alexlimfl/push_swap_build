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

void	pb_m_f_cid(t_node **a, t_node **b, t_node **otpt, t_var *c)
{
	int	position_s;

	label_position(a);
	if (ps_c_id(a, c->c1, c->c2) <= (c_n(*a) - ps_c_id_r(a, c->c1, c->c2)))
	{
		position_s = ps_c_id(a, c->c1, c->c2);
		while (position_s != -1 && (*a)->position != position_s)
			ra(a, b, otpt, 1);
	}
	else if (ps_c_id(a, c->c1, c->c2) > (c_n(*a) - ps_c_id_r(a, c->c1, c->c2)))
	{
		position_s = ps_c_id_r(a, c->c1, c->c2);
		while (position_s != -1 && (*a)->position != position_s)
			rra(a, b, otpt, 1);
	}
	if (position_s > 0)
		pb(a, b, otpt, 1);
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

void	rotate(t_node **a, t_node **b, t_var *op, t_node **otpt)
{
	if (op->ra == 1 && op->rb == 1)
		rr(a, b, otpt, 1);
	else if (op->ra == 1 && op->rb == 0)
		ra(a, b, otpt, 1);
	else if (op->ra == 0 && op->rb == 1)
		rb(a, b, otpt, 1);
}

void	reverse_rotate(t_node **a, t_node **b, t_var *op, t_node **otpt)
{
	if (op->rra == 1 && op->rrb == 1)
		rrr(a, b, otpt, 1);
	else if (op->rra == 1 && op->rrb == 0)
		rra(a, b, otpt, 1);
	else if (op->rra == 0 && op->rrb == 1)
		rrb(a, b, otpt, 1);
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
