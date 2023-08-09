/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:59:39 by folim             #+#    #+#             */
/*   Updated: 2023/08/07 22:59:46 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_node **a)
{
	t_node	*curr;
	int		before;

	curr = (*a)->next;
	before = (*a)->x;
	while (curr != NULL)
	{
		if (curr->x <= before)
			return (0);
		before = curr->x;
		curr = curr->next;
	}
	return (1);
}

int	check_sorted_reverse(t_node **a)
{
	t_node	*curr;
	int		before;

	curr = (*a)->next;
	before = (*a)->x;
	while (curr != NULL)
	{
		if (curr->x >= before)
			return (0);
		before = curr->x;
		curr = curr->next;
	}
	return (1);
}

void	check_duplicate(t_node **a)
{
	t_node	*curr;
	t_node	*find_curr;

	curr = *a;
	while (curr->next != NULL)
	{
		find_curr = curr->next;
		while (find_curr != NULL)
		{
			if (find_curr->x == curr->x)
				exit_message();
			find_curr = find_curr->next;
		}
		curr = curr->next;
	}
}

void	no_space_and_character_allowed(char **str)
{
	int	c;
	int	d;

	c = 1;
	while (str[c])
	{
		d = 0;
		while (str[c][d])
		{
			if (c > 1 && str[c][d] == ' ')
				exit_message();
			if (str[1][d] == ' ')
			{
				if (str[2])
					exit_message();
			}
			if (str[c][d] != ' ' && str[c][d] != '-'
				&& (str[c][d] < '0' || str[c][d] > '9'))
				exit_message();
			d++;
		}
		c++;
	}
}

int	check_sorted_plus(t_node **a)
{
	t_node	*curr;
	int		b4;

	curr = (*a)->next;
	b4 = (*a)->rank;
	while (curr != NULL)
	{
		if (curr->rank < b4 && !(curr->rank == get_lowest_rank(a)
				&& b4 == get_highest_rank(a)))
			return (0);
		b4 = curr->rank;
		curr = curr->next;
	}
	return (1);
}
