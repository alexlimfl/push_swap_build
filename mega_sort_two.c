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

void view_chunk(int *chunk,  int num_chunk)
{
	int i;

	i = 0;
	while(i <= num_chunk)
	{
		printf("%d\n", chunk[i]);
		i++;
	}
}

int	position_s_within_chunk(Node **A, int *chunk, int i)
{
	Node *curr;

	curr = *A;
	while(curr != NULL)
	{
		if(curr->rank > (chunk[i]) && curr->rank <= chunk[i+1])
			return (curr->position);
		curr = curr->next;
	}
	return (-1);
}

int position_s_within_chunk_reverse(Node **A, int *chunk, int i)
{
	Node *curr;

	curr = double_ll_convert(A);
	while(curr != NULL)
	{
		if(curr->rank > (chunk[i]) && curr->rank <= chunk[i+1])
			return (curr->position);
		curr = curr->prev;
	}
	return (-1);
}


int	position_s_chunk_id(Node **lst, int chunk_one, int chunk_two)
{
	Node *curr;

	curr = *lst;
	while(curr != NULL)
	{
		if(curr->chunk_id == chunk_one || curr->chunk_id == chunk_two)
			return (curr->position);
		curr = curr->next;
	}
	return (-1);
}

int	position_s_chunk_id_reverse(Node **lst, int chunk_one, int chunk_two)
{
	Node *curr;

	curr = double_ll_convert(lst);
	while(curr != NULL)
	{
		if(curr->chunk_id == chunk_one || curr->chunk_id == chunk_two)
			return (curr->position);
		curr = curr->prev;
	}
	return (-1);
}


int value_within_chunk_available(Node **lst, int *chunk, int i)
{
	Node *curr;

	curr = *lst;
	while(curr != NULL)
	{
		if(curr->rank > (chunk[i]) && curr->rank <= chunk[i+1])
			return (1);
		curr = curr->next;
	}
	return (0);
}

int	push_A_single_way_find(Node **A, Node **B, int *chunk, int i, int n_operation)
{
	int position_s;
	
	label_position(A);
	position_s = position_s_within_chunk(A, chunk, i);
	if(position_s > 0)
	{
		while(position_s != -1 && (*A)->position != position_s)
			n_operation = ra(A, 1, n_operation);
		n_operation = pb(A, B, 1, n_operation);
	}
	return (n_operation);
}

int	push_B_multi_way_find(Node **A, Node **B, int *chunk, int i, int n_operation)
{
	int	position_s;

	label_position(A);
	if(position_s_within_chunk(A, chunk, i) + position_s_within_chunk_reverse(A, chunk, i) > 0) //if not negative
		{
			if(position_s_within_chunk(A, chunk, i) <= (count_node(*A) - position_s_within_chunk_reverse(A, chunk, i)))
			{
				position_s = position_s_within_chunk(A, chunk, i);
				while(position_s != -1 && (*A)->position != position_s)
					n_operation = ra(A, 1, n_operation);
			}
			else if(position_s_within_chunk(A, chunk, i) > (count_node(*A) - position_s_within_chunk_reverse(A, chunk, i)))
			{
				position_s = position_s_within_chunk_reverse(A, chunk, i);
				while(position_s != -1 && (*A)->position != position_s)
					n_operation = rra(A, 1, n_operation);
			}
			if(position_s > 0)
				n_operation = pb(A, B, 1, n_operation);
		}
	return (n_operation);
}

int	PB_multi_find_chunkID(Node **A, Node **B, int chunk_one, int chunk_two, int n_operation)
{
	int	position_s;

	label_position(A);
	if(position_s_chunk_id(A, chunk_one, chunk_two) <= (count_node(*A) - position_s_chunk_id_reverse(A, chunk_one, chunk_two)))
	{
		position_s = position_s_chunk_id(A, chunk_one, chunk_two);
		while(position_s != -1 && (*A)->position != position_s)
			n_operation = ra(A, 1, n_operation);
	}
	else if(position_s_chunk_id(A, chunk_one, chunk_two) > (count_node(*A) - position_s_chunk_id_reverse(A, chunk_one, chunk_two)))
	{
		position_s = position_s_chunk_id_reverse(A, chunk_one, chunk_two);
		while(position_s != -1 && (*A)->position != position_s)
			n_operation = rra(A, 1, n_operation);
	}
	if(position_s > 0)
		n_operation = pb(A, B, 1, n_operation);
	return(n_operation);
}


