/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedListFunction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:38:21 by folim             #+#    #+#             */
/*   Updated: 2023/07/10 18:38:23 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"









void insert_front(t_node **lst, int value)
{
	t_node *newnode;
	newnode = malloc(sizeof(t_node));
	newnode->x = value;

	if (*lst == NULL)
	{
		newnode->next = NULL;
		*lst = newnode;
		ft_printf("First node in the list with value '%d' is added.\n", value);
		return;
	}
	newnode->next = *lst;
	*lst = newnode;
	ft_printf("t_node with value '%d' is added at the front.\n", value);
}

void insert_after(t_node *lst, int value)
{
	if(lst == NULL)
	{
		ft_printf("No node found\n");
		return;
	}
	t_node *newNode = malloc(sizeof(t_node));
	// t_node *curr = *lst; // dereference if **lst are used instead, *lst->next unusable
	newNode->x = value;
	newNode->next = lst->next;
	lst->next = newNode;
	ft_printf("t_node with value '%d' is added after '%d'.\n", value, lst->x);
}

void insert_sorted(t_node **lst, int value)
{
	if(*lst == NULL || (*lst)->x >= value)
	{
		insert_front(lst, value);
		return;
	}
	t_node *curr;
	curr = *lst;
	while(curr->next != NULL)
	{
		if(curr->next->x >= value)
			break;
		curr = curr->next;
	}
	insert_after(curr, value);
	// if (*lst == NULL)
	// {
	// 	newNode->next = NULL;
	// 	*lst = newNode;
	// 	ft_printf("t_node not found for sorting, node with value '%d' is added as the first node.\n", value);
	// 	return;
	// }
}

void delete_an_element(t_node **lst, int value)
{
	if (*lst == NULL)
	{
		ft_printf("List is empty\n");
		return;
	}
	if ((*lst)->x == value)
	{
		t_node *to_remove;
		to_remove = (*lst);
		ft_printf("Element '%d' is deleted.\n", (*lst)->x);
		*lst = (*lst)->next;
		free(to_remove);
		return;
	}
	t_node *curr;
	curr = *lst;
	while (curr->next != NULL)
	{
		if (curr->next->x == value)
		{
			t_node *to_remove1;
			to_remove1 = curr->next;
			ft_printf("Element '%d' is deleted.\n", curr->next->x);
			curr->next = curr->next->next;
			free(to_remove1);
			return;
		}
		curr = curr->next;
	}
	ft_printf("Element '%d' not found\n", value);
}

void delete_all_element(t_node **lst, int value)
{
	int count;
	count = 0;
	if (*lst == NULL)
	{
		count = ft_printf("List is empty\n");
		return;
	}
	while ((*lst)->x == value)
	{
		t_node *to_remove;
		to_remove = (*lst);
		count = ft_printf("Element '%d' is deleted.\n", (*lst)->x);
		*lst = (*lst)->next;
		free(to_remove);
	}
	t_node *curr;
	curr = *lst;
	while (curr->next != NULL)
	{
		while (curr->next->x == value)
		{
			t_node *to_remove1;
			to_remove1 = curr->next;
			count = ft_printf("Element '%d' is deleted.\n", curr->next->x);
			curr->next = curr->next->next;
			if (curr->next == NULL)
			{
				free(to_remove1);
				return;
			}
			free(to_remove1);
		}
		curr = curr->next;
	}
	if (count == 0)
		ft_printf("Element '%d' not found\n", value);
}

void reverse(t_node **lst)
{
	t_node *curr, *previous, *after;
	curr = *lst;
	previous = NULL;
	while (curr != NULL)
	{
		after = curr->next;
		curr->next = previous;
		previous = curr;
		curr = after;
	}
	(*lst)->next = NULL;
	*lst = previous;
	ft_printf("Linked list is reversed\n");
}

int check_loop(t_node *lst)
{
	t_node *slow, *fast;
	slow = lst;
	fast = lst;
	while (slow != NULL && fast != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			ft_printf("Linked list contains loop.\n");
			return (1);
		}
	}
	ft_printf("Linked list contains no loop.\n");
	return (0);
}



