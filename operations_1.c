/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:22:24 by folim             #+#    #+#             */
/*   Updated: 2023/08/07 23:22:25 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a, t_node **b, t_node **otpt, int print)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (*a == NULL || (*a)->next == NULL)
	{
		ft_printf("KO\n");
		delete_list(a);
		delete_list(b);
		exit(1);
	}
	first = *a;
	second = first->next;
	third = first->next->next;
	second->next = first;
	first->next = third;
	*a = second;
	if (print == 1)
	{
		if (!optimizer(otpt, 2, 3))
			insert_back(otpt, 1);
	}
}

void	sb(t_node **a, t_node **b, t_node **otpt, int print)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (*b == NULL || (*b)->next == NULL)
	{
		ft_printf("KO\n");
		delete_list(a);
		delete_list(b);
		exit(1);
	}
	first = *b;
	second = first->next;
	third = first->next->next;
	second->next = first;
	first->next = third;
	*b = second;
	if (print == 1)
	{
		if (!optimizer(otpt, 1, 3))
			insert_back(otpt, 2);
	}
}

void	ss(t_node **a, t_node **b, t_node **otpt, int print)
{
	if (*a == NULL || (*a)->next == NULL || *b == NULL || (*b)->next == NULL)
	{
		ft_printf("KO\n");
		delete_list(a);
		delete_list(b);
		exit(1);
	}
	sa(a, b, otpt, 0);
	sb(a, b, otpt, 0);
	if (print == 1)
		insert_back(otpt, 3);
}

void	pa(t_node **a, t_node **b, t_node **otpt, int print)
{
	t_node	*temp_a;
	t_node	*temp_b;

	if (*b == NULL)
	{
		ft_printf("KO\n");
		delete_list(a);
		delete_list(b);
		exit(1);
	}
	temp_a = *a;
	temp_b = *b;
	*b = temp_b->next;
	temp_b->next = *a;
	*a = temp_b;
	if (print == 1)
		insert_back(otpt, 4);
}

void	pb(t_node **a, t_node **b, t_node **otpt, int print)
{
	t_node	*temp_a;
	t_node	*temp_b;

	if (*a == NULL)
	{
		ft_printf("KO\n");
		delete_list(a);
		delete_list(b);
		exit(1);
	}
	temp_a = *a;
	temp_b = *b;
	*a = temp_a->next;
	temp_a->next = *b;
	*b = temp_a;
	if (print == 1)
		insert_back(otpt, 5);
}