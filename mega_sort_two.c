/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mega_sort_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:09:39 by folim             #+#    #+#             */
/*   Updated: 2023/07/26 21:09:40 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void view_chunk(int *chunk,  int num_chunk)
{
	int i;

	i = 0;
	while(i <= num_chunk)
	{
		printf("%d\n", chunk[i]);
		i++;
	}
}

int	position_s_within_chunk(Node **A, int *chunk, int i)
{
	Node *curr;

	curr = *A;
	while(curr != NULL)
	{
		if(curr->rank > (chunk[i]) && curr->rank <= chunk[i+1])
			return (curr->position);
		curr = curr->next;
	}
	return (-1);
}

int position_s_within_chunk_reverse(Node **A, int *chunk, int i)
{
	Node *curr;

	curr = double_ll_convert(A);
	while(curr != NULL)
	{
		if(curr->rank > (chunk[i]) && curr->rank <= chunk[i+1])
			return (curr->position);
		curr = curr->prev;
	}
	return (-1);
}


int	position_s_chunk_id(Node **lst, int chunk_one, int chunk_two)
{
	Node *curr;

	curr = *lst;
	while(curr != NULL)
	{
		if(curr->chunk_id == chunk_one || curr->chunk_id == chunk_two)
			return (curr->position);
		curr = curr->next;
	}
	return (-1);
}

int	position_s_chunk_id_reverse(Node **lst, int chunk_one, int chunk_two)
{
	Node *curr;

	curr = double_ll_convert(lst);
	while(curr != NULL)
	{
		if(curr->chunk_id == chunk_one || curr->chunk_id == chunk_two)
			return (curr->position);
		curr = curr->prev;
	}
	return (-1);
}


int value_within_chunk_available(Node **lst, int *chunk, int i)
{
	Node *curr;

	curr = *lst;
	while(curr != NULL)
	{
		if(curr->rank > (chunk[i]) && curr->rank <= chunk[i+1])
			return (1);
		curr = curr->next;
	}
	return (0);
}

int	push_A_single_way_find(Node **A, Node **B, int *chunk, int i, int n_operation)
{
	int position_s;
	
	label_position(A);
	position_s = position_s_within_chunk(A, chunk, i);
	if(position_s > 0)
	{
		while(position_s != -1 && (*A)->position != position_s)
			n_operation = ra(A, 1, n_operation);
		n_operation = pb(A, B, 1, n_operation);
	}
	return (n_operation);
}

int	push_B_multi_way_find(Node **A, Node **B, int *chunk, int i, int n_operation)
{
	int	position_s;

	label_position(A);
	if(position_s_within_chunk(A, chunk, i) + position_s_within_chunk_reverse(A, chunk, i) > 0) //if not negative
		{
			if(position_s_within_chunk(A, chunk, i) <= (count_node(*A) - position_s_within_chunk_reverse(A, chunk, i)))
			{
				position_s = position_s_within_chunk(A, chunk, i);
				while(position_s != -1 && (*A)->position != position_s)
					n_operation = ra(A, 1, n_operation);
			}
			else if(position_s_within_chunk(A, chunk, i) > (count_node(*A) - position_s_within_chunk_reverse(A, chunk, i)))
			{
				position_s = position_s_within_chunk_reverse(A, chunk, i);
				while(position_s != -1 && (*A)->position != position_s)
					n_operation = rra(A, 1, n_operation);
			}
			if(position_s > 0)
				n_operation = pb(A, B, 1, n_operation);
		}
	return (n_operation);
}

int	PB_multi_find_chunkID(Node **A, Node **B, int chunk_one, int chunk_two, int n_operation)
{
	int	position_s;

	label_position(A);
	if(position_s_chunk_id(A, chunk_one, chunk_two) <= (count_node(*A) - position_s_chunk_id_reverse(A, chunk_one, chunk_two)))
	{
		position_s = position_s_chunk_id(A, chunk_one, chunk_two);
		while(position_s != -1 && (*A)->position != position_s)
			n_operation = ra(A, 1, n_operation);
	}
	else if(position_s_chunk_id(A, chunk_one, chunk_two) > (count_node(*A) - position_s_chunk_id_reverse(A, chunk_one, chunk_two)))
	{
		position_s = position_s_chunk_id_reverse(A, chunk_one, chunk_two);
		while(position_s != -1 && (*A)->position != position_s)
			n_operation = rra(A, 1, n_operation);
	}
	if(position_s > 0)
		n_operation = pb(A, B, 1, n_operation);
	return(n_operation);
}


void lable_chunk(Node **lst, int *chunk, int num_chunk)
{
	Node *curr;
	int i;

	i = 0;
	while(i < num_chunk)
	{
		
		curr = *lst;
		while(curr != NULL)
		{	
			if(value_within_chunk_available(lst, chunk, i) && curr->rank > (chunk[i]) && curr->rank <= chunk[i+1])
				curr->chunk_id = i+1;
			curr = curr->next;
		}
		if(curr == NULL)
			i++;
	}
}

int rotate(Node **A, Node**B, int RA, int RB, int n_operation)
{
	if(RA == 1 && RB == 1)
		n_operation = rr(A, B, 1, n_operation);
	else if(RA == 1 && RB == 0)
		n_operation = ra(A, 1, n_operation);
	else if(RA == 0 && RB == 1)
		n_operation = rb(B, 1, n_operation);
	return (n_operation);
}

int reverse_rotate(Node **A, Node**B, int RRA, int RRB, int n_operation)
{
	if(RRA == 1 && RRB == 1)
		n_operation = rrr(A, B, 1, n_operation);
	else if(RRA == 1 && RRB == 0)
		n_operation = rra(A, 1, n_operation);
	else if(RRA == 0 && RRB == 1)
		n_operation = rrb(B, 1, n_operation);
	return (n_operation);
}

int		check_sorted_h_tail(Node **lst)
{
	Node *curr;
	int before;

	curr = (*lst)->next;
	before = (*lst)->x;	
	while(curr != NULL)
	{
		
		if (curr->x >= before)
		{
			before = curr->x;
			curr = curr->next;
		}
		else
		{
			curr->sorted_h_tail = 1;
			before = curr->x;
			curr = curr->next;
		}
	}
	return (1);
}

int push_top_chunk(Node **A, Node **B, int *chunk, int num_chunk, int n_operation)
{
	int RA;
	int RB;
	int i;

	while(count_node(*B) < 2)
		n_operation = PB_multi_find_chunkID(A, B, 1, 2, n_operation);
	i = 0;
	while(i <= (num_chunk - 2))
	{
		while(value_within_chunk_available(A, chunk, i) || value_within_chunk_available(A, chunk, (i+1)))
		{
			RA = 0;
			RB = 0;
			if((*A)->chunk_id >= (*B)->chunk_id && ((*A)->chunk_id == (i+1) || (*A)->chunk_id == (i+2)))
			{
				n_operation = pb(A, B, 1, n_operation);
				if((*B)->chunk_id == (i+1))
					RB = 1;
			}
			else if((*A)->chunk_id < (*B)->chunk_id && ((*A)->chunk_id == (i+1) || (*A)->chunk_id == (i+2)))
			{
				n_operation = pb(A, B, 1, n_operation);
				// ft_printf("CHECK\n");
				RB = 1;
			}
			if((*A) != NULL && (*A)->chunk_id != (i+1) && (*A)->chunk_id != (i+2))
				RA = 1;
			// if((*A) != NULL)
				n_operation = rotate(A, B, RA, RB, n_operation);
		}
		// while((*B)->chunk_id == (i+1))
		// 	n_operation = rb(B, 1, n_operation);
		// if(!(value_within_chunk_available(A, chunk, i) || value_within_chunk_available(A, chunk, (i+1))) && ((*B)->chunk_id == (i+1) || (*B)->chunk_id == (i+2)))
		// 	n_operation = rb(B, 1, n_operation);

		i += 2;
	}
	// check_sorted_h_tail(B);
	// view_all(*A, *B);
	// exit(1);

	/*
	while(value_within_chunk_available(A, chunk, 0) || value_within_chunk_available(A, chunk, 1))
	{
		RA = 0;
		RB = 0;
		if((*A)->chunk_id >= (*B)->chunk_id && ((*A)->chunk_id == 1 || (*A)->chunk_id == 2))
			n_operation = pb(A, B, 1, n_operation);
		else if((*A)->chunk_id < (*B)->chunk_id && ((*A)->chunk_id == 1 || (*A)->chunk_id == 2))
		{
			n_operation = pb(A, B, 1, n_operation);
			RB = 1;

		}
		if(((*A)->chunk_id != 1 && (*A)->chunk_id != 2))
			RA = 1;
		n_operation = rotate(A, B, RA, RB, n_operation);
	}
	while(value_within_chunk_available(A, chunk, 2) || value_within_chunk_available(A, chunk, 3))
	{
		RA = 0;
		RB = 0;
		while(count_node(*B) < 2 && ((*A)->chunk_id == 3 || (*A)->chunk_id == 4))
			n_operation = pb(A, B, 1, n_operation);
	
		if((*A)->chunk_id >= (*B)->chunk_id && ((*A)->chunk_id == 3 || (*A)->chunk_id == 4))
			n_operation = pb(A, B, 1, n_operation);
		else if((*A)->chunk_id < (*B)->chunk_id && ((*A)->chunk_id == 3 || (*A)->chunk_id == 4))
		{
			n_operation = pb(A, B, 1, n_operation);
			RB = 1;

		}
		if(((*A)->chunk_id != 3 && (*A)->chunk_id != 4))
			RA = 1;
		n_operation = rotate(A, B, RA, RB, n_operation);
	}
	while(value_within_chunk_available(A, chunk, 4) || value_within_chunk_available(A, chunk, 5))
	{
		RA = 0;
		RB = 0;
		while(count_node(*B) < 2 && ((*A)->chunk_id == 5 || (*A)->chunk_id == 6))
			n_operation = pb(A, B, 1, n_operation);
	
		if((*A)->chunk_id >= (*B)->chunk_id && ((*A)->chunk_id == 5 || (*A)->chunk_id == 6))
			n_operation = pb(A, B, 1, n_operation);
		else if((*A)->chunk_id < (*B)->chunk_id && ((*A)->chunk_id == 5 || (*A)->chunk_id == 6))
		{
			n_operation = pb(A, B, 1, n_operation);
			RB = 1;

		}
		if(((*A)->chunk_id != 5 && (*A)->chunk_id != 6))
			RA = 1;
		n_operation = rotate(A, B, RA, RB, n_operation);
	}
	while(value_within_chunk_available(A, chunk, 6) || value_within_chunk_available(A, chunk, 7))
	{
		RA = 0;
		RB = 0;
		while(count_node(*B) < 2 && ((*A)->chunk_id == 7 || (*A)->chunk_id == 8))
			n_operation = pb(A, B, 1, n_operation);
	
		if((*A)->chunk_id >= (*B)->chunk_id && ((*A)->chunk_id == 7 || (*A)->chunk_id == 8))
			n_operation = pb(A, B, 1, n_operation);
		else if((*A)->chunk_id < (*B)->chunk_id && ((*A)->chunk_id == 7 || (*A)->chunk_id == 8))
		{
			n_operation = pb(A, B, 1, n_operation);
			RB = 1;

		}
		if(((*A)->chunk_id != 7 && (*A)->chunk_id != 8))
			RA = 1;
		n_operation = rotate(A, B, RA, RB, n_operation);
	}
	while(value_within_chunk_available(A, chunk, 8) || value_within_chunk_available(A, chunk, 9))
	{
		RA = 0;
		RB = 0;
		while(count_node(*B) < 2 && ((*A)->chunk_id == 9 || (*A)->chunk_id == 10))
			n_operation = pb(A, B, 1, n_operation);
	
		if((*A)->chunk_id >= (*B)->chunk_id && ((*A)->chunk_id == 9 || (*A)->chunk_id == 10))
			n_operation = pb(A, B, 1, n_operation);
		else if((*A)->chunk_id < (*B)->chunk_id && ((*A)->chunk_id == 9 || (*A)->chunk_id == 10))
		{
			n_operation = pb(A, B, 1, n_operation);
			RB = 1;
		}
		if(((*A)->chunk_id != 9 && (*A)->chunk_id != 10))
			RA = 1;
		n_operation = rotate(A, B, RA, RB, n_operation);
	}*/
	return (n_operation);
}

