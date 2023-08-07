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

void sa(t_node **A, t_node **output, int print)
{
    t_node	*first;
    t_node	*second;
    t_node	*third;

    if(*A == NULL || (*A)->next == NULL)
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
    if(print == 1)
    {
        if (!optimizer(output, 2, 3))
			insert_back(output, 1);
    }
}

void sb(t_node **B, t_node **output, int print)
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
    if(print == 1)
    {
		if (!optimizer(output, 1, 3))
    		insert_back(output, 2);
    }
}

void ss(t_node **A, t_node **B, t_node **output, int print)
{
    if(*A == NULL || (*A)->next == NULL || *B == NULL || (*B)->next == NULL)
    {
        ft_printf("Error (ss)\n");
        delete_list(A);
        delete_list(B);
        exit(1);
    }
    sa(A, output, 0);
    sb(A, output, 0);
    if(print == 1)
        insert_back(output, 3);
}

void pa(t_node **A, t_node **B, t_node **output, int print)
{
	t_node	*temp_A;
	t_node	*temp_B;

    if(*B == NULL)
    {
		ft_printf("Error (pa)\n");
		delete_list(A);
		delete_list(B);
		exit(1);
    }
	temp_A = *A;
	temp_B = *B;
	*B = temp_B->next;
	temp_B->next = *A;
	*A = temp_B;
	if(print == 1)
		insert_back(output, 4);
}

void pb(t_node **A, t_node **B, t_node **output, int print)
{
    t_node *temp_A;
    t_node *temp_B;

    if(*A == NULL)
    {
        ft_printf("Error (pb)\n");
        delete_list(A);
        delete_list(B);
        exit(1);
    }
    temp_A = *A;
    temp_B = *B;
    *A = temp_A->next;
    temp_A->next = *B;
    *B = temp_A;
    if(print == 1)
        insert_back(output, 5);
}