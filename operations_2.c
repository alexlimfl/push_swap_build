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

void ra(t_node **A, t_node **output, int print)
{
	t_node *first;
	t_node *curr;

	if(*A == NULL || (*A)->next == NULL)
	{
		ft_printf("Error (ra)\n");
		delete_list(A);
		exit(1);
	}
	first = *A;
	curr = *A;
	while(curr->next != NULL)
		curr = curr->next;

	*A = first->next;
	first->next = NULL;
	curr->next = first;
	if(print == 1)
	{
		if (!optimizer(output, 7, 8))
			insert_back(output, 6);
	}
}

void rb(t_node **B, t_node **output, int print)
{
	t_node *first;
	t_node *curr;

	if(*B == NULL || (*B)->next == NULL)
	{
		ft_printf("Error (rb)\n");
		delete_list(B);
		exit(1);
	}
	first = *B;
	curr = *B;
	while(curr->next != NULL)
		curr = curr->next;
	*B = first->next;
	first->next = NULL;
	curr->next = first;
	if(print == 1)
	{
		if (!optimizer(output, 6, 8))
			insert_back(output, 7);
	}
}

void rr(t_node **A, t_node **B, t_node **output, int print)
{
	if(*A == NULL || (*A)->next == NULL || *B == NULL || (*B)->next == NULL)
	{
		ft_printf("Error (rr)\n");
		delete_list(A);
		delete_list(B);
		exit(1);
	}
	ra(A, output, 0);
	rb(B, output, 0);
	if(print == 1)
		insert_back(output, 8);
}

void rra(t_node **A, t_node **output, int print)
{
	t_node *first;
	t_node *second_last;

	if(*A == NULL || (*A)->next == NULL)
	{
		ft_printf("Error (rra)\n");
		delete_list(A);
		exit(1);
	}
	first = *A;
	second_last = *A;
	while(second_last->next->next != NULL)
		second_last = second_last->next;
	*A = second_last->next;
	second_last->next->next = first;
	second_last->next = NULL;
	if(print == 1)
	{
		if (!optimizer(output, 10, 11))
			insert_back(output, 9);
	}
}

void rrb(t_node **B, t_node **output, int print)
{
	t_node *first;
	t_node *second_last;

	if(*B == NULL || (*B)->next == NULL)
	{
		ft_printf("Error (rrb)\n");
		delete_list(B);
		exit(1);
	}
	first = *B;
	second_last = *B;
	while(second_last->next->next != NULL)
		second_last = second_last->next;
	*B = second_last->next;
	second_last->next->next = first;
	second_last->next = NULL;
	if(print == 1)
	{
		if (!optimizer(output, 9, 11))
			insert_back(output, 10);
	}
}