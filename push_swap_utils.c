/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:13:24 by folim             #+#    #+#             */
/*   Updated: 2023/07/10 19:13:26 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_atoi(const char *str)
{
	int	sign;
	int	i;
	int	output;

	i = 0;
	sign = 1;
	output = 0;
	while (str[i] != 0 && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		output = (output * 10) + (str[i] - '0');
		i++;
	}
	return (output * sign);
}

int		check_sorted(Node **A)
{
	Node *curr;
	int before;

	curr = (*A)->next;
	before = (*A)->x;	
	while(curr != NULL)
	{
		
		if (curr->x <= before)
		{
			// ft_printf("Not sorted\n");
			return (0);
		}
		before = curr->x;
		curr = curr->next;
	}
	// ft_printf("Sorted\n");
	return (1);
}

int		get_largest(Node **lst)
{
	int largest;
	Node *curr;

	largest = (*lst)->x;
	curr = (*lst)->next;
	while (curr != NULL)
	{
		if (curr->x > largest)
			largest = curr->x;
		curr = curr->next;
	}
	// ft_printf("Largest = %d\n", largest);
	return (largest);
}

int		get_smallest(Node **lst)
{
	int smallest;
	Node *curr;

	smallest = (*lst)->x;
	curr = (*lst)->next;
	while (curr != NULL)
	{
		if (curr->x < smallest)
			smallest = curr->x;
		curr = curr->next;
	}
	// ft_printf("Smallest = %d\n", smallest);
	return (smallest);
}

int		tiny_sort(Node **A, int n_operation)
{
	Node *curr;
	int largest;
	int c;

	if(count_node(*A) > 3)
		return (n_operation);
	largest = get_largest(A);
	curr = *A;
	c = 1;
	while (!check_sorted(A))
	{
		if(c == 1 && largest == curr->x)
		{
			ra(A, 0);
			n_operation += 1;
			curr = *A;
			c = 1;
			view_list(*A);
		}
		if(c == 2 && largest == curr->x)
		{
			rra(A, 0);
			n_operation += 1;
			curr = *A;
			c = 1;
			view_list(*A);
		}
		if(c == 3 && largest == curr->x)
		{
			sa(A, 0);
			n_operation += 1;
			curr = *A;
			c = 1;
			view_list(*A);
		}
		c++;
		curr = curr->next;
	}
	return (n_operation);
}

void	check_duplicate(Node **A)
{
	Node *curr;
	Node *temp;

	temp = *A;
	curr = temp->next;
	while(curr != NULL)
	{
		
		while(curr != NULL)
		{
			if(temp->x == curr->x)
			{

				ft_printf("%d\n", temp->x);
				ft_printf("%d\n", curr->x);
				ft_printf("Error (Duplicate found)\n");
				exit(1);
			}
			curr = curr->next;
		}
		temp = temp->next;
		curr = temp->next;
	}
}

int		get_median(Node *lst)
{
	int sum;
	int median;
	Node *curr;

	sum = 0;
	curr = lst;

	while(curr != NULL)
	{
		sum = sum + curr->x;
		curr = curr->next;
	}
	median = sum/(count_node(lst));
	ft_printf("Sum = %d, Median = %d\n", sum, median);
	return (median);
}

int 	last_node_value(Node *lst)
{
	Node *curr;
	curr = lst;
	while(curr->next != NULL)
		curr = curr->next;
	return (curr->x);
}

int		medium_sort(Node **A, Node **B, int n_operation)
{
	int largest;
	int smallest;
	
	if(count_node(*A) > 5)
		return (n_operation);
	
	largest = get_largest(A);
	smallest = get_smallest(A);

	pb(A, B);
	pb(A, B);
	n_operation += 2;

	n_operation = tiny_sort(A, n_operation);

	while(*B != NULL)
	{
		// view_list(*A);
		// view_list(*B);

		if((*B)->x == largest && (*B)->x && get_largest(A) == last_node_value(*A))
		{
			// ft_printf("CHECK 1\n");
			pa(A, B);
		}
		else if((*B)->x == smallest && get_smallest(A) == (*A)->x)
		{
			// ft_printf("CHECK 2\n");
			pa(A, B);
		}
		else if((*B)->x > last_node_value(*A) && (*B)->x < (*A)->x)
		{
			// ft_printf("CHECK 3\n");
			pa(A, B);
		}
		else if(check_sorted(A) && (*B)->x < (*A)->x)
		{
			// ft_printf("CHECK 4\n");
			pa(A, B);
		}
		else if(check_sorted(A) && (*B)->x > last_node_value(*A))
		{
			// ft_printf("CHECK 4.5\n");
			pa(A, B);
		}
		else
		{
			// ft_printf("CHECK 5\n");
			ra(A, 0);
		}
		n_operation += 1;
	}

	while(!check_sorted(A))
	{
		// ft_printf("CHECK 6\n");
		ra(A, 0);
		n_operation += 1;
	}
	return (n_operation);
}

Node	*double_ll_convert(Node **lst)
{
	if (*lst == NULL)
	{
		ft_printf("Error (double_ll_convert)\n");
		exit(1);
	}

	Node *prev;
	Node *curr;
	Node *tail;

	prev = NULL;
	curr = *lst;

	while (curr != NULL)
	{
		curr->prev = prev;
		prev = curr;
		curr = curr->next;
	}
	tail = prev;
	return (tail);
}

void	label_ranking(Node **lst)
{
	int max_rank;
	int	bigger_than_nb;
	int	nb;
	Node *curr;
	Node *curr_two;

	max_rank = count_node(*lst);
	curr = *lst;
	curr_two = *lst;
	while(curr != NULL)
	{
		nb = curr->x;
		curr_two = *lst;
		bigger_than_nb = 0;
		while(curr_two != NULL)
		{
			if (curr_two->x > nb)
				bigger_than_nb += 1;
			curr_two = curr_two->next;
		}
		curr->rank = max_rank - bigger_than_nb;
		curr = curr->next;
	}
}


void 	label_position(Node **lst)
{
	Node *curr;
	int count;

	count = 0;
	curr = *lst;
	while(curr != NULL)
	{
		curr->position = count;
		curr = curr->next;
		count++;
	}
}

int		mega_sort_one(Node **A, Node **B, int n_operation)
{
	Node *A_tail;
	A_tail = double_ll_convert(A);

	label_ranking(A);
	label_position(A);
	view_list(*A);
	view_list_rank(*A);
	view_list_position(*A);
	view_list_backward(A_tail);

	return (n_operation);
}