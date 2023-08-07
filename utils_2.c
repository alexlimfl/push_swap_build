/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:13:54 by folim             #+#    #+#             */
/*   Updated: 2023/08/07 23:13:56 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*double_ll_convert(t_node **lst)
{
	t_node *prev;
	t_node *curr;
	t_node *tail;

	if (*lst == NULL)
		return (NULL);
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

void insert_back(t_node **lst, int value)
{
	t_node  *newnode;
    t_node  *curr;

	newnode = malloc(sizeof(t_node));
	newnode->x = value;
	newnode->next = NULL;
	if (*lst == NULL)
	{
		*lst = newnode;
		return;
	}
	curr = *lst;
	while(curr->next != NULL)
		curr = curr->next;
	curr->next = newnode;
}

void delete_list(t_node **lst)
{
	t_node  *curr;

	curr = *lst;
	while(curr != NULL)
	{	
		t_node *prenode;
		prenode = curr;
		curr = curr->next;
		free(prenode);
	}
	*lst = NULL;
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