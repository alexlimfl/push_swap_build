/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operation.print                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:55:24 by folim             #+#    #+#             */
/*   Updated: 2023/07/10 19:55:26 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int sa(t_node **A, int print, int n_operation)
{
    if(*A == NULL || (*A)->next == NULL)
    {
        ft_printf("Error (sa)\n");
        delete_list(A);
        exit(1);
    }

    t_node *first;
    t_node *second;
    t_node *third;

    first = *A;
    second = first->next;
    third = first->next->next;
    second->next = first;
    first->next = third;
    *A = second;
    if(print == 1)
        ft_printf("sa\n");
    n_operation += 1;
    return (n_operation);
}

int sb(t_node **B, int print, int n_operation)
{
    
    if(*B == NULL || (*B)->next == NULL)
    {
        ft_printf("Error (sb)\n");
        delete_list(B);
        exit(1);
    }
    
    t_node *first;
    t_node *second;
    t_node *third;

    first = *B;
    second = first->next;
    third = first->next->next;
    second->next = first;
    first->next = third;
    *B = second;
    if(print == 1)
        ft_printf("sb\n");
    n_operation += 1;
    return (n_operation);
}

int ss(t_node **A, t_node **B, int print, int n_operation)
{
    if(*A == NULL || (*A)->next == NULL || *B == NULL || (*B)->next == NULL)
    {
        ft_printf("Error (ss)\n");
        delete_list(A);
        delete_list(B);
        exit(1);
    }
    sa(A, 0, 0);
    sb(A, 0, 0);
    if(print == 1)
        ft_printf("ss\n");
    n_operation += 1;
    return (n_operation);
}

int pa(t_node **A, t_node **B, int print, int n_operation)
{
    if(*B == NULL)
    {
        ft_printf("Error (pa)\n");
        delete_list(A);
        delete_list(B);
        exit(1);
    }

    t_node *temp_A;
    t_node *temp_B;

    temp_A = *A;
    temp_B = *B;
    *B = temp_B->next;

    temp_B->next = *A;
    *A = temp_B;
    if(print == 1)
        ft_printf("pa\n");
    n_operation += 1;
    return (n_operation);
}

int pb(t_node **A, t_node **B, int print, int n_operation)
{
    if(*A == NULL)
    {
        ft_printf("Error (pb)\n");
        delete_list(A);
        delete_list(B);
        exit(1);
    }

    t_node *temp_A;
    t_node *temp_B;

    temp_A = *A;
    temp_B = *B;
    *A = temp_A->next;

    temp_A->next = *B;
    *B = temp_A;
    if(print == 1)
        ft_printf("pb\n");
    n_operation += 1;
    return (n_operation);
}

int ra(t_node **A, int print, int n_operation)
{
    if(*A == NULL || (*A)->next == NULL)
    {
        ft_printf("Error (ra)\n");
        delete_list(A);
        exit(1);
    }

    t_node *first;
    t_node *curr;

    first = *A;
    curr = *A;
    while(curr->next != NULL)
        curr = curr->next;

    *A = first->next;
    first->next = NULL;
    
    curr->next = first;
	if(print == 1)
    	ft_printf("ra\n");
    n_operation += 1;
    return (n_operation);
}

int rb(t_node **B, int print, int n_operation)
{
    if(*B == NULL || (*B)->next == NULL)
    {
        ft_printf("Error (rb)\n");
        delete_list(B);
        exit(1);
    }

    t_node *first;
    t_node *curr;

    first = *B;
    curr = *B;
    while(curr->next != NULL)
        curr = curr->next;

    *B = first->next;
    first->next = NULL;

    curr->next = first;
	if(print == 1)
		ft_printf("rb\n");
    n_operation += 1;
    return (n_operation);
}

int rr(t_node **A, t_node **B, int print, int n_operation)
{

	if(*A == NULL || (*A)->next == NULL || *B == NULL || (*B)->next == NULL)
    {
        ft_printf("Error (rr)\n");
        delete_list(A);
        delete_list(B);
        exit(1);
    }
	ra(A, 0, 0);
	rb(B, 0, 0);
    if(print == 1)
	    ft_printf("rr\n");
    n_operation += 1;
    return (n_operation);
}

int rra(t_node **A, int print, int n_operation)
{
	if(*A == NULL || (*A)->next == NULL)
    {
        ft_printf("Error (rra)\n");
        delete_list(A);
        exit(1);
    }
	t_node *first;
	t_node *second_last;

	first = *A;
	second_last = *A;
	while(second_last->next->next != NULL)
		second_last = second_last->next;
	*A = second_last->next;
	second_last->next->next = first;
	second_last->next = NULL;
	if(print == 1)
		ft_printf("rra\n");
    n_operation += 1;
    return (n_operation);
}

int rrb(t_node **B, int print, int n_operation)
{
	if(*B == NULL || (*B)->next == NULL)
    {
        ft_printf("Error (rrb)\n");
        delete_list(B);
        exit(1);
    }
	t_node *first;
	t_node *second_last;

	first = *B;
	second_last = *B;
	while(second_last->next->next != NULL)
		second_last = second_last->next;
	*B = second_last->next;
	second_last->next->next = first;
	second_last->next = NULL;
	if(print == 1)
		ft_printf("rrb\n");
    n_operation += 1;
    return (n_operation);
}

int rrr(t_node **A, t_node **B, int print, int n_operation)
{
	if(*A == NULL || (*A)->next == NULL || *B == NULL || (*B)->next == NULL)
    {
        ft_printf("Error (rrr)\n");
        delete_list(A);
        delete_list(B);
        exit(1);
    }
	rra(A, 0, 0);
	rrb(B, 0, 0);
    if(print == 1)
	    ft_printf("rrr\n");
    n_operation += 1;
    return (n_operation);
}