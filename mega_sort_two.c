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

int mega_sort_two(Node **A, Node **B, int n_operation)
{	
	int chunk[100];
	int selected_A;
	int i;
	int position_s;
	Node *curr;
	curr = *A;
	
	label_ranking(A);
	label_position(A);
	view_all(*A, *B);

	chunk_maker(count_node(*A), chunk, 7);



	// while(curr != NULL)
	// {
	// 	if(curr->rank == 236)
	// 	{
	// 		printf("\nCHECK, %d\n", c);
	// 		exit(1);
	// 	}
	// 	curr = curr->next;
	// }

	// move Stack B without finding ra or rra.
	i = 0;
	while(i < 7 && (*A) != NULL)
	{
		position_s = position_s_within_chunk(A, chunk, i);
			if(position_s == 236)
			{
				ft_printf("chunkID: %d\n", i);
				exit(1);
			}
		while(position_s != -1 && (*A)->position != position_s)
		{
		// ft_printf("CHECK	%d	%d\n", (*A)->position, position_s);
			ra(A, 0);
		}
		pb(A, B);
		if(position_s == -1)
			i++;

	}
	view_all(*A, *B);
	view_chunk(chunk, 7);
	return (n_operation);
}

int	position_s_within_chunk(Node **A, int *chunk, int i)
{
	int middle_p;
	int selected_p;
	Node *curr;

	middle_p = count_node(*A);
	curr = *A;
	
	while(curr != NULL)
	{
			// if(curr->rank == 443)
			// {
			// 	ft_printf("\n%d, %d, %d\n", chunk[i]+1, curr->rank, chunk[i+1]);
			// 	exit(1);
			// }
		curr = curr->next;
	}
	
	curr = *A;
	while(curr != NULL)
	{
		if(curr->rank > (chunk[i]) && curr->rank <= chunk[i+1])
		{
			// if(curr->rank == 236)
			// {
			// 	ft_printf("\n%d, %d, %d\n", chunk[i]+1, curr->rank, chunk[i+1]);
			// 	exit(1);
			// }
			curr->chunk_id = (chunk[i]+1);
			selected_p = curr->position;
			break;
		}
		curr = curr->next;
	}
	if(curr == NULL)
		return (-1);
	return (selected_p);
}