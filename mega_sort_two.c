/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mega_sort_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:09:39 by folim             #+#    #+#             */
/*   Updated: 2023/07/26 21:09:40 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	view_chunk(int *chunk, int num_chunk)
{
	int	i;

	i = 0;
	while (i <= num_chunk)
	{
		printf("%d\n", chunk[i]);
		i++;
	}
}

int	ps_w_chk(t_node **A, int *chunk, int i)
{
	t_node *curr;

	curr = *A;
	while (curr != NULL)
	{
		if (curr->rank > (chunk[i]) && curr->rank <= chunk[i + 1])
			return (curr->position);
		curr = curr->next;
	}
	return (-1);
}

int	check_sorted_plus(t_node **A)
{
	t_node	*curr;
	int		b4;

	curr = (*A)->next;
	b4 = (*A)->rank;
	while (curr != NULL)
	{
		if (curr->rank < b4 && !(curr->rank == get_lowest_rank(A)
				&& b4 == get_highest_rank(A)))
			return (0);
		b4 = curr->rank;
		curr = curr->next;
	}
	return (1);
}

int	ps_w_chk_r(t_node **A, int *chunk, int i)
{
	t_node	*curr;

	curr = double_ll_convert(A);
	while (curr != NULL)
	{
		if (curr->rank > (chunk[i]) && curr->rank <= chunk[i + 1])
			return (curr->position);
		curr = curr->prev;
	}
	return (-1);
}

int	ps_chk_id(t_node **lst, int chunk_one, int chunk_two)
{
	t_node	*curr;

	curr = *lst;
	while (curr != NULL)
	{
		if (curr->chunk_id == chunk_one || curr->chunk_id == chunk_two)
			return (curr->position);
		curr = curr->next;
	}
	return (-1);
}

int	ps_chk_id_r(t_node **lst, int chunk_one, int chunk_two)
{
	t_node	*curr;

	curr = double_ll_convert(lst);
	while (curr != NULL)
	{
		if (curr->chunk_id == chunk_one || curr->chunk_id == chunk_two)
			return (curr->position);
		curr = curr->prev;
	}
	return (-1);
}


int	value_within_chunk_available(t_node **lst, int *chunk, int i)
{
	t_node	*curr;

	curr = *lst;
	while (curr != NULL)
	{
		if (curr->rank > (chunk[i]) && curr->rank <= chunk[i + 1])
			return (1);
		curr = curr->next;
	}
	return (0);
}

int	chunkID_avalable(t_node **lst, int id)
{
	t_node	*curr;

	curr = *lst;
	while (curr != NULL)
	{
		if (curr->chunk_id == id)
			return (1);
		curr = curr->next;
	}
	return (0);
}


void	push_A_single_way_find(t_node **A, t_node **B, t_node **output, int *chunk, int i)
{
	int	position_s;

	label_position(A);
	position_s = ps_w_chk(A, chunk, i);
	if (position_s > 0)
	{
		while (position_s != -1 && (*A)->position != position_s)
			ra(A, output, 1);
		pb(A, B, output, 1);
	}
}

int	push_B_multi_way_find(t_node **A, t_node **B, t_node **output, int *chunk, int i)
{
	int	position_s;

	label_position(A);
	if (ps_w_chk(A, chunk, i) + ps_w_chk_r(A, chunk, i) > 0)
	{
		if (ps_w_chk(A, chunk, i) <= (c_node(*A) - ps_w_chk_r(A, chunk, i)))
		{
			position_s = ps_w_chk(A, chunk, i);
			while (position_s != -1 && (*A)->position != position_s)
				ra(A, output, 1);
		}
		else if (ps_w_chk(A, chunk, i) > (c_node(*A) - ps_w_chk_r(A, chunk, i)))
		{
			position_s = ps_w_chk_r(A, chunk, i);
			while (position_s != -1 && (*A)->position != position_s)
				rra(A, output, 1);
		}
		if (position_s > 0)
			pb(A, B, output, 1);
	}
}

void	PB_multi_find_chunkID(t_node **A, t_node **B, t_node **output, int c1, int c2)
{
	int	position_s;

	label_position(A);
	if (ps_chk_id(A, c1, c2) <= (c_node(*A) - ps_chk_id_r(A, c1, c2)))
	{
		position_s = ps_chk_id(A, c1, c2);
		while (position_s != -1 && (*A)->position != position_s)
			ra(A, output, 1);
	}
	else if (ps_chk_id(A, c1, c2) > (c_node(*A) - ps_chk_id_r(A, c1, c2)))
	{
		position_s = ps_chk_id_r(A, c1, c2);
		while (position_s != -1 && (*A)->position != position_s)
			rra(A, output, 1);
	}
	if (position_s > 0)
		pb(A, B, output, 1);
}


void lable_chunk(t_node **lst, t_node **output) //, int *chunk, int num_chunk)
{
	t_node	*curr;
	int		i;

	i = 0;
	while (i < (*output)->num_chunk)
	{
		curr = *lst;
		while (curr != NULL)
		{
			if (value_within_chunk_available(lst, (*output)->outer_chunk, i)
				&& curr->rank > ((*output)->outer_chunk[i]) && curr->rank <= (*output)->outer_chunk[i + 1])
				curr->chunk_id = i + 1;
			curr = curr->next;
		}
		if (curr == NULL)
			i++;
	}
}

void rotate(t_node **A, t_node **B, t_node **output, int RA, int RB)
{
	if(RA == 1 && RB == 1)
		rr(A, B, output, 1);
	else if(RA == 1 && RB == 0)
		ra(A, output, 1);
	else if(RA == 0 && RB == 1)
		rb(B, output, 1);
}

void reverse_rotate(t_node **A, t_node **B, t_node **output, int RRA, int RRB)
{
	if(RRA == 1 && RRB == 1)
		rrr(A, B, output, 1);
	else if(RRA == 1 && RRB == 0)
		rra(A, output, 1);
	else if(RRA == 0 && RRB == 1)
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

void push_top_chunk(t_node **A, t_node **B, t_node **output) //, int *chunk, int num_chunk)
{
	int RA;
	int RB;
	int i;

	while(c_node(*B) < 2)
		PB_multi_find_chunkID(A, B, output, 1, 2);
	i = 0;
	while(i <= ((*output)->num_chunk - 2) && c_node(*A) > 3)
	{
		while((value_within_chunk_available(A, (*output)->outer_chunk, i) || value_within_chunk_available(A, (*output)->outer_chunk, (i+1))) && c_node(*A) > 3)
		{
			RA = 0;
			RB = 0;
			if((*A)->chunk_id >= (*B)->chunk_id && ((*A)->chunk_id == (i+1) || (*A)->chunk_id == (i+2)))
			{
				pb(A, B, output, 1);
				if((*B)->chunk_id == (i+1))
					RB = 1;
			}
			else if((*A)->chunk_id < (*B)->chunk_id && ((*A)->chunk_id == (i+1) || (*A)->chunk_id == (i+2)))
			{
				pb(A, B, output, 1);
				RB = 1;
			}
			if((*A) != NULL && (*A)->chunk_id != (i+1) && (*A)->chunk_id != (i+2))
				RA = 1;
				rotate(A, B, output, RA, RB);
		}
		i += 2;
	}
	tiny_sort(A, output);
	/*
	while(value_within_chunk_available(A, chunk, 0) || value_within_chunk_available(A, chunk, 1))
	{
		RA = 0;
		RB = 0;
		if((*A)->chunk_id >= (*B)->chunk_id && ((*A)->chunk_id == 1 || (*A)->chunk_id == 2))
			pb(A, B, output, 1);
		else if((*A)->chunk_id < (*B)->chunk_id && ((*A)->chunk_id == 1 || (*A)->chunk_id == 2))
		{
			pb(A, B, output, 1);
			RB = 1;

		}
		if(((*A)->chunk_id != 1 && (*A)->chunk_id != 2))
			RA = 1;
		n_op = rotate(A, B, RA, RB, n_op);
	}
	while(value_within_chunk_available(A, chunk, 2) || value_within_chunk_available(A, chunk, 3))
	{
		RA = 0;
		RB = 0;
		while(c_node(*B) < 2 && ((*A)->chunk_id == 3 || (*A)->chunk_id == 4))
			pb(A, B, output, 1);
	
		if((*A)->chunk_id >= (*B)->chunk_id && ((*A)->chunk_id == 3 || (*A)->chunk_id == 4))
			pb(A, B, output, 1);
		else if((*A)->chunk_id < (*B)->chunk_id && ((*A)->chunk_id == 3 || (*A)->chunk_id == 4))
		{
			pb(A, B, output, 1);
			RB = 1;

		}
		if(((*A)->chunk_id != 3 && (*A)->chunk_id != 4))
			RA = 1;
		n_op = rotate(A, B, RA, RB, n_op);
	}
	while(value_within_chunk_available(A, chunk, 4) || value_within_chunk_available(A, chunk, 5))
	{
		RA = 0;
		RB = 0;
		while(c_node(*B) < 2 && ((*A)->chunk_id == 5 || (*A)->chunk_id == 6))
			pb(A, B, output, 1);
	
		if((*A)->chunk_id >= (*B)->chunk_id && ((*A)->chunk_id == 5 || (*A)->chunk_id == 6))
			pb(A, B, output, 1);
		else if((*A)->chunk_id < (*B)->chunk_id && ((*A)->chunk_id == 5 || (*A)->chunk_id == 6))
		{
			pb(A, B, output, 1);
			RB = 1;

		}
		if(((*A)->chunk_id != 5 && (*A)->chunk_id != 6))
			RA = 1;
		n_op = rotate(A, B, RA, RB, n_op);
	}
	while(value_within_chunk_available(A, chunk, 6) || value_within_chunk_available(A, chunk, 7))
	{
		RA = 0;
		RB = 0;
		while(c_node(*B) < 2 && ((*A)->chunk_id == 7 || (*A)->chunk_id == 8))
			pb(A, B, output, 1);
	
		if((*A)->chunk_id >= (*B)->chunk_id && ((*A)->chunk_id == 7 || (*A)->chunk_id == 8))
			pb(A, B, output, 1);
		else if((*A)->chunk_id < (*B)->chunk_id && ((*A)->chunk_id == 7 || (*A)->chunk_id == 8))
		{
			pb(A, B, output, 1);
			RB = 1;

		}
		if(((*A)->chunk_id != 7 && (*A)->chunk_id != 8))
			RA = 1;
		n_op = rotate(A, B, RA, RB, n_op);
	}
	while(value_within_chunk_available(A, chunk, 8) || value_within_chunk_available(A, chunk, 9))
	{
		RA = 0;
		RB = 0;
		while(c_node(*B) < 2 && ((*A)->chunk_id == 9 || (*A)->chunk_id == 10))
			pb(A, B, output, 1);
	
		if((*A)->chunk_id >= (*B)->chunk_id && ((*A)->chunk_id == 9 || (*A)->chunk_id == 10))
			pb(A, B, output, 1);
		else if((*A)->chunk_id < (*B)->chunk_id && ((*A)->chunk_id == 9 || (*A)->chunk_id == 10))
		{
			pb(A, B, output, 1);
			RB = 1;
		}
		if(((*A)->chunk_id != 9 && (*A)->chunk_id != 10))
			RA = 1;
		n_op = rotate(A, B, RA, RB, n_op);
	}*/
}

