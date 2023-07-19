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

void view_list(Node *lst)
{
	ft_printf("List:\n");
	if (lst == NULL)
	{
		ft_printf("Empty\n");
	}
    while (lst != NULL)
    {
        // ft_printf("%d\n", curr);
        ft_printf("%d\n", lst->x);
        lst = lst->next;
    }
        // ft_printf("%d\n", lst);
}

void view_list_rank(Node *lst)
{
	ft_printf("List (Ranking):\n");
	if (lst == NULL)
		ft_printf("Empty\n");
    while (lst != NULL)
    {
        ft_printf("%d\n", lst->rank);
        lst = lst->next;
    }
}

void view_list_position(Node *lst)
{
	ft_printf("List (Position):\n");
	if (lst == NULL)
		ft_printf("Empty\n");
    while (lst != NULL)
    {
        ft_printf("%d\n", lst->position);
        lst = lst->next;
    }
}

void view_list_backward(Node *lst)
{
	ft_printf("List (backward):\n");
	if(lst == NULL)
	{
		ft_printf("Empty.\n");
		return;
	}
	while (lst != NULL)
    {
		ft_printf("%d\n", lst->x);
        lst = lst->prev;
    }
}

void insert_back(Node **lst, int value)
{
	Node *newnode, *curr;
	newnode = malloc(sizeof(Node));
	newnode->x = value;
	newnode->next = NULL;

	if (*lst == NULL) //if value pointed by *root is NULL
	{
		*lst = newnode; //*root is assigned to point at value pointed by *newnode
		// ft_printf("First node in the list with value '%d' is added.\n", value);
		return;
	}
	curr = *lst; //*curr is assigned to point at value pointed by *root
	while(curr->next != NULL)
		curr = curr->next;
	curr->next = newnode;
	// ft_printf("Node with value '%d' is added at the end.\n", value);
	// **lst points at &root/root's address/root pointer/pointer to a pointer
	// **lst --> *root pointer
	//  *lst points to variable of &root/root pointer/the allocated memory pointed by root pointer
	//  *lst --> *root pointer --> malloc(sizeof(Node))
	// 		**lst == &root
	//  	 *lst == *root
	//   	  lst ==  root->x
}

void delete_list(Node **lst)
{
	Node *curr;
	curr = *lst;
	while(curr != NULL)
	{	
		Node *prenode;
		prenode = curr;
		curr = curr->next;
		free(prenode);
	}
	*lst = NULL;
	ft_printf("Deallocation done and list deleted.\n");
}

void insert_front(Node **lst, int value)
{
	Node *newnode;
	newnode = malloc(sizeof(Node));
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
	ft_printf("Node with value '%d' is added at the front.\n", value);
}

void insert_after(Node *lst, int value)
{
	if(lst == NULL)
	{
		ft_printf("No node found\n");
		return;
	}
	Node *newNode = malloc(sizeof(Node));
	// Node *curr = *lst; // dereference if **lst are used instead, *lst->next unusable
	newNode->x = value;
	newNode->next = lst->next;
	lst->next = newNode;
	ft_printf("Node with value '%d' is added after '%d'.\n", value, lst->x);
}

void insert_sorted(Node **lst, int value)
{
	if(*lst == NULL || (*lst)->x >= value)
	{
		insert_front(lst, value);
		return;
	}
	Node *curr;
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
	// 	ft_printf("Node not found for sorting, node with value '%d' is added as the first node.\n", value);
	// 	return;
	// }
}

void delete_an_element(Node **lst, int value)
{
	if (*lst == NULL)
	{
		ft_printf("List is empty\n");
		return;
	}
	if ((*lst)->x == value)
	{
		Node *to_remove;
		to_remove = (*lst);
		ft_printf("Element '%d' is deleted.\n", (*lst)->x);
		*lst = (*lst)->next;
		free(to_remove);
		return;
	}
	Node *curr;
	curr = *lst;
	while (curr->next != NULL)
	{
		if (curr->next->x == value)
		{
			Node *to_remove1;
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

void delete_all_element(Node **lst, int value)
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
		Node *to_remove;
		to_remove = (*lst);
		count = ft_printf("Element '%d' is deleted.\n", (*lst)->x);
		*lst = (*lst)->next;
		free(to_remove);
	}
	Node *curr;
	curr = *lst;
	while (curr->next != NULL)
	{
		while (curr->next->x == value)
		{
			Node *to_remove1;
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

void reverse(Node **lst)
{
	Node *curr, *previous, *after;
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

int check_loop(Node *lst)
{
	Node *slow, *fast;
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

int count_node(Node *lst)
{
	int count;
	Node *curr;
	count = 0;
	curr = lst;
	while(curr != NULL)
	{
		count++;
		curr = curr->next;
	}
	// ft_printf("Number of node(s) in linked list: %d\n", count);
	return (count);
}