void lable_chunk(Node **lst, int *chunk, int num_chunk)
{
	Node *curr;
	int i;

	i = 0;
	while(i < num_chunk)
	{
		
		curr = *lst;
		while(curr != NULL)
		{	
			if(value_within_chunk_available(lst, chunk, i) && curr->rank > (chunk[i]) && curr->rank <= chunk[i+1])
				curr->chunk_id = i+1;
			curr = curr->next;
		}
		if(curr == NULL)
			i++;
	}
}

int rotate(Node **A, Node**B, int RA, int RB, int n_operation)
{
	if(RA == 1 && RB == 1)
		n_operation = rr(A, B, 1, n_operation);
	else if(RA == 1 && RB == 0)
		n_operation = ra(A, 1, n_operation);
	else if(RA == 0 && RB == 1)
		n_operation = rb(B, 1, n_operation);
	return (n_operation);
}

int push_top_chunk(Node **A, Node **B, int *chunk, int num_chunk, int n_operation)
{
	int RA;
	int RB;
	int i;

	while(count_node(*B) < 2)
		n_operation = PB_multi_find_chunkID(A, B, 1, 2, n_operation);
	i = 0;
	while(i <= (num_chunk - 2))
	{
		while(value_within_chunk_available(A, chunk, i) || value_within_chunk_available(A, chunk, (i+1)))
		{
			RA = 0;
			RB = 0;
			if((*A)->chunk_id >= (*B)->chunk_id && ((*A)->chunk_id == (i+1) || (*A)->chunk_id == (i+2)))
			{
				n_operation = pb(A, B, 1, n_operation);
			}
			else if((*A)->chunk_id < (*B)->chunk_id && ((*A)->chunk_id == (i+1) || (*A)->chunk_id == (i+2)))
			{
				n_operation = pb(A, B, 1, n_operation);
				// ft_printf("CHECK\n");
				RB = 1;
			}
			if((*A) != NULL && (*A)->chunk_id != (i+1) && (*A)->chunk_id != (i+2))
				RA = 1;
			// if((*A) != NULL)
				n_operation = rotate(A, B, RA, RB, n_operation);
		}
		while((*B)->chunk_id == (i+1))
			n_operation = rb(B, 1, n_operation);
		i += 2;
	}

	/*
	while(value_within_chunk_available(A, chunk, 0) || value_within_chunk_available(A, chunk, 1))
	{
		RA = 0;
		RB = 0;
		if((*A)->chunk_id >= (*B)->chunk_id && ((*A)->chunk_id == 1 || (*A)->chunk_id == 2))
			n_operation = pb(A, B, 1, n_operation);
		else if((*A)->chunk_id < (*B)->chunk_id && ((*A)->chunk_id == 1 || (*A)->chunk_id == 2))
		{
			n_operation = pb(A, B, 1, n_operation);
			RB = 1;

		}
		if(((*A)->chunk_id != 1 && (*A)->chunk_id != 2))
			RA = 1;
		n_operation = rotate(A, B, RA, RB, n_operation);
	}
	while(value_within_chunk_available(A, chunk, 2) || value_within_chunk_available(A, chunk, 3))
	{
		RA = 0;
		RB = 0;
		while(count_node(*B) < 2 && ((*A)->chunk_id == 3 || (*A)->chunk_id == 4))
			n_operation = pb(A, B, 1, n_operation);
	
		if((*A)->chunk_id >= (*B)->chunk_id && ((*A)->chunk_id == 3 || (*A)->chunk_id == 4))
			n_operation = pb(A, B, 1, n_operation);
		else if((*A)->chunk_id < (*B)->chunk_id && ((*A)->chunk_id == 3 || (*A)->chunk_id == 4))
		{
			n_operation = pb(A, B, 1, n_operation);
			RB = 1;

		}
		if(((*A)->chunk_id != 3 && (*A)->chunk_id != 4))
			RA = 1;
		n_operation = rotate(A, B, RA, RB, n_operation);
	}
	while(value_within_chunk_available(A, chunk, 4) || value_within_chunk_available(A, chunk, 5))
	{
		RA = 0;
		RB = 0;
		while(count_node(*B) < 2 && ((*A)->chunk_id == 5 || (*A)->chunk_id == 6))
			n_operation = pb(A, B, 1, n_operation);
	
		if((*A)->chunk_id >= (*B)->chunk_id && ((*A)->chunk_id == 5 || (*A)->chunk_id == 6))
			n_operation = pb(A, B, 1, n_operation);
		else if((*A)->chunk_id < (*B)->chunk_id && ((*A)->chunk_id == 5 || (*A)->chunk_id == 6))
		{
			n_operation = pb(A, B, 1, n_operation);
			RB = 1;

		}
		if(((*A)->chunk_id != 5 && (*A)->chunk_id != 6))
			RA = 1;
		n_operation = rotate(A, B, RA, RB, n_operation);
	}
	while(value_within_chunk_available(A, chunk, 6) || value_within_chunk_available(A, chunk, 7))
	{
		RA = 0;
		RB = 0;
		while(count_node(*B) < 2 && ((*A)->chunk_id == 7 || (*A)->chunk_id == 8))
			n_operation = pb(A, B, 1, n_operation);
	
		if((*A)->chunk_id >= (*B)->chunk_id && ((*A)->chunk_id == 7 || (*A)->chunk_id == 8))
			n_operation = pb(A, B, 1, n_operation);
		else if((*A)->chunk_id < (*B)->chunk_id && ((*A)->chunk_id == 7 || (*A)->chunk_id == 8))
		{
			n_operation = pb(A, B, 1, n_operation);
			RB = 1;

		}
		if(((*A)->chunk_id != 7 && (*A)->chunk_id != 8))
			RA = 1;
		n_operation = rotate(A, B, RA, RB, n_operation);
	}
	while(value_within_chunk_available(A, chunk, 8) || value_within_chunk_available(A, chunk, 9))
	{
		RA = 0;
		RB = 0;
		while(count_node(*B) < 2 && ((*A)->chunk_id == 9 || (*A)->chunk_id == 10))
			n_operation = pb(A, B, 1, n_operation);
	
		if((*A)->chunk_id >= (*B)->chunk_id && ((*A)->chunk_id == 9 || (*A)->chunk_id == 10))
			n_operation = pb(A, B, 1, n_operation);
		else if((*A)->chunk_id < (*B)->chunk_id && ((*A)->chunk_id == 9 || (*A)->chunk_id == 10))
		{
			n_operation = pb(A, B, 1, n_operation);
			RB = 1;
		}
		if(((*A)->chunk_id != 9 && (*A)->chunk_id != 10))
			RA = 1;
		n_operation = rotate(A, B, RA, RB, n_operation);
	}*/
	return (n_operation);
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

int mega_sort_two(Node **A, Node **B, int n_operation)
{	
	int inner_chunk[100];
	int outer_chunk[100];
	int num_chunk;
	// int position_s;
	Node *curr;

	curr = *A;
	num_chunk = 10;
	label_ranking(A);
	view_list_rank(*A);
	// exit(1);
	inner_chunk_maker(count_node(*A), inner_chunk, num_chunk);
	outer_chunk_maker(count_node(*A), inner_chunk, outer_chunk, num_chunk);
	lable_chunk(A, outer_chunk, num_chunk);
	n_operation = push_top_chunk(A, B, outer_chunk, num_chunk, n_operation);


	
	view_all(*A, *B);
	view_chunk(outer_chunk, num_chunk);
	ft_printf("Number of Operation >>> %d\n", n_operation);
	exit(0);
	return (n_operation);
}

// Stack A will rotate, if value on top is within current and the next chunks. Ready to PA.
// Stack B will check which chunk the top value of Stack A is, will rotate accordingly.
// If chunk on top B is same with on top A, Push B.
// If chunk on top B is not same with on top A, 
// Objective, make sure chunk 1 and chunk 2 doesn't overlap.
// Check if on top Stack B and the next, if same just push, not same rotate.






