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

void	sa(t_node **A, t_node **otpt, int print)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (*A == NULL || (*A)->next == NULL)
	{
		ft_printf("Error (sa)\n");
		delete_list(A);
		exit(1);
	}
	first = *A;
	second = first->next;
	third = first->next->next;
	second->next = first;
	first->next = third;
	*A = second;
	if (print == 1)
	{
		if (!optimizer(otpt, 2, 3))
			insert_back(otpt, 1);
	}
}

void	sb(t_node **B, t_node **otpt, int print)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (*B == NULL || (*B)->next == NULL)
	{
		ft_printf("Error (sb)\n");
		delete_list(B);
		exit(1);
	}
	first = *B;
	second = first->next;
	third = first->next->next;
	second->next = first;
	first->next = third;
	*B = second;
	if (print == 1)
	{
		if (!optimizer(otpt, 1, 3))
			insert_back(otpt, 2);
	}
}

void	ss(t_node **A, t_node **B, t_node **otpt, int print)
{
	if (*A == NULL || (*A)->next == NULL || *B == NULL || (*B)->next == NULL)
	{
		ft_printf("Error (ss)\n");
		delete_list(A);
		delete_list(B);
		exit(1);
	}
	sa(A, otpt, 0);
	sb(A, otpt, 0);
	if (print == 1)
		insert_back(otpt, 3);
}

void	pa(t_node **A, t_node **B, t_node **otpt, int print)
{
	t_node	*temp_a;
	t_node	*temp_b;

	if (*B == NULL)
	{
		ft_printf("Error (pa)\n");
		delete_list(A);
		delete_list(B);
		exit(1);
	}
	temp_a = *A;
	temp_b = *B;
	*B = temp_b->next;
	temp_b->next = *A;
	*A = temp_b;
	if (print == 1)
		insert_back(otpt, 4);
}

void	pb(t_node **A, t_node **B, t_node **otpt, int print)
{
	t_node	*temp_a;
	t_node	*temp_b;

	if (*A == NULL)
	{
		ft_printf("Error (pb)\n");
		delete_list(A);
		delete_list(B);
		exit(1);
	}
	temp_a = *A;
	temp_b = *B;
	*A = temp_a->next;
	temp_a->next = *B;
	*B = temp_a;
	if (print == 1)
		insert_back(otpt, 5);
}