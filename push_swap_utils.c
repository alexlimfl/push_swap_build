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

int		check_sorted(t_node **A)
{
	t_node *curr;
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

int		check_sorted_reverse(t_node **A)
{
	t_node *curr;
	int before;

	curr = (*A)->next;
	before = (*A)->x;	
	while(curr != NULL)
	{
		
		if (curr->x >= before)
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

int		get_largest(t_node **lst)
{
	int largest;
	t_node *curr;

	if(*lst == NULL)
		return (0);
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

int		get_highest_rank(t_node **lst)
{
	int highest_rank;
	t_node *curr;

	if(*lst == NULL)
		return (0);
	highest_rank = (*lst)->rank;
	curr = (*lst)->next;
	while (curr != NULL)
	{
		if (curr->rank > highest_rank)
			highest_rank = curr->rank;
		// ft_printf("Curr->rank: %d , HR = %d\n", curr->rank, highest_rank);
		curr = curr->next;
	}
	return (highest_rank);
}

int		get_smallest(t_node **lst)
{
	int smallest;
	t_node *curr;

	if(*lst == NULL)
		return (0);
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

int		get_lowest_rank(t_node **lst)
{
	int lowest_rank;
	t_node *curr;

	if(*lst == NULL)
		return (0);
	lowest_rank = (*lst)->rank;
	curr = (*lst)->next;
	while (curr != NULL)
	{
		if (curr->rank < lowest_rank)
			lowest_rank = curr->rank;
		curr = curr->next;
	}
	// ft_printf("Smallest = %d\n", smallest);
	return (lowest_rank);
}

void	tiny_sort(t_node **A, t_node **output)
{
	t_node *curr;
	int largest;
	int c;

	if(c_node(*A) > 3)
		return ;
	largest = get_largest(A);
	curr = *A;
	c = 1;
	while (!check_sorted(A))
	{
		if(c == 1 && largest == curr->x)
		{
			ra(A, output, 1);
			curr = *A;
			c = 1;
			// view_list(*A);
		}
		if(c == 2 && largest == curr->x)
		{
			rra(A, output, 1);
			curr = *A;
			c = 1;
			// view_list(*A);
		}
		if(c == 3 && largest == curr->x)
		{
			sa(A, output, 1);
			curr = *A;
			c = 1;
			// view_list(*A);
		}
		c++;
		curr = curr->next;
	}
}

void	check_duplicate(t_node **A)
{
	t_node *curr;
	t_node *temp;

	temp = *A;
	curr = temp->next;
	while(curr != NULL)
	{
		{
			if(temp->x == curr->x)
			{

				ft_printf("Error\n");
				exit(1);
			}
			curr = curr->next;
		}
		temp = temp->next;
		curr = temp->next;
	}
}

int		get_median(t_node *lst)
{
	int sum;
	int median;
	t_node *curr;

	sum = 0;
	curr = lst;

	while(curr != NULL)
	{
		sum = sum + curr->x;
		curr = curr->next;
	}
	median = sum/(c_node(lst));
	ft_printf("Sum = %d, Median = %d\n", sum, median);
	return (median);
}

int 	last_node_value(t_node *lst)
{
	t_node *curr;
	curr = lst;
	while(curr->next != NULL)
		curr = curr->next;
	return (curr->x);
}

void	medium_sort(t_node **A, t_node **B, t_node **output)
{
	int largest;
	int smallest;
	
	if(c_node(*A) > 5)
		return ;
	
	largest = get_largest(A);
	smallest = get_smallest(A);

	pb(A, B, output, 1);
	pb(A, B, output, 1);

	tiny_sort(A, output);

	while(*B != NULL)
	{
		// view_list(*A);
		// view_list(*B);

		if((*B)->x == largest && (*B)->x && get_largest(A) == last_node_value(*A))
			pa(A, B, output, 1);
		else if((*B)->x == smallest && get_smallest(A) == (*A)->x)
			pa(A, B, output, 1);
		else if((*B)->x > last_node_value(*A) && (*B)->x < (*A)->x)
			pa(A, B, output, 1);
		else if(check_sorted(A) && (*B)->x < (*A)->x)
			pa(A, B, output, 1);
		else if(check_sorted(A) && (*B)->x > last_node_value(*A))
			pa(A, B, output, 1);
		else
			ra(A, output, 1);
	}

	while(!check_sorted(A))
	{
		if(last_node_value(*A) == smallest)
			rra(A, output, 1);
		else
			ra(A, output, 1);
	}
}

t_node	*double_ll_convert(t_node **lst)
{
	if (*lst == NULL)
	{
		// ft_printf("Warning (double_ll_convert argument is NULL)\n");
		return (NULL);
	}

	t_node *prev;
	t_node *curr;
	t_node *tail;

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

void	label_ranking(t_node **lst)
{
	int max_rank;
	int	bigger_than_nb;
	int	nb;
	t_node *curr;
	t_node *curr_two;

	max_rank = c_node(*lst);
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

void 	label_position(t_node **lst)
{
	t_node *curr;
	int count;

	count = 1;
	curr = *lst;
	while(curr != NULL)
	{
		curr->position = count;
		curr = curr->next;
		count++;
	}
}

