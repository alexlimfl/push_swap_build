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


int	push_A_single_way_find(t_node **A, t_node **B, int *chunk, int i, int n_op)
{
	int	position_s;

	label_position(A);
	position_s = ps_w_chk(A, chunk, i);
	if (position_s > 0)
	{
		while (position_s != -1 && (*A)->position != position_s)
			n_op = ra(A, 1, n_op);
		n_op = pb(A, B, 1, n_op);
	}
	return (n_op);
}

int	push_B_multi_way_find(t_node **A, t_node **B, int *chunk, int i, int n_op)
{
	int	position_s;

	label_position(A);
	if (ps_w_chk(A, chunk, i) + ps_w_chk_r(A, chunk, i) > 0)
	{
		if (ps_w_chk(A, chunk, i) <= (c_node(*A) - ps_w_chk_r(A, chunk, i)))
		{
			position_s = ps_w_chk(A, chunk, i);
			while (position_s != -1 && (*A)->position != position_s)
				n_op = ra(A, 1, n_op);
		}
		else if (ps_w_chk(A, chunk, i) > (c_node(*A) - ps_w_chk_r(A, chunk, i)))
		{
			position_s = ps_w_chk_r(A, chunk, i);
			while (position_s != -1 && (*A)->position != position_s)
				n_op = rra(A, 1, n_op);
		}
		if (position_s > 0)
			n_op = pb(A, B, 1, n_op);
	}
	return (n_op);
}

int	PB_multi_find_chunkID(t_node **A, t_node **B, int c1, int c2, int n_op)
{
	int	position_s;

	label_position(A);
	if (ps_chk_id(A, c1, c2) <= (c_node(*A) - ps_chk_id_r(A, c1, c2)))
	{
		position_s = ps_chk_id(A, c1, c2);
		while (position_s != -1 && (*A)->position != position_s)
			n_op = ra(A, 1, n_op);
	}
	else if (ps_chk_id(A, c1, c2) > (c_node(*A) - ps_chk_id_r(A, c1, c2)))
	{
		position_s = ps_chk_id_r(A, c1, c2);
		while (position_s != -1 && (*A)->position != position_s)
			n_op = rra(A, 1, n_op);
	}
	if (position_s > 0)
		n_op = pb(A, B, 1, n_op);
	return (n_op);
}


void lable_chunk(t_node **lst, int *chunk, int num_chunk)
{
	t_node	*curr;
	int		i;

	i = 0;
	while (i < num_chunk)
	{
		curr = *lst;
		while (curr != NULL)
		{
			if (value_within_chunk_available(lst, chunk, i)
				&& curr->rank > (chunk[i]) && curr->rank <= chunk[i + 1])
				curr->chunk_id = i + 1;
			curr = curr->next;
		}
		if (curr == NULL)
			i++;
	}
}

int rotate(t_node **A, t_node**B, int RA, int RB, int n_op)
{
	if(RA == 1 && RB == 1)
		n_op = rr(A, B, 1, n_op);
	else if(RA == 1 && RB == 0)
		n_op = ra(A, 1, n_op);
	else if(RA == 0 && RB == 1)
		n_op = rb(B, 1, n_op);
	return (n_op);
}

