/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:55:24 by folim             #+#    #+#             */
/*   Updated: 2023/07/10 19:55:26 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(Node **A, int c)
{
    if(*A == NULL || (*A)->next == NULL)
    {
        ft_printf("Error (sa)\n");
        delete_list(A);
        exit(1);
    }

    Node *first;
    Node *second;
    Node *third;

    first = *A;
    second = first->next;
    third = first->next->next;
    second->next = first;
    first->next = third;
    *A = second;
    if(c == 0)
        ft_printf("sa\n");
}

void sb(Node **B, int c)
{
    
    if(*B == NULL || (*B)->next == NULL)
    {
        ft_printf("Error (sb)\n");
        delete_list(B);
        exit(1);
    }
    
    Node *first;
    Node *second;
    Node *third;

    first = *B;
    second = first->next;
    third = first->next->next;
    second->next = first;
    first->next = third;
    *B = second;
    if(c == 0)
        ft_printf("sb\n");
}

void ss(Node **A, Node **B)
{
    if(*A == NULL || (*A)->next == NULL || *B == NULL || (*B)->next == NULL)
    {
        ft_printf("Error (ss)\n");
        delete_list(A);
        delete_list(B);
        exit(1);
    }
    sa(A, 1);
    sb(A, 1);
    ft_printf("ss\n");
}

void pa(Node **A, Node **B)
{
    if(*B == NULL)
    {
        ft_printf("Error (pa)\n");
        delete_list(A);
        delete_list(B);
        exit(1);
    }

    Node *temp_A;
    Node *temp_B;

    temp_A = *A;
    temp_B = *B;
    *B = temp_B->next;

    temp_B->next = *A;
    *A = temp_B;

    ft_printf("pa\n");
}

void pb(Node **A, Node **B)
{
    if(*A == NULL)
    {
        ft_printf("Error (pb)\n");
        delete_list(A);
        delete_list(B);
        exit(1);
    }

    Node *temp_A;
    Node *temp_B;

    temp_A = *A;
    temp_B = *B;
    *A = temp_A->next;

    temp_A->next = *B;
    *B = temp_A;

    ft_printf("pb\n");
}

void ra(Node **A, int c)
{
    if(*A == NULL || (*A)->next == NULL)
    {
        ft_printf("Error (ra)\n");
        delete_list(A);
        exit(1);
    }

    Node *first;
    Node *curr;

    first = *A;
    curr = *A;
    while(curr->next != NULL)
        curr = curr->next;

    *A = first->next;
    first->next = NULL;
    
    curr->next = first;
	if(c == 0)
    	ft_printf("ra\n");
}

void rb(Node **B, int c)
{
    if(*B == NULL || (*B)->next == NULL)
    {
        ft_printf("Error (rb)\n");
        delete_list(B);
        exit(1);
    }

    Node *first;
    Node *curr;

    first = *B;
    curr = *B;
    while(curr->next != NULL)
        curr = curr->next;

    *B = first->next;
    first->next = NULL;

    curr->next = first;
	if(c == 0)
		ft_printf("rb\n");
}

void rr(Node **A, Node **B)
{

	if(*A == NULL || (*A)->next == NULL || *B == NULL || (*B)->next == NULL)
    {
        ft_printf("Error (rr)\n");
        delete_list(A);
        delete_list(B);
        exit(1);
    }
	ra(A, 1);
	rb(B, 1);
	ft_printf("rr\n");
}

void rra(Node **A, int c)
{
	if(*A == NULL || (*A)->next == NULL)
    {
        ft_printf("Error (rra)\n");
        delete_list(A);
        exit(1);
    }
	Node *first;
	Node *second_last;

	first = *A;
	second_last = *A;
	while(second_last->next->next != NULL)
		second_last = second_last->next;
	*A = second_last->next;
	second_last->next->next = first;
	second_last->next = NULL;
	if(c == 0)
		ft_printf("rra\n");
}
void rrb(Node **B, int c)
{
	if(*B == NULL || (*B)->next == NULL)
    {
        ft_printf("Error (rrb)\n");
        delete_list(B);
        exit(1);
    }
	Node *first;
	Node *second_last;

	first = *B;
	second_last = *B;
	while(second_last->next->next != NULL)
		second_last = second_last->next;
	*B = second_last->next;
	second_last->next->next = first;
	second_last->next = NULL;
	if(c == 0)
		ft_printf("rrb\n");
}

void rrr(Node **A, Node **B)
{
	if(*A == NULL || (*A)->next == NULL || *B == NULL || (*B)->next == NULL)
    {
        ft_printf("Error (rrr)\n");
        delete_list(A);
        delete_list(B);
        exit(1);
    }
	rra(A, 1);
	rrb(B, 1);
	ft_printf("rrr\n");
}