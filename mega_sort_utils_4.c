/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mega_sort_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:54:18 by folim             #+#    #+#             */
/*   Updated: 2023/08/07 23:54:19 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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