void	inner_chunk_maker(int nn, int *inner_chunk, int denominator)
{
	int D;
	int i;
	float numerator;

	D = denominator * 6.2;
	numerator = 1;
	inner_chunk[0] = 0;
	i = 1;
	while(numerator <= D)
	{
		inner_chunk[i] = (numerator/D)*nn;
		i++;
		numerator++;
	}
}


void	outer_chunk_maker(int nn, int *inner_chunk, int *outer_chunk, int denominator)
{
	float numerator;
	int i;
	int j;
	int section[] = {0, 16, 32, 40, 48, 52, 56, 58, 60, 61, 62};

	numerator = 1;
	outer_chunk[0] = 0;
	i = 1;
	j = 1;
	while(numerator <= denominator)
	{
		outer_chunk[i] = inner_chunk[section[j]];
		i++;
		j++;
		numerator++;
	}
}





// int		check_sorted_tail_h(Node **lst)
// {
// 	Node *curr;
// 	int before;
// 
// 	curr = (*lst)->prev;
// 	before = (*lst)->x;	
// 	while(curr != NULL)
// 	{
// 		if (curr->x <= before)
// 		{
// 			before = curr->x;
// 			curr = curr->prev;		
// 		}
// 		else
// 		{
// 			curr->sorted_tail_h = 1;
// 			before = curr->x;
// 			curr = curr->prev;
// 		}
// 	}
// 	return (1);
// }


