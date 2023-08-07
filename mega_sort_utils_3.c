/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mega_sort_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:54:09 by folim             #+#    #+#             */
/*   Updated: 2023/08/07 23:54:11 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_top_chunk_attach(t_node **A, t_node **B, t_var *r, t_node **output)
{
	while ((va_wi_ch_av(A, (*output)->outer_chunk, r->i) ||
			va_wi_ch_av(A, (*output)->outer_chunk, (r->i + 1))) && c_node(*A) > 3)
	{
		r->ra = 0;
		r->rb = 0;
		if((*A)->chunk_id >= (*B)->chunk_id &&
			((*A)->chunk_id == (r->i+1) || (*A)->chunk_id == (r->i+2)))
		{
			pb(A, B, output, 1);
			if((*B)->chunk_id == (r->i + 1))
				r->rb = 1;
		}
		else if((*A)->chunk_id < (*B)->chunk_id &&
				((*A)->chunk_id == (r->i + 1) || (*A)->chunk_id == (r->i + 2)))
		{
			pb(A, B, output, 1);
			r->rb = 1;
		}
		if((*A) != NULL && (*A)->chunk_id != (r->i + 1) && (*A)->chunk_id != (r->i + 2))
			r->ra = 1;
			rotate(A, B, r, output);
	}
}

void	push_top_chunk(t_node **A, t_node **B, t_var *r, t_node **output)
{
	t_var c;

	c.c1 = 1;
	c.c2 = 2;
	while (c_node(*B) < 2)
		PB_multi_find_chunkID(A, B, output, &c);
	r->i = 0;
	while (r->i <= ((*output)->num_chunk - 2) && c_node(*A) > 3)
	{
		push_top_chunk_attach(A, B, r, output);
		r->i += 2;
	}
	tiny_sort(A, output);
}

void	inner_chunk_maker(t_node **output, int nn)
{
	int D;
	int i;
	float numerator;

	D = ((*output)->num_chunk * 6.2);
	numerator = 1;
	(*output)->inner_chunk[0] = 0;
	i = 1;
	while(numerator <= D)
	{
		(*output)->inner_chunk[i] = (numerator/D)*nn;
		i++;
		numerator++;
	}
}

void	outer_chunk_maker(t_node **output, int nn)
{
	float numerator;
	int i;
	int section[11];

	section[0] = 0;
	section[1] = 16;
	section[2] = 32;
	section[3] = 40;
	section[4] = 48;
	section[5] = 52;
	section[6] = 56;
	section[7] = 58;
	section[8] = 60;
	section[9] = 61;
	section[10] = 62;
	numerator = 1;
	(*output)->outer_chunk[0] = 0;
	i = 1;
	while(numerator <= (*output)->num_chunk)
	{
		(*output)->outer_chunk[i] = (*output)->inner_chunk[section[i]];
		i++;
		numerator++;
	}
}

int target_A_largest_B(t_node **A, int rank_b)
{
	t_node *curr_A;
	int highest_rank;
	int lowest_rank;

	// label_position(A);
	highest_rank = get_highest_rank(A);
	lowest_rank = get_lowest_rank(A);
	if(rank_b > highest_rank)
	{
		while(highest_rank >= lowest_rank)
		{
			curr_A = *A;
			while(curr_A != NULL)
			{
				if(curr_A->rank == rank_b)
					return (curr_A->position);
				curr_A = curr_A->next;
			}
			rank_b--;
		}
	}
	return (-1);
}