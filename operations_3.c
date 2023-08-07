/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:25:37 by folim             #+#    #+#             */
/*   Updated: 2023/08/07 23:25:38 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		insert_back(output, 11);
}

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
        if(curr->x != 0)
			ft_printf("%s\n", str[curr->x - 1]);
        curr = curr->next;
    }
	// ft_printf("N_op: %d\n", c_node(*output) - 1);
}

int	optimizer(t_node **output, int find, int substi)
{
    t_node *curr;
	
	if (*output == NULL)
		return (0);
	curr = double_ll_convert(output);
	while (curr != NULL && curr->x != 4 && curr->x != 5)
		curr = curr->prev;
	if (curr == NULL)
		return (0);
	curr = curr->next;
	while (curr != NULL && curr->x != 4 && curr->x != 5)
	{
		if (curr->x == find)
		{
			curr->x = substi;
			return (1);
		}
		curr = curr->next;
	}
	return (0);
}

void mega_sort(t_node **A, t_node **B, t_node **output)
{	
	t_node	*curr;
	t_var	r;

	curr = *A;
	insert_back(output, 0);
	(*output)->num_chunk = 10;
	label_ranking(A);
	inner_chunk_maker(output, c_node(*A));
	outer_chunk_maker(output, c_node(*A));
	lable_chunk(A, output);
	push_top_chunk(A, B, &r, output);
	quick_sort(A, B, output);
	final_sort(A, output);
}