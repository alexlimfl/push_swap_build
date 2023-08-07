/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mega_sort_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:51:46 by folim             #+#    #+#             */
/*   Updated: 2023/08/07 23:51:53 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	view_chunk(int *chunk, int num_chunk)
{
	int	i;

	i = 0;
	while (i <= num_chunk)
	{
		printf("%d\n", chunk[i]);
		i++;
	}
}

int	ps_chk_id(t_node **lst, int chunk_one, int chunk_two)
{
	t_node	*curr;

	curr = *lst;
	while (curr != NULL)
	{
		if (curr->chunk_id == chunk_one || curr->chunk_id == chunk_two)
			return (curr->position);
		curr = curr->next;
	}
	return (-1);
}

int	ps_chk_id_r(t_node **lst, int chunk_one, int chunk_two)
{
	t_node	*curr;

	curr = double_ll_convert(lst);
	while (curr != NULL)
	{
		if (curr->chunk_id == chunk_one || curr->chunk_id == chunk_two)
			return (curr->position);
		curr = curr->prev;
	}
	return (-1);
}

int	va_wi_ch_av(t_node **lst, int *chunk, int i)
{
	t_node	*curr;

	curr = *lst;
	while (curr != NULL)
	{
		if (curr->rank > (chunk[i]) && curr->rank <= chunk[i + 1])
			return (1);
		curr = curr->next;
	}
	return (0);
}

int	chunkID_avalable(t_node **lst, int id)
{
	t_node	*curr;

	curr = *lst;
	while (curr != NULL)
	{
		if (curr->chunk_id == id)
			return (1);
		curr = curr->next;
	}
	return (0);
}