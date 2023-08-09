/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:18:21 by folim             #+#    #+#             */
/*   Updated: 2023/08/07 23:18:23 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	c_n(t_node *lst)
{
	int		count;
	t_node	*curr;

	count = 0;
	curr = lst;
	while (curr != NULL)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}

int	get_largest(t_node **lst)
{
	int		largest;
	t_node	*curr;

	if (*lst == NULL)
		return (0);
	largest = (*lst)->x;
	curr = (*lst)->next;
	while (curr != NULL)
	{
		if (curr->x > largest)
			largest = curr->x;
		curr = curr->next;
	}
	return (largest);
}

int	get_highest_rank(t_node **lst)
{
	int		highest_rank;
	t_node	*curr;

	if (*lst == NULL)
		return (0);
	highest_rank = (*lst)->rank;
	curr = (*lst)->next;
	while (curr != NULL)
	{
		if (curr->rank > highest_rank)
			highest_rank = curr->rank;
		curr = curr->next;
	}
	return (highest_rank);
}

int	get_smallest(t_node **lst)
{
	int		smallest;
	t_node	*curr;

	if (*lst == NULL)
		return (0);
	smallest = (*lst)->x;
	curr = (*lst)->next;
	while (curr != NULL)
	{
		if (curr->x < smallest)
			smallest = curr->x;
		curr = curr->next;
	}
	return (smallest);
}

int	get_lowest_rank(t_node **lst)
{
	int		lowest_rank;
	t_node	*curr;

	if (*lst == NULL)
		return (0);
	lowest_rank = (*lst)->rank;
	curr = (*lst)->next;
	while (curr != NULL)
	{
		if (curr->rank < lowest_rank)
			lowest_rank = curr->rank;
		curr = curr->next;
	}
	return (lowest_rank);
}
