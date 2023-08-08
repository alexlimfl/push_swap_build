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

void	sorting_type_assign(t_node **a, t_node **b, t_node **otpt)
{
	check_duplicate(a);
	insert_back(otpt, 0);
	if (!check_sorted(a))
	{
		if (c_n(*a) <= 3)
			tiny_sort(a, b, otpt);
		else if (c_n(*a) <= 5)
			medium_sort(a, b, otpt);
		else
			mega_sort(a, b, otpt);
	}
}

void	tiny_sort_attach(t_node **a, t_node **b, t_node **otpt, t_node *curr)
{
	while (!check_sorted(a))
	{
		if ((*otpt)->c == 1 && (*otpt)->largest == curr->x)
		{
			ra(a, b, otpt, 1);
			curr = *a;
			(*otpt)->c = 1;
		}
		if ((*otpt)->c == 2 && (*otpt)->largest == curr->x)
		{
			rra(a, b, otpt, 1);
			curr = *a;
			(*otpt)->c = 1;
		}
		if ((*otpt)->c == 3 && (*otpt)->largest == curr->x)
		{
			sa(a, b, otpt, 1);
			curr = *a;
			(*otpt)->c = 1;
		}
		(*otpt)->c++;
		curr = curr->next;
	}
}

void	tiny_sort(t_node **a, t_node **b, t_node **otpt)
{
	t_node	*curr;

	(*otpt)->largest = get_largest(a);
	curr = *a;
	(*otpt)->c = 1;
	tiny_sort_attach(a, b, otpt, curr);
}

void	medium_sort_attach(t_node **a, t_node **b, t_node **otpt)
{
	while (*b != NULL)
	{
		if ((*b)->x == (*otpt)->largest
			&& (*b)->x && get_largest(a) == last_node_value(*a))
			pa(a, b, otpt, 1);
		else if ((*b)->x == (*otpt)->smallest && get_smallest(a) == (*a)->x)
			pa(a, b, otpt, 1);
		else if ((*b)->x > last_node_value(*a) && (*b)->x < (*a)->x)
			pa(a, b, otpt, 1);
		else if (check_sorted(a) && (*b)->x < (*a)->x)
			pa(a, b, otpt, 1);
		else if (check_sorted(a) && (*b)->x > last_node_value(*a))
			pa(a, b, otpt, 1);
		else
			ra(a, b, otpt, 1);
	}	
}

void	medium_sort(t_node **a, t_node **b, t_node **otpt)
{
	(*otpt)->largest = get_largest(a);
	(*otpt)->smallest = get_smallest(a);
	pb(a, b, otpt, 1);
	pb(a, b, otpt, 1);
	tiny_sort(a, b, otpt);
	medium_sort_attach(a, b, otpt);
	while (!check_sorted(a))
	{
		if (last_node_value(*a) == (*otpt)->smallest)
			rra(a, b, otpt, 1);
		else
			ra(a, b, otpt, 1);
	}
}
