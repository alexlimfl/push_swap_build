/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:11:15 by folim             #+#    #+#             */
/*   Updated: 2023/08/07 23:11:19 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	view_list(t_node *lst)
	{
	ft_printf("List:\n");
	if (lst == NULL)
	{
		ft_printf("Empty\n");
	}
	while (lst != NULL)
	{
		ft_printf("%d\n", lst->x);
		lst = lst->next;
	}
}

void	view_list_rank(t_node *lst)
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

void	view_list_position(t_node *lst)
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

void	view_list_backward(t_node *lst)
{
	ft_printf("List (backward):\n");
	if (lst == NULL)
	{
		ft_printf("Empty.\n");
		return ;
	}
	while (lst != NULL)
	{
		ft_printf("%d\n", lst->x);
		lst = lst->prev;
	}
}

void	view_all(t_node *lst, t_node *lst2)
{
	ft_printf("List ALL:\n");
	if (lst == NULL)
		ft_printf("A: Empty\n");
	if (lst2 == NULL)
		ft_printf("B: Empty\n");
	ft_printf("Value, R, ChunkID, Posi, sht	 Value, R, ChunkID, Posi, sht\n");
	while (lst != NULL || lst2 != NULL)
	{
		if (lst != NULL)
		{
			ft_printf("%d   %d   %d   %d      ", lst->x, lst->rank,
				lst->chunk_id, lst->position/*, lst->sorted_h_tail*/);
			lst = lst->next;
		}
		if (lst2 != NULL)
		{
			ft_printf("\n		   		%d   %d   %d   %d   ", lst2->x,
				lst2->rank, lst2->chunk_id,
				lst2->position/*, lst2->sorted_h_tail*/);
			lst2 = lst2->next;
		}
		ft_printf("\n");
	}
}