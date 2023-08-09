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

void	push_top_chunk_attach(t_node **a, t_node **b, t_var *r, t_node **otpt)
{
	while ((va_wi_ch_av(a, (*otpt)->outer_chunk, r->i)
			|| va_wi_ch_av(a, (*otpt)->outer_chunk, (r->i + 1))) && c_n(*a) > 3)
	{
		r->ra = 0;
		r->rb = 0;
		if ((*a)->chunk_id >= (*b)->chunk_id
			&& ((*a)->chunk_id == (r->i + 1) || (*a)->chunk_id == (r->i + 2)))
		{
			pb(a, b, otpt, 1);
			if ((*b)->chunk_id == (r->i + 1))
				r->rb = 1;
		}
		else if ((*a)->chunk_id < (*b)->chunk_id
			&& ((*a)->chunk_id == (r->i + 1) || (*a)->chunk_id == (r->i + 2)))
		{
			pb(a, b, otpt, 1);
			r->rb = 1;
		}
		if ((*a) != NULL && (*a)->chunk_id != (r->i + 1)
			&& (*a)->chunk_id != (r->i + 2))
			r->ra = 1;
		rotate(a, b, r, otpt);
	}
}

void	push_top_chunk(t_node **a, t_node **b, t_var *r, t_node **otpt)
{
	t_var	c;

	c.c1 = 1;
	c.c2 = 2;
	while (c_n(*b) < 2)
		pb_m_f_cid(a, b, otpt, &c);
	r->i = 0;
	while (r->i <= ((*otpt)->num_chunk - 2) && c_n(*a) > 3)
	{
		push_top_chunk_attach(a, b, r, otpt);
		r->i += 2;
	}
	tiny_sort(a, b, otpt);
}

void	inner_chunk_maker(t_node **otpt, int nn)
{
	int		d;
	int		i;
	float	numerator;

	d = ((*otpt)->num_chunk * 6.2);
	numerator = 1;
	(*otpt)->inner_chunk[0] = 0;
	i = 1;
	while (numerator <= d)
	{
		(*otpt)->inner_chunk[i] = (numerator / d) * nn;
		i++;
		numerator++;
	}
}

void	outer_chunk_maker(t_node **otpt, int nn)
{
	float	numerator;
	int		i;
	int		section[11];

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
	(*otpt)->outer_chunk[0] = 0;
	i = 1;
	while (numerator <= (*otpt)->num_chunk)
	{
		(*otpt)->outer_chunk[i] = (*otpt)->inner_chunk[section[i]];
		i++;
		numerator++;
	}
}

int	target_a_largest_b(t_node **a, int rank_b)
{
	int		highest_rank;
	int		lowest_rank;
	t_node	*curr_a;

	highest_rank = get_highest_rank(a);
	lowest_rank = get_lowest_rank(a);
	if (rank_b > highest_rank)
	{
		while (highest_rank >= lowest_rank)
		{
			curr_a = *a;
			while (curr_a != NULL)
			{
				if (curr_a->rank == rank_b)
					return (curr_a->position);
				curr_a = curr_a->next;
			}
			rank_b--;
		}
	}
	return (-1);
}
