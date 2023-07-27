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
	while(i <= 7)
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
		{
			curr->chunk_id = (chunk[i]+1);
			return (curr->position);
		}
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
		{
			curr->chunk_id = (chunk[i]+1);
			return (curr->position);
		}
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

int	push_A_multi_way_find(Node **A, Node **B, int *chunk, int i, int n_operation)
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



int mega_sort_two(Node **A, Node **B, int n_operation)
{	
	int chunk[100];
	int i;
	// int position_s;
	Node *curr;

	curr = *A;
	label_ranking(A);
	// view_all(*A, *B);
	chunk_maker(count_node(*A), chunk, 7);
	i = 0;
	while(i < 7 && (*A) != NULL)
	{
	
		// n_operation = push_A_multi_way_find(A, B, chunk, i, n_operation);
		n_operation = push_A_single_way_find(A, B, chunk, i, n_operation);
		if(!value_within_chunk_available(A, chunk, i))
			i++;
	}
	view_all(*A, *B);
	view_chunk(chunk, 7);
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


int push_top_chunk(Node **A, Node **B, int *chunk, int i, int j, int n_operation)
{
	Node *curr_A;
	Node *curr_B;
	int rank_selected_A;
	int rotateA;
	int pushB;

	curr_A = *A;
	curr_B = *B;
	if(value_within_chunk_available(A, chunk, i)) //loop while value within chunk is avalable
	{
		if((*A)->rank > (chunk[i]) && curr_A->rank <= chunk[i+1] || (*A)->rank > (chunk[i+j]) && curr_A->rank <= chunk[i+1+j])
			pushB = 1;
		else
			rotateA = 1;
	}
	if(count_node(*B) > 1)
	{
		if((*B)->rank > (chunk[i]) && curr_A->rank <= chunk[i+1] )
	}

	




	return (n_operation);
}
