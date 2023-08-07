/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_category.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:30:39 by folim             #+#    #+#             */
/*   Updated: 2023/08/07 23:30:41 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_type_assign(t_node **A, t_node **B, t_node **output)
{
	check_duplicate(A);
	if (!check_sorted(A))
	{   
		if(c_node(*A) <= 3)
			tiny_sort(A, output);
		else if(c_node(*A) <= 5)
			medium_sort(A, B, output);
		else
			mega_sort(A, B, output);
	}
}

void	tiny_sort(t_node **A, t_node **output)
{
	t_node *curr;
	int largest;
	int c;

	if(c_node(*A) > 3)
		return ;
	largest = get_largest(A);
	curr = *A;
	c = 1;
	while (!check_sorted(A))
	{
		if(c == 1 && largest == curr->x)
		{
			ra(A, output, 1);
			curr = *A;
			c = 1;
		}
		if(c == 2 && largest == curr->x)
		{
			rra(A, output, 1);
			curr = *A;
			c = 1;
		}
		if(c == 3 && largest == curr->x)
		{
			sa(A, output, 1);
			curr = *A;
			c = 1;
		}
		c++;
		curr = curr->next;
	}
}

void	medium_sort(t_node **A, t_node **B, t_node **output)
{
	int largest;
	int smallest;
	
	if(c_node(*A) > 5)
		return ;
	largest = get_largest(A);
	smallest = get_smallest(A);
	pb(A, B, output, 1);
	pb(A, B, output, 1);
	tiny_sort(A, output);
	while(*B != NULL)
	{
		if((*B)->x == largest && (*B)->x && get_largest(A) == last_node_value(*A))
			pa(A, B, output, 1);
		else if((*B)->x == smallest && get_smallest(A) == (*A)->x)
			pa(A, B, output, 1);
		else if((*B)->x > last_node_value(*A) && (*B)->x < (*A)->x)
			pa(A, B, output, 1);
		else if(check_sorted(A) && (*B)->x < (*A)->x)
			pa(A, B, output, 1);
		else if(check_sorted(A) && (*B)->x > last_node_value(*A))
			pa(A, B, output, 1);
		else
			ra(A, output, 1);
	}
	while(!check_sorted(A))
	{
		if(last_node_value(*A) == smallest)
			rra(A, output, 1);
		else
			ra(A, output, 1);
	}
}
