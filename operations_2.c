/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:24:11 by folim             #+#    #+#             */
/*   Updated: 2023/08/07 23:24:13 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a, t_node **b, t_node **otpt, int print)
{
	t_node	*first;
	t_node	*curr;

	if (*a == NULL || (*a)->next == NULL)
		clear_ll_exit(a, b, otpt, 0);
	first = *a;
	curr = *a;
	while (curr->next != NULL)
		curr = curr->next;
	*a = first->next;
	first->next = NULL;
	curr->next = first;
	if (print == 1)
	{
		if (!optimizer(otpt, 7, 8))
			insert_back(otpt, 6);
	}
}

void	rb(t_node **a, t_node **b, t_node **otpt, int print)
{
	t_node	*first;
	t_node	*curr;

	if (*b == NULL || (*b)->next == NULL)
		clear_ll_exit(a, b, otpt, 0);
	first = *b;
	curr = *b;
	while (curr->next != NULL)
		curr = curr->next;
	*b = first->next;
	first->next = NULL;
	curr->next = first;
	if (print == 1)
	{
		if (!optimizer(otpt, 6, 8))
			insert_back(otpt, 7);
	}
}

void	rr(t_node **a, t_node **b, t_node **otpt, int print)
{
	if (*a == NULL || (*a)->next == NULL || *b == NULL || (*b)->next == NULL)
		clear_ll_exit(a, b, otpt, 0);
	ra(a, b, otpt, 0);
	rb(b, b, otpt, 0);
	if (print == 1)
		insert_back(otpt, 8);
}

void	rra(t_node **a, t_node **b, t_node **otpt, int print)
{
	t_node	*first;
	t_node	*second_last;

	if (*a == NULL || (*a)->next == NULL)
		clear_ll_exit(a, b, otpt, 0);
	first = *a;
	second_last = *a;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	*a = second_last->next;
	second_last->next->next = first;
	second_last->next = NULL;
	if (print == 1)
	{
		if (!optimizer(otpt, 10, 11))
			insert_back(otpt, 9);
	}
}

void	rrb(t_node **a, t_node **b, t_node **otpt, int print)
{
	t_node	*first;
	t_node	*second_last;

	if (*b == NULL || (*b)->next == NULL)
		clear_ll_exit(a, b, otpt, 0);
	first = *b;
	second_last = *b;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	*b = second_last->next;
	second_last->next->next = first;
	second_last->next = NULL;
	if (print == 1)
	{
		if (!optimizer(otpt, 9, 11))
			insert_back(otpt, 10);
	}
}