int reverse_rotate(t_node **A, t_node**B, int RRA, int RRB, int n_op)
{
	if(RRA == 1 && RRB == 1)
		n_op = rrr(A, B, 1, n_op);
	else if(RRA == 1 && RRB == 0)
		n_op = rra(A, 1, n_op);
	else if(RRA == 0 && RRB == 1)
		n_op = rrb(B, 1, n_op);
	return (n_op);
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

int push_top_chunk(t_node **A, t_node **B, int *chunk, int num_chunk, int n_op)
{
	int RA;
	int RB;
	int i;

	while(c_node(*B) < 2)
		n_op = PB_multi_find_chunkID(A, B, 1, 2, n_op);
	i = 0;
	while(i <= (num_chunk - 2) && c_node(*A) > 3)
	{
		while((value_within_chunk_available(A, chunk, i) || value_within_chunk_available(A, chunk, (i+1))) && c_node(*A) > 3)
		{
			RA = 0;
			RB = 0;
			if((*A)->chunk_id >= (*B)->chunk_id && ((*A)->chunk_id == (i+1) || (*A)->chunk_id == (i+2)))
			{
				n_op = pb(A, B, 1, n_op);
				if((*B)->chunk_id == (i+1))
					RB = 1;
			}
			else if((*A)->chunk_id < (*B)->chunk_id && ((*A)->chunk_id == (i+1) || (*A)->chunk_id == (i+2)))
			{
				n_op = pb(A, B, 1, n_op);
				RB = 1;
			}
			if((*A) != NULL && (*A)->chunk_id != (i+1) && (*A)->chunk_id != (i+2))
				RA = 1;
				n_op = rotate(A, B, RA, RB, n_op);
		}
		i += 2;
	}
	n_op = tiny_sort(A, n_op);
	/*
	while(value_within_chunk_available(A, chunk, 0) || value_within_chunk_available(A, chunk, 1))
	{
		RA = 0;
		RB = 0;
		if((*A)->chunk_id >= (*B)->chunk_id && ((*A)->chunk_id == 1 || (*A)->chunk_id == 2))
			n_op = pb(A, B, 1, n_op);
		else if((*A)->chunk_id < (*B)->chunk_id && ((*A)->chunk_id == 1 || (*A)->chunk_id == 2))
		{
			n_op = pb(A, B, 1, n_op);
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
			n_op = pb(A, B, 1, n_op);
	
		if((*A)->chunk_id >= (*B)->chunk_id && ((*A)->chunk_id == 3 || (*A)->chunk_id == 4))
			n_op = pb(A, B, 1, n_op);
		else if((*A)->chunk_id < (*B)->chunk_id && ((*A)->chunk_id == 3 || (*A)->chunk_id == 4))
		{
			n_op = pb(A, B, 1, n_op);
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
			n_op = pb(A, B, 1, n_op);
	
		if((*A)->chunk_id >= (*B)->chunk_id && ((*A)->chunk_id == 5 || (*A)->chunk_id == 6))
			n_op = pb(A, B, 1, n_op);
		else if((*A)->chunk_id < (*B)->chunk_id && ((*A)->chunk_id == 5 || (*A)->chunk_id == 6))
		{
			n_op = pb(A, B, 1, n_op);
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
			n_op = pb(A, B, 1, n_op);
	
		if((*A)->chunk_id >= (*B)->chunk_id && ((*A)->chunk_id == 7 || (*A)->chunk_id == 8))
			n_op = pb(A, B, 1, n_op);
		else if((*A)->chunk_id < (*B)->chunk_id && ((*A)->chunk_id == 7 || (*A)->chunk_id == 8))
		{
			n_op = pb(A, B, 1, n_op);
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
			n_op = pb(A, B, 1, n_op);
	
		if((*A)->chunk_id >= (*B)->chunk_id && ((*A)->chunk_id == 9 || (*A)->chunk_id == 10))
			n_op = pb(A, B, 1, n_op);
		else if((*A)->chunk_id < (*B)->chunk_id && ((*A)->chunk_id == 9 || (*A)->chunk_id == 10))
		{
			n_op = pb(A, B, 1, n_op);
			RB = 1;
		}
		if(((*A)->chunk_id != 9 && (*A)->chunk_id != 10))
			RA = 1;
		n_op = rotate(A, B, RA, RB, n_op);
	}*/
	return (n_op);
}

void	inner_chunk_maker(int nn, int *inner_chunk, int denominator)
{
	int D;
	int i;
	float numerator;

	D = denominator * 6.2;
	numerator = 1;
	inner_chunk[0] = 0;
	i = 1;
	while(numerator <= D)
	{
		inner_chunk[i] = (numerator/D)*nn;
		i++;
		numerator++;
	}
}


void	outer_chunk_maker(int nn, int *inner_chunk, int *outer_chunk, int denominator)
{
	float numerator;
	int i;
	int j;
	int section[] = {0, 16, 32, 40, 48, 52, 56, 58, 60, 61, 62};

	numerator = 1;
	outer_chunk[0] = 0;
	i = 1;
	j = 1;
	while(numerator <= denominator)
	{
		outer_chunk[i] = inner_chunk[section[j]];
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

int push_a(t_node **A, t_node **B, t_node **curr_b, int target_p_a)
{
	t_node	*tail_A;
	t_var	op;
	int		n_op;

	n_op = 0;
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
		n_op = rotate(A, B, op.ra, op.rb, n_op);
		n_op = reverse_rotate(A, B, op.rra, op.rrb, n_op);
	}
	return (n_op);
}

int	decending_from_top(t_node **A, t_node **B, int *chunk, int num_chunk, int until_chunk)
{
	t_node	*curr_b;
	t_node	*tail_A;
	int 	n_op;
	// int		RA;
	// int		RB;
	// int		RRA;
	// int		RRB;
	int		target_p_a;

	n_op = 0;
	while ((*B) != NULL && chunkID_avalable(B, until_chunk))
	{
		label_position(B);
		if (is_even(num_chunk) || until_chunk < 5)
			curr_b = *B;
		else if (!is_even(num_chunk))
			curr_b = double_ll_convert(B);
		target_p_a = get_target_p_A(A, curr_b->rank);
		n_op += push_a(A, B, &curr_b, target_p_a);
		n_op = pa(A, B, 1, n_op);
		if (!chunkID_avalable(B, num_chunk))
			num_chunk--;
	}
	return (n_op);
}

int	decending_from_bottom(t_node **A, t_node **B, int *chunk, int chunkID)
{
	t_node *curr_b;
	t_node *tail_A;
	int 	n_op;
	// int RA;
	// int RB;
	// int RRA;
	// int RRB;
	int target_p_a;

	n_op = 0;
	while((*B) != NULL && chunkID_avalable(B, chunkID))
	{					
		label_position(B);
		curr_b = double_ll_convert(B);
		target_p_a =  get_target_p_A(A, curr_b->rank);
		n_op += push_a(A, B, &curr_b, target_p_a);
		n_op = pa(A, B, 1, n_op);
	}
	return (n_op);
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

int rotate_below_median_top(t_node **A, t_node **B, int chunkID, int median)
{
	t_node *curr_b;
	int n_op;

	n_op = 0;
	while (*B != NULL && (*B)->chunk_id == chunkID && (*B)->rank <= median)
		n_op = rb(B, 1, n_op);
	return (n_op);
}

int rotate_below_median_bottom(t_node **A, t_node **B, int chunkID, int median)
{
	t_node *curr_b;
	int n_op;

	n_op = 0;
	curr_b = double_ll_convert(B);
	while (*B != NULL && curr_b->chunk_id == chunkID
		&& curr_b->rank <= median)
	{
		n_op = rrb(B, 1, n_op);
		curr_b = double_ll_convert(B);
	}
	return (n_op);
}

int	split_chunk_top(t_node **A, t_node **B, int chunkID, int median)
{
	t_node	*curr_b;
	int		target_p_a;
	int		n_op;

	n_op = 0;
	label_position(A);
	label_position(B);
	while ((*B) != NULL && (*B)->chunk_id == chunkID)
	{
		n_op += rotate_below_median_top(A, B, chunkID, median);
		if ((*B)->chunk_id == chunkID)
		{
			target_p_a =  get_target_p_A(A, (*B)->rank);
			n_op += push_a(A, B, B, target_p_a);
			n_op = pa(A, B, 1, n_op);
		}
	}
	return (n_op);
}

int	split_chunk_bottom(t_node **A, t_node **B, int chunkID, int median)
{
	t_node	*tail_b;
	int		target_p_a;
	int		n_op;

	n_op = 0;
	label_position(A);
	label_position(B);
	tail_b = double_ll_convert(B);
	while ((*B) != NULL && tail_b->chunk_id == chunkID)
	{
		tail_b = double_ll_convert(B);
		n_op += rotate_below_median_bottom(A, B, chunkID, median);
		tail_b = double_ll_convert(B);
		if (tail_b->chunk_id == chunkID)
		{
			target_p_a = get_target_p_A(A, tail_b->rank);
			n_op += push_a(A, B, &tail_b, target_p_a);
			n_op = pa(A, B, 1, n_op);
		}
		tail_b = double_ll_convert(B);
	}
	return (n_op);
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

int finalization_attach(t_node **A, t_node **B, int m, int n_op)
{
	t_node	*curr_b;
	int		target_p_a;

	curr_b = *B;
	while (*B != NULL && (*B)->rank > m)
	{
		label_position(B);
		curr_b = *B;
		target_p_a = get_target_p_A(A, curr_b->rank);
		n_op += push_a(A, B, &curr_b, target_p_a);
		n_op = pa(A, B, 1, n_op);
	}
	return (n_op);
}

int	finalization(t_node **A, t_node **B)
{
	int 	m[4];
	int		n_op;
	int		i;

	n_op = 0;
	m[0] = 0;
	m[1] = get_three_median(B, 1, 1);
	m[2] = get_three_median(B, 1, 2);
	m[3] = get_three_median(B, 1, 3);
	i = 3;
	while (*B != NULL)
	{
		while ((*B)->rank <= m[i] && c_node(*B) > 1)
			n_op = rb(B, 1, n_op);
		n_op = finalization_attach(A, B, m[i], n_op);
		if (!above_median_available(B, m[i]))
			i--;
	}
	return (n_op);
}

int	quick_sort(t_node **A, t_node **B, int *chunk, int num_chunk, int n_op)
{
	n_op += decending_from_top(A, B, chunk, num_chunk, 5);
	n_op += split_chunk_top(A, B, 4, get_median_rank_within_chunk(B, 4));
	n_op += decending_from_bottom(A, B, chunk, 4);
	n_op += split_chunk_bottom(A, B, 3, get_median_rank_within_chunk(B, 3));
	n_op += decending_from_top(A, B, chunk, num_chunk, 3);
	n_op += split_chunk_top(A, B, 2, get_three_median(B, 2, 2));
	n_op += split_chunk_bottom(A, B, 2, get_three_median(B, 2, 3));
	n_op += decending_from_top(A, B, chunk, num_chunk, 2);
	n_op += finalization(A, B);
	return (n_op);
}

int	final_sort(t_node **A, int n_op)
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
			n_op = ra(A, 1, n_op);
		else
			n_op = rra(A, 1, n_op);
	}
	return (n_op);
}


int mega_sort_two(t_node **A, t_node **B, int n_op)
{	
	int inner_chunk[100];
	int outer_chunk[100];
	int num_chunk;
	// int position_s;
	t_node *curr;

	curr = *A;
	num_chunk = 10;
	label_ranking(A);
	// view_list_rank(*A);
	// exit(1);
	inner_chunk_maker(c_node(*A), inner_chunk, num_chunk);
	outer_chunk_maker(c_node(*A), inner_chunk, outer_chunk, num_chunk);
	lable_chunk(A, outer_chunk, num_chunk);
	n_op = push_top_chunk(A, B, outer_chunk, num_chunk, n_op);
	// check_sorted_h_tail(B);
	// view_all(*A, *B);
	// exit(0);
	n_op = quick_sort(A, B, outer_chunk, num_chunk, n_op);
	n_op = final_sort(A, n_op);


	view_all(*A, *B);
	view_chunk(outer_chunk, num_chunk);
	ft_printf("Check sorted = %d\n", check_sorted(A));
	ft_printf("Check sorted plus = %d\n", check_sorted_plus(A));

	ft_printf("Number of Operation >>> %d\n", n_op);
	exit(0);
	return (n_op);
}

// Stack A will rotate, if value on top is within current and the next chunks. Ready to PA.
// Stack B will check which chunk the top value of Stack A is, will rotate accordingly.
// If chunk on top B is same with on top A, Push B.
// If chunk on top B is not same with on top A, 
// Objective, make sure chunk 1 and chunk 2 doesn't overlap.
// Check if on top Stack B and the next, if same just push, not same rotate.






