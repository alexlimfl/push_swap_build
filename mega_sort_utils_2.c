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

void	PB_multi_find_chunkID(t_node **A, t_node **B, t_node **output, t_var *c)
{
	int	position_s;

	label_position(A);
	if (ps_chk_id(A, c->c1, c->c2) <= (c_node(*A) - ps_chk_id_r(A, c->c1, c->c2)))
	{
		position_s = ps_chk_id(A, c->c1, c->c2);
		while (position_s != -1 && (*A)->position != position_s)
			ra(A, output, 1);
	}
	else if (ps_chk_id(A, c->c1, c->c2) > (c_node(*A) - ps_chk_id_r(A, c->c1, c->c2)))
	{
		position_s = ps_chk_id_r(A, c->c1, c->c2);
		while (position_s != -1 && (*A)->position != position_s)
			rra(A, output, 1);
	}
	if (position_s > 0)
		pb(A, B, output, 1);
}

void	lable_chunk(t_node **lst, t_node **output)
{
	t_node	*curr;
	int		i;

	i = 0;
	while (i < (*output)->num_chunk)
	{
		curr = *lst;
		while (curr != NULL)
		{
			if (va_wi_ch_av(lst, (*output)->outer_chunk, i)
				&& curr->rank > ((*output)->outer_chunk[i])
				&& curr->rank <= (*output)->outer_chunk[i + 1])
				curr->chunk_id = i + 1;
			curr = curr->next;
		}
		if (curr == NULL)
			i++;
	}
}

void	rotate(t_node **A, t_node **B, t_var *op, t_node **output)//, int RA, int RB)
{
	if(op->ra == 1 && op->rb == 1)
		rr(A, B, output, 1);
	else if(op->ra == 1 && op->rb == 0)
		ra(A, output, 1);
	else if(op->ra == 0 && op->rb == 1)
		rb(B, output, 1);
}

void	reverse_rotate(t_node **A, t_node **B, t_var *op, t_node **output)//, int RRA, int RRB)
{
	if(op->rra == 1 && op->rrb == 1)
		rrr(A, B, output, 1);
	else if(op->rra == 1 && op->rrb == 0)
		rra(A, output, 1);
	else if(op->rra == 0 && op->rrb == 1)
		rrb(B, output, 1);
}

int		check_sorted_h_tail(t_node **lst)
{
	t_node *curr;
	int before;

	curr = (*lst)->next;
	before = (*lst)->x;	
	while(curr != NULL)
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