int target_A_largest_B(Node **A, int rank_B)
{
	Node *curr_A;
	int highest_rank;
	int lowest_rank;

	label_position(A);
	highest_rank = get_highest_rank(A);
	lowest_rank = get_lowest_rank(A);
	if(rank_B > highest_rank)
	{
		while(highest_rank >= lowest_rank)
		{
			curr_A = *A;
			while(curr_A != NULL)
			{
				if(curr_A->rank == highest_rank)
					return (curr_A->position);
				curr_A = curr_A->next;
			}
			highest_rank--;
		}
	}
	return (-1);
}

int	target_A_smallest_B(Node **A, int rank_B)
{
	Node *curr_A;
	int highest_rank;
	int lowest_rank;

	highest_rank = get_highest_rank(A);
	lowest_rank = get_lowest_rank(A);
	label_position(A);
	if(rank_B < lowest_rank)
	{
		while(lowest_rank <= highest_rank)
		{
			curr_A = *A;
			while (curr_A != NULL)
			{
				if(curr_A->rank == lowest_rank)
					return (curr_A->position);
				curr_A = curr_A->next;
			}
			lowest_rank--;
		}
	}
	return (-1);
}

int target_A(Node **A, int rank_B)
{
	Node *curr_A;
	int position_l;
	int position_h;
	int rank_B_temp;

	label_position(A);
	rank_B_temp = rank_B;
	while(rank_B >= get_lowest_rank(A))
	{
		curr_A = *A;
		while (curr_A != NULL)
		{
			if (curr_A->rank == rank_B)
				break;
			curr_A = curr_A->next;
		}
		if (curr_A != NULL)
			break;
		rank_B--;
	}
	position_l = curr_A->position;
	rank_B = rank_B_temp;
	while(rank_B <- get_highest_rank(A))
	{
		curr_A = *A;
		while (curr_A != NULL)
		{
			if (curr_A->rank == rank_B)
				break;
			curr_A = curr_A->next;
		}
		if (curr_A != NULL)
			break;
		rank_B++;
	}
	position_h = curr_A->position;
	if (position_h <= count_node(*A) - position_l)
		return (position_h);
	else if (position_h > count_node(*A) - position_l)
		return (position_l);
}



