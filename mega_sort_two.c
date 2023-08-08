/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mega_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:09:39 by folim             #+#    #+#             */
/*   Updated: 2023/07/26 21:09:40 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



// int	ps_w_chk(t_node **a, int *chunk, int i)
// {
// 	t_node *curr;

// 	curr = *a;
// 	while (curr != NULL)
// 	{
// 		if (curr->rank > (chunk[i]) && curr->rank <= chunk[i + 1])
// 			return (curr->position);
// 		curr = curr->next;
// 	}
// 	return (-1);
// }

// int	ps_w_chk_r(t_node **a, int *chunk, int i)
// {
// 	t_node	*curr;

// 	curr = double_ll_convert(a);
// 	while (curr != NULL)
// 	{
// 		if (curr->rank > (chunk[i]) && curr->rank <= chunk[i + 1])
// 			return (curr->position);
// 		curr = curr->prev;
// 	}
// 	return (-1);
// }






// void	pa_s_w_f(t_node **a, t_node **b, t_node **otpt, int *chunk, int i)
// {
// 	int	position_s;

// 	label_position(a);
// 	position_s = ps_w_chk(a, chunk, i);
// 	if (position_s > 0)
// 	{
// 		while (position_s != -1 && (*a)->position != position_s)
// 			ra(a, b, otpt, 1);
// 		pb(a, b, otpt, 1);
// 	}
// }

// int	pb_m_w_f(t_node **a, t_node **b, t_node **otpt, int *chunk, int i)
// {
// 	int	position_s;

// 	label_position(a);
// 	if (ps_w_chk(a, chunk, i) + ps_w_chk_r(a, chunk, i) > 0)
// 	{
// 		if (ps_w_chk(a, chunk, i) <= (c_n(*a) - ps_w_chk_r(a, chunk, i)))
// 		{
// 			position_s = ps_w_chk(a, chunk, i);
// 			while (position_s != -1 && (*a)->position != position_s)
// 				ra(a, b, otpt, 1);
// 		}
// 		else if (ps_w_chk(a, chunk, i) > (c_n(*a) - ps_w_chk_r(a, chunk, i)))
// 		{
// 			position_s = ps_w_chk_r(a, chunk, i);
// 			while (position_s != -1 && (*a)->position != position_s)
// 				rra(a, b, otpt, 1);
// 		}
// 		if (position_s > 0)
// 			pb(a, b, otpt, 1);
// 	}
// }













/////////////////////////////////////////////////////////////////////////////////

int c_node_wc(t_node *lst, int chunkid)
{
	int count;
	t_node *curr;
	count = 0;
	curr = lst;
	while (curr != NULL)
	{
		if (curr->chunk_id == chunkid)
			count++;
		curr = curr->next;
	}
	// ft_printf("Number of node(s) in linked list: %d\n", count);
	return (count);
}

int	 get_four_median(t_node **b, int chunkid, int choose)
{
	t_node	*curr_b;
	int m1;
	int m2;
	int m3;
	int m4;
	int n_bound;

	// count numbers of values withinchunk
	n_bound = c_node_wc(*b, chunkid) / 5;
	m1 = glowest_rankwithin_chunk(b, chunkid) + n_bound;
	m2 = m1 + n_bound;
	m3 = m2 + n_bound;
	m4 = m3 + n_bound;
	if (choose == 1)
		return (m1);
	if (choose == 2)
		return (m2);
	if (choose == 3)
		return (m3);
	if (choose == 4)
		return (m4);
}
///////////////////////////////////////////////////////






// Stack a will rotate, if value on top is within current and the next chunks. Ready to PA.
// Stack b will check which chunk the top value of Stack a is, will rotate accordingly.
// If chunk on top b is same with on top a, Push b.
// If chunk on top b is not same with on top a, 
// Objective, make sure chunk 1 and chunk 2 doesn't overlap.
// Check if on top Stack b and the next, if same just push, not same rotate.






