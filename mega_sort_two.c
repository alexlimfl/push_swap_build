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



// int	ps_w_chk(t_node **A, int *chunk, int i)
// {
// 	t_node *curr;

// 	curr = *A;
// 	while (curr != NULL)
// 	{
// 		if (curr->rank > (chunk[i]) && curr->rank <= chunk[i + 1])
// 			return (curr->position);
// 		curr = curr->next;
// 	}
// 	return (-1);
// }

// int	ps_w_chk_r(t_node **A, int *chunk, int i)
// {
// 	t_node	*curr;

// 	curr = double_ll_convert(A);
// 	while (curr != NULL)
// 	{
// 		if (curr->rank > (chunk[i]) && curr->rank <= chunk[i + 1])
// 			return (curr->position);
// 		curr = curr->prev;
// 	}
// 	return (-1);
// }






// void	push_A_single_way_find(t_node **A, t_node **B, t_node **output, int *chunk, int i)
// {
// 	int	position_s;

// 	label_position(A);
// 	position_s = ps_w_chk(A, chunk, i);
// 	if (position_s > 0)
// 	{
// 		while (position_s != -1 && (*A)->position != position_s)
// 			ra(A, output, 1);
// 		pb(A, B, output, 1);
// 	}
// }

// int	push_B_multi_way_find(t_node **A, t_node **B, t_node **output, int *chunk, int i)
// {
// 	int	position_s;

// 	label_position(A);
// 	if (ps_w_chk(A, chunk, i) + ps_w_chk_r(A, chunk, i) > 0)
// 	{
// 		if (ps_w_chk(A, chunk, i) <= (c_node(*A) - ps_w_chk_r(A, chunk, i)))
// 		{
// 			position_s = ps_w_chk(A, chunk, i);
// 			while (position_s != -1 && (*A)->position != position_s)
// 				ra(A, output, 1);
// 		}
// 		else if (ps_w_chk(A, chunk, i) > (c_node(*A) - ps_w_chk_r(A, chunk, i)))
// 		{
// 			position_s = ps_w_chk_r(A, chunk, i);
// 			while (position_s != -1 && (*A)->position != position_s)
// 				rra(A, output, 1);
// 		}
// 		if (position_s > 0)
// 			pb(A, B, output, 1);
// 	}
// }













/////////////////////////////////////////////////////////////////////////////////

int c_node_wc(t_node *lst, int chunkID)
{
	int count;
	t_node *curr;
	count = 0;
	curr = lst;
	while(curr != NULL)
	{
		if (curr->chunk_id == chunkID)
			count++;
		curr = curr->next;
	}
	// ft_printf("Number of node(s) in linked list: %d\n", count);
	return (count);
}

int	 get_four_median(t_node **B, int chunkID, int choose)
{
	t_node	*curr_b;
	int m1;
	int m2;
	int m3;
	int m4;
	int n_bound;

	// count numbers of values withinchunk
	n_bound = c_node_wc(*B, chunkID) / 5;
	m1 = glowest_rankwithin_chunk(B, chunkID) + n_bound;
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






// Stack A will rotate, if value on top is within current and the next chunks. Ready to PA.
// Stack B will check which chunk the top value of Stack A is, will rotate accordingly.
// If chunk on top B is same with on top A, Push B.
// If chunk on top B is not same with on top A, 
// Objective, make sure chunk 1 and chunk 2 doesn't overlap.
// Check if on top Stack B and the next, if same just push, not same rotate.