int	decending_from_top(Node **A, Node **B, int num_chunk, int n_operation)
{
	Node *curr_A;
	Node *curr_B;
	Node *tail_B;
	int target_p_A;
	int RA;
	int RB;
	int RRA;
	int RRB;


	tail_B = double_ll_convert(B);

	get_highest_rank(B);


	while((*B) != NULL)
	{
		curr_B = *B;
		label_position(B);
		while(curr_B != NULL)
		{
			if(curr_B->rank == get_highest_rank(B))
				break;
			curr_B = curr_B->next;
		}
		curr_A = *A;
		label_position(A);

				// ft_printf("CHECK, %d, %d\n", curr_B->rank, get_highest_rank(A));
		if (curr_B->rank > get_highest_rank(A))
		{
			target_p_A = target_A_largest_B(A, curr_B->rank);
			ft_printf("CHECK 111111111111111\n");

		}
		else if (curr_B->rank < get_lowest_rank(A))
		{
			target_p_A = target_A_smallest_B(A, curr_B->rank);
			ft_printf("CHECK 2222222222222222222222\n");

		}
		else
		{
			ft_printf("CHECK 33333333333333333333\n");
			target_p_A = target_A(A, curr_B->rank);
		}

		// while(curr_A !=  NULL)
		// {
		// 	if(curr_A->rank == get_lowest_rank(A))
		// 		break;
		// 	curr_A = curr_A->next;
		// }

		while(curr_B != NULL && (*B)->rank != curr_B->rank || (*A) != NULL && (*A)->position != target_p_A)
		{
			RA = 0;
			RB = 0;
			RRA = 0;
			RRB = 0;
			if(curr_B != NULL && (*B)->rank != curr_B->rank)
			{
				if(curr_B->position <= count_node(*B)/2)
					RB = 1;
				else
					RRB = 1;
			}
			if((*A) != NULL && (*A)->position != target_p_A)
			{
				if(target_p_A <= count_node(*A)/2)
					RA = 1;
				else
					RRA = 1;
			}
			n_operation = rotate(A, B, RA, RB, n_operation);
			n_operation = reverse_rotate(A, B, RRA, RRB, n_operation);
		}
		if((*B)->next != NULL && (*B)->sorted_h_tail == 0 && (*B)->next->sorted_h_tail == 1)
		{
			if((*B)->sorted_h_tail == 0 && (*B)->next->sorted_h_tail == 1)
				n_operation = pa(A, B, 1, n_operation);
			while((*B)->sorted_h_tail == 1)
				n_operation = pa(A, B, 1, n_operation);
			ft_printf("CHECK 44444444444444\n");
		}
		else
			n_operation = pa(A, B, 1, n_operation);
	}

	// while((*A)->rank != get_smallest(A))
	// 	n_operation = ra(A, 1, n_operation);
	return (n_operation);
	
}