void	inner_chunk_maker(t_node **output, int nn) //, int *inner_chunk, int denominator)
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


void	outer_chunk_maker(t_node **output, int nn) //, int *inner_chunk, int *outer_chunk, int denominator)
{
	float numerator;
	int i;
	int j;
	int section[] = {0, 16, 32, 40, 48, 52, 56, 58, 60, 61, 62};

	numerator = 1;
	(*output)->outer_chunk[0] = 0;
	i = 1;
	j = 1;
	while(numerator <= (*output)->num_chunk)
	{
		(*output)->outer_chunk[i] = (*output)->inner_chunk[section[j]];
		i++;
		j++;
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

int	target_A_smallest_B(t_node **A, int rank_b)
{
	t_node *curr_A;
	int highest_rank;
	int lowest_rank;

			// ft_printf("RANKB %d\n", rank_b);
	highest_rank = get_highest_rank(A);
	lowest_rank = get_lowest_rank(A);
	// label_position(A);
	if(rank_b < lowest_rank)
	{
		while(lowest_rank <= highest_rank)
		{
			curr_A = *A;
			while (curr_A != NULL)
			{
				if(curr_A->rank == rank_b)
					return (curr_A->position);
				curr_A = curr_A->next;
			}
			rank_b++;
		}
	}
	return (-1);
}

int target_A_poaition_h(t_node **A, int rank_b)
{
	t_node *curr_A;

	curr_A = *A;
	while (rank_b <= get_highest_rank(A))
	{
		curr_A = *A;
		while (curr_A != NULL)
		{
			if (curr_A->rank == rank_b)
				break ;
			curr_A = curr_A->next;
		}
		if (curr_A != NULL)
			break ;
		rank_b++;
	}
	return (curr_A->position);
}

int target_A(t_node **A, int rank_b)
{
	t_node	*curr_A;
	int		position_l;
	int		position_h;
	int		rank_b_temp;

	rank_b_temp = rank_b;
	while (rank_b >= get_lowest_rank(A))
	{
		curr_A = *A;
		while (curr_A != NULL)
		{
			if (curr_A->rank == rank_b)
				break ;
			curr_A = curr_A->next;
		}
		if (curr_A != NULL)
			break ;
		rank_b--;
	}
	position_l = curr_A->position;
	if (target_A_poaition_h(A, rank_b_temp) <= c_node(*A) - position_l)
		return (target_A_poaition_h(A, rank_b_temp));
	else if (target_A_poaition_h(A, rank_b_temp) > c_node(*A) - position_l)
		return (position_l);
	return (-1);
}

int	find_rank_of_position(t_node **lst, int position)
{
	t_node	*curr;

	curr = *lst;
	while (curr != NULL)
	{
		if (curr->position == position)
			return (curr->rank);
		curr = curr->next;
	}
	return (-1);
}

int	is_even(int num)
{
	int	value;

	value = num % 2;
	if (value == 0)
		return (1);
	return (0);
}

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

void top_A_one(t_node **A, int target_p_a, int curr_B_rank, int tail_A_position, t_var *op)//int *RA, int *RRA, int *stop)
{
	if (curr_B_rank > get_highest_rank(A))
	{
		if (tail_A_position != target_p_a && target_p_a < c_node(*A) / 2)
			op->ra = 1;
		else if (tail_A_position != target_p_a && target_p_a >= c_node(*A) / 2)
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

void top_A_two(t_node **A, int target_p_a, int curr_B_rank, int tail_A_position, t_var *op)//int *RA, int *RRA, int *stop)
{
	if (find_rank_of_position(A, target_p_a) < curr_B_rank)
	{
		if (tail_A_position != target_p_a && target_p_a < c_node(*A) / 2)
			op->ra = 1;
		else if (tail_A_position != target_p_a && target_p_a >= c_node(*A) / 2)
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

void push_a(t_node **A, t_node **B, t_node **output, t_node **curr_b, int target_p_a)
{
	t_node	*tail_A;
	t_var	op;

	op.stop = 0;
	while(*curr_b != NULL && (*B)->rank != (*curr_b)->rank || op.stop == 0)
	{
		tail_A = double_ll_convert(A);
		reset_op(&op);
		if (*curr_b != NULL && (*B)->rank != (*curr_b)->rank && (*curr_b)->position <= c_node(*B) / 2)
			op.rb = 1;
		else if (*curr_b != NULL && (*B)->rank != (*curr_b)->rank)
			op.rrb = 1;
		if (op.stop == 0 && ((*curr_b)->rank > get_highest_rank(A) || (*curr_b)->rank < get_lowest_rank(A)))
			top_A_one(A, target_p_a, (*curr_b)->rank, tail_A->position, &op);
		else if (op.stop == 0)
			top_A_two(A, target_p_a, (*curr_b)->rank, tail_A->position, &op);// RA, RRA, &stop);
		rotate(A, B, output, op.ra, op.rb);
		reverse_rotate(A, B, output, op.rra, op.rrb);
	}
}

void	decending_from_top(t_node **A, t_node **B, t_node **output, int until_chunk) //, int *chunk, int num_chunk, int until_chunk)
{
	t_node	*curr_b;
	t_node	*tail_A;
	int		target_p_a;
	int		num_chunk;

	num_chunk = (*output)->num_chunk;
	while ((*B) != NULL && chunkID_avalable(B, until_chunk))
	{
		label_position(B);
		if (is_even(num_chunk) || until_chunk < 5)
			curr_b = *B;
		else if (!is_even(num_chunk))
			curr_b = double_ll_convert(B);
		target_p_a = get_target_p_A(A, curr_b->rank);
		push_a(A, B, output, &curr_b, target_p_a);
		pa(A, B, output, 1);
		if (!chunkID_avalable(B, num_chunk))
			num_chunk--;
	}
}

void	decending_from_bottom(t_node **A, t_node **B, t_node **output, int until_chunk) //, int *chunk, int chunkID)
{
	t_node *curr_b;
	t_node *tail_A;
	int target_p_a;
	int num_chunk;

	num_chunk = (*output)->num_chunk;
	while((*B) != NULL && chunkID_avalable(B, until_chunk))
	{					
		label_position(B);
		curr_b = double_ll_convert(B);
		target_p_a =  get_target_p_A(A, curr_b->rank);
		push_a(A, B, output, &curr_b, target_p_a);
		pa(A, B, output, 1);
	}
}

int get_median_rank_within_chunk(t_node **lst, int chunkID)
{
	t_node *curr;
	int total;
	int number_of_rank;

	total = 0;
	number_of_rank = 0;
	curr =  *lst;
	while(curr != NULL)
	{
		if (curr->chunk_id == chunkID)
		{
			number_of_rank += 1;
			total += curr->rank;
		}
		curr = curr->next;
	}
	return (total/number_of_rank);
}

void rotate_below_median_top(t_node **A, t_node **B, t_node **output, int chunkID)
{
	t_node *curr_b;

	while (*B != NULL && (*B)->chunk_id == chunkID && (*B)->rank <= (*output)->median)
		rb(B, output, 1);
}

void rotate_below_median_bottom(t_node **A, t_node **B, t_node **output, int chunkID)
{
	t_node *curr_b;

	curr_b = double_ll_convert(B);
	while (*B != NULL && curr_b->chunk_id == chunkID
		&& curr_b->rank <= (*output)->median)
	{
		rrb(B, output, 1);
		curr_b = double_ll_convert(B);
	}
}

void	split_chunk_top(t_node **A, t_node **B, t_node **output, int chunkID)
{
	t_node	*curr_b;
	int		target_p_a;

	label_position(A);
	label_position(B);
	while ((*B) != NULL && (*B)->chunk_id == chunkID)
	{
		rotate_below_median_top(A, B, output, chunkID);
		if ((*B)->chunk_id == chunkID)
		{
			target_p_a =  get_target_p_A(A, (*B)->rank);
			push_a(A, B, output, B, target_p_a);
			pa(A, B, output, 1);
		}
	}
}

int	split_chunk_bottom(t_node **A, t_node **B, t_node **output, int chunkID)
{
	t_node	*tail_b;
	int		target_p_a;

	label_position(A);
	label_position(B);
	tail_b = double_ll_convert(B);
	while ((*B) != NULL && tail_b->chunk_id == chunkID)
	{
		tail_b = double_ll_convert(B);
		rotate_below_median_bottom(A, B, output, chunkID);
		tail_b = double_ll_convert(B);
		if (tail_b->chunk_id == chunkID)
		{
			target_p_a = get_target_p_A(A, tail_b->rank);
			push_a(A, B, output, &tail_b, target_p_a);
			pa(A, B, output, 1);
		}
		tail_b = double_ll_convert(B);
	}
}


int ghighest_rankwithin_chunk(t_node **lst, int chunkID)
{
	t_node	*curr;
	int		highest;

	highest = (*lst)->rank;
	curr = (*lst)->next;
	while (curr != NULL)
	{
		if (curr->chunk_id == chunkID && curr->rank > highest)
				highest = curr->rank;
		curr = curr->next;
	}
	return (highest);
}

int glowest_rankwithin_chunk(t_node **lst, int chunkID)
{
	t_node	*curr;
	int		lowest;

	lowest = (*lst)->rank;
	curr = (*lst)->next;
	while (curr != NULL)
	{
		if (curr->chunk_id == chunkID && curr->rank < lowest)
				lowest = curr->rank;
		curr = curr->next;
	}
	return (lowest);
}

int	get_three_median(t_node **B, int chunkID, int choose)
{
	t_node	*curr_b;
	int		m1;
	int		m2;
	int		m3;

	m2 = get_median_rank_within_chunk(B, chunkID);
	m1 = ((m2 + glowest_rankwithin_chunk(B, chunkID)) / 2);
	m3 = ((m2 + ghighest_rankwithin_chunk(B, chunkID)) / 2);
	if (choose == 1)
		return (m1);
	else if (choose == 2)
		return (m2);
	else
		return (m3);
}

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

int above_median_available(t_node **lst, int median)
{
	t_node	*curr;

	curr = *lst;
	while (curr != NULL)
	{
		if (curr->rank > median)
			return (1);
		curr = curr->next;
	}
	return (0);
}

int finalization_attach(t_node **A, t_node **B, t_node **output, int m)
{
	t_node	*curr_b;
	int		target_p_a;

	curr_b = *B;
	while (*B != NULL && (*B)->rank > m)
	{
		label_position(B);
		curr_b = *B;
		target_p_a = get_target_p_A(A, curr_b->rank);
		push_a(A, B, output, &curr_b, target_p_a);
		pa(A, B, output, 1);
	}
}

int	finalization(t_node **A, t_node **B, t_node **output)
{
	int 	m[4];
	int		i;

	m[0] = 0;
	m[1] = get_three_median(B, 1, 1);
	m[2] = get_three_median(B, 1, 2);
	m[3] = get_three_median(B, 1, 3);
	i = 3;
	while (*B != NULL)
	{
		while ((*B)->rank <= m[i] && c_node(*B) > 1)
			rb(B, output, 1);
		finalization_attach(A, B, output, m[i]);
		if (!above_median_available(B, m[i]))
			i--;
	}
}

void	quick_sort(t_node **A, t_node **B, t_node **output)
{
	decending_from_top(A, B, output, 5);
	(*output)->median = get_median_rank_within_chunk(B, 4);
	split_chunk_top(A, B, output, 4);
	decending_from_bottom(A, B, output, 4);
	(*output)->median = get_median_rank_within_chunk(B, 3);
	split_chunk_bottom(A, B, output, 3);
	decending_from_top(A, B, output, 3);

	(*output)->median = get_three_median(B, 2, 3);
	split_chunk_top(A, B, output, 2);
	(*output)->median = get_three_median(B, 2, 2);
	split_chunk_bottom(A, B, output, 2);
	// (*output)->median = get_three_median(B, 2, 1);
	// split_chunk_top(A, B, output, 2);
	// decending_from_bottom(A, B, output, 2);
	decending_from_top(A, B, output, 2);

	finalization(A, B, output);
}

int	final_sort(t_node **A, t_node **output)
{
	t_node	*curr;

	label_position(A);
	curr = *A;
	while (curr != NULL)
	{
		if (curr->rank == get_lowest_rank(A))
			break ;
		curr = curr->next;
	}
	while ((*A)->position != curr->position)
	{
		if (curr->position <= c_node(*A) / 2)
			ra(A, output, 1);
		else
			rra(A, output, 1);
	}
}


void mega_sort_two(t_node **A, t_node **B, t_node **output)
{	
	// int inner_chunk[100];
	// int outer_chunk[100];
	// int num_chunk;
	t_node *curr;

	curr = *A;
	insert_back(output, 0);
	(*output)->num_chunk = 10;
	label_ranking(A);
	inner_chunk_maker(output, c_node(*A)); //, inner_chunk, num_chunk);
	outer_chunk_maker(output, c_node(*A)); //, inner_chunk, outer_chunk, num_chunk);
	lable_chunk(A, output); // outer_chunk, num_chunk);
	push_top_chunk(A, B, output); //, outer_chunk, num_chunk);
	quick_sort(A, B, output); //, outer_chunk, num_chunk);
	final_sort(A, output);
}

// Stack A will rotate, if value on top is within current and the next chunks. Ready to PA.
// Stack B will check which chunk the top value of Stack A is, will rotate accordingly.
// If chunk on top B is same with on top A, Push B.
// If chunk on top B is not same with on top A, 
// Objective, make sure chunk 1 and chunk 2 doesn't overlap.
// Check if on top Stack B and the next, if same just push, not same rotate.






