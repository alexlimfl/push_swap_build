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

void    print_output(t_node **output)
{
    t_node *curr;
    const char *str[11];

    str[0] = "sa";
    str[1] = "sb";
    str[2] = "ss";
    str[3] = "pa";
    str[4] = "pb";
    str[5] = "ra";
    str[6] = "rb";
    str[7] = "rr";
    str[8] = "rra";
    str[9] = "rrb";
    str[10] = "rrr";
    
    curr = *output;
    while (curr != NULL)
    {
        ft_printf("%s\n", str[curr->x - 1]);
        curr = curr->next;
    }
	// ft_printf("N_op: %d\n", c_node(*output));
}

int	optimizer(t_node **output, int find, int substi)
{
    t_node *curr;
	t_node *durr;
	
	// ft_printf("CHECK ^^^^^^^^^^^^^^^^^\n");
	// print_output(output);
	if (*output == NULL)
		return (0);
	// have to use double_ll, scan from the back
	curr = double_ll_convert(output);
	while (curr != NULL && curr->x != 4 && curr->x != 5)
		curr = curr->prev;
	if (curr == NULL)
		return (0);
	durr = curr->next;
	while (durr != NULL && durr->x != 4 && durr->x != 5)
	{
			// ft_printf(">>>>>>>>>>>>>>>>>>>%d, %d\n", find, substi);
		if (durr->x == find)
		{
			durr->x = substi;
			// ft_printf(">>>>>>>>>>>>>>>>>>>>>>>>%d, %d\n", find, substi);
			// exit(0);
			return (1);
		}
		durr = durr->next;
	}
	// ft_printf("failed >>>>>>>>>>>>>>>>>>>\n");
	return (0);
}

void sa(t_node **A, t_node **output, int print)
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
    {
        if (!optimizer(output, 2, 3))
			insert_back(output, 1);
        // ft_printf("sa\n");
    }
}

void sb(t_node **B, t_node **output, int print)
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
    {
        if (!optimizer(output, 1, 3))
    		insert_back(output, 2);
        // ft_printf("sb\n");
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
    {
        insert_back(output, 3);
        // ft_printf("ss\n");
    }
}

void pa(t_node **A, t_node **B, t_node **output, int print)
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
    {
        insert_back(output, 4);
        // ft_printf("pa\n");
    }
}

void pb(t_node **A, t_node **B, t_node **output, int print)
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
    {
        insert_back(output, 5);
        // ft_printf("pb\n");
    }
}

void ra(t_node **A, t_node **output, int print)
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
    {
		if (!optimizer(output, 7, 8))
        	insert_back(output, 6);
    	// ft_printf("ra\n");
    }
}

void rb(t_node **B, t_node **output, int print)
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
    {
        if (!optimizer(output, 6, 8))
			insert_back(output, 7);
		// ft_printf("rb\n");
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
    {
        insert_back(output, 8);
	    // ft_printf("rr\n");
    }
}

void rra(t_node **A, t_node **output, int print)
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
    {
        if (!optimizer(output, 10, 11))
        	insert_back(output, 9);
		// ft_printf("rra\n");
    }
}

void rrb(t_node **B, t_node **output, int print)
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
    {
        if (!optimizer(output, 9, 11))
     	   insert_back(output, 10);
		// ft_printf("rrb\n");
    }
}

void rrr(t_node **A, t_node **B, t_node **output, int print)
{
	if(*A == NULL || (*A)->next == NULL || *B == NULL || (*B)->next == NULL)
    {
        ft_printf("Error (rrr)\n");
        delete_list(A);
        delete_list(B);
        exit(1);
    }
	rra(A, output, 0);
	rrb(B, output, 0);
    if(print == 1)
    {
        insert_back(output, 11);
	    // ft_printf("rrr\n");
    }
}