int	quick_sort(Node **A, Node **B, int *chunk, int num_chunk, int n_operation)
{
	// while(count_node(*A) < 2) // push A until A has two
	// 	n_operation = pa(A, B, 1, n_operation);
	// until last two chunk, chunk_ID 1 and 2
	// while((*B)->chunk_id != 1 && (*B)->chunk_id !=2)
	// {
	// 	//find
	// }

	n_operation = decending_from_top(A, B, num_chunk, n_operation);



	return (n_operation);
}



int mega_sort_two(Node **A, Node **B, int n_operation)
{	
	int inner_chunk[100];
	int outer_chunk[100];
	int num_chunk;
	// int position_s;
	Node *curr;

	curr = *A;
	num_chunk = 10;
	label_ranking(A);
	// view_list_rank(*A);
	// exit(1);
	inner_chunk_maker(count_node(*A), inner_chunk, num_chunk);
	outer_chunk_maker(count_node(*A), inner_chunk, outer_chunk, num_chunk);
	lable_chunk(A, outer_chunk, num_chunk);
	n_operation = push_top_chunk(A, B, outer_chunk, num_chunk, n_operation);
	n_operation = quick_sort(A, B, outer_chunk, num_chunk, n_operation);


	
	// view_all(*A, *B);
	// view_chunk(outer_chunk, num_chunk);
	// ft_printf("Check sorted = %d\n", check_sorted(A));
	// ft_printf("Number of Operation >>> %d\n", n_operation);
	exit(0);
	return (n_operation);
}

// Stack A will rotate, if value on top is within current and the next chunks. Ready to PA.
// Stack B will check which chunk the top value of Stack A is, will rotate accordingly.
// If chunk on top B is same with on top A, Push B.
// If chunk on top B is not same with on top A, 
// Objective, make sure chunk 1 and chunk 2 doesn't overlap.
// Check if on top Stack B and the next, if same just push, not same rotate.






