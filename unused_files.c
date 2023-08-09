/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unused_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:09:39 by folim             #+#    #+#             */
/*   Updated: 2023/07/26 21:09:40 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_w_chk(t_node **a, int *chunk, int i)
{
	t_node *curr;

	curr = *a;
	while (curr != NULL)
	{
		if (curr->rank > (chunk[i]) && curr->rank <= chunk[i + 1])
			return (curr->position);
		curr = curr->next;
	}
	return (-1);
}

int	ps_w_chk_r(t_node **a, int *chunk, int i)
{
	t_node	*curr;

	curr = double_ll_convert(a);
	while (curr != NULL)
	{
		if (curr->rank > (chunk[i]) && curr->rank <= chunk[i + 1])
			return (curr->position);
		curr = curr->prev;
	}
	return (-1);
}

void	pa_s_w_f(t_node **a, t_node **b, t_node **otpt, int *chunk, int i)
{
	int	position_s;

	label_position(a);
	position_s = ps_w_chk(a, chunk, i);
	if (position_s > 0)
	{
		while (position_s != -1 && (*a)->position != position_s)
			ra(a, b, otpt, 1);
		pb(a, b, otpt, 1);
	}
}

int	pb_m_w_f(t_node **a, t_node **b, t_node **otpt, int *chunk, int i)
{
	int	position_s;

	label_position(a);
	if (ps_w_chk(a, chunk, i) + ps_w_chk_r(a, chunk, i) > 0)
	{
		if (ps_w_chk(a, chunk, i) <= (c_n(*a) - ps_w_chk_r(a, chunk, i)))
		{
			position_s = ps_w_chk(a, chunk, i);
			while (position_s != -1 && (*a)->position != position_s)
				ra(a, b, otpt, 1);
		}
		else if (ps_w_chk(a, chunk, i) > (c_n(*a) - ps_w_chk_r(a, chunk, i)))
		{
			position_s = ps_w_chk_r(a, chunk, i);
			while (position_s != -1 && (*a)->position != position_s)
				rra(a, b, otpt, 1);
		}
		if (position_s > 0)
			pb(a, b, otpt, 1);
	}
}
/////////////////////////////////////////////////////////////////////////////////
int c_node_wc(t_node *lst, int chunkid)
{
	int count;
	t_node *curr;
	count = 0;
	curr = lst;
	while (curr != NULL)
	{
		if (curr->chunk_id == chunkid)
			count++;
		curr = curr->next;
	}
	// ft_printf("Number of node(s) in linked list: %d\n", count);
	return (count);
}

int	 get_four_median(t_node **b, int chunkid, int choose)
{
	t_node	*curr_b;
	int m1;
	int m2;
	int m3;
	int m4;
	int n_bound;

	// count numbers of values withinchunk
	n_bound = c_node_wc(*b, chunkid) / 5;
	m1 = glowest_rankwithin_chunk(b, chunkid) + n_bound;
	m2 = m1 + n_bound;
	m3 = m2 + n_bound;
	m4 = m3 + n_bound;
	if (choose == 1)
		return (m1);
	if (choose == 2)
		return (m2);
	if (choose == 3)
		return (m3);
	if (choose == 4)
		return (m4);
}
// Stack a will rotate, if value on top is within current and the next chunks. Ready to PA.
// Stack b will check which chunk the top value of Stack a is, will rotate accordingly.
// If chunk on top b is same with on top a, Push b.
// If chunk on top b is not same with on top a, 
// Objective, make sure chunk 1 and chunk 2 doesn't overlap.
// Check if on top Stack b and the next, if same just push, not same rotate.

int push_A(t_node **a, t_node **b, t_node **curr_B, int target_p_A, int *RA, int *RB, int *RRA, int *RRB, int n_operation)
{
    t_node *tail_a;
    
    int stop;
    stop = 0;
	while (*curr_B != NULL && (*b)->rank != (*curr_B)->rank || /*(*a) != NULL && c_n(*a) > 1 && */stop == 0)
    {
        tail_a = double_ll_convert(a);
        *RA = 0;
        *RB = 0;
        *RRA = 0;
        *RRB = 0;
        if (*curr_B != NULL && (*b)->rank != (*curr_B)->rank)
        {
            if ((*curr_B)->position <= c_n(*b)/2)
                *RB = 1;
            else
                *RRB = 1;
        }
        if (/*(*a) != NULL && c_n(*a) > 1 && */stop == 0)
        {
            if ((*curr_B)->rank > get_highest_rank(a) || (*curr_B)->rank < get_lowest_rank(a))
                top_a_one(a, target_p_A, (*curr_B)->rank, tail_a->position, RA, RRA, &stop);
            else
                top_a_two(a, target_p_A, (*curr_B)->rank, tail_a->position, RA, RRA, &stop);
        }
        n_operation = rotate(a, b, *RA, *RB, n_operation);
        n_operation = reverse_rotate(a, b, *RRA, *RRB, n_operation);
    }
    return (n_operation);
}

void top_A(t_node **a, int target_p_A, int curr_B_rank, int tail_A_position, int *RA, int *RRA, int *stop)
{
    if (find_rank_of_position(a, target_p_A) < curr_B_rank)
    {
        if (tail_A_position != target_p_A && target_p_A < c_n(*a)/2)
            RA = 1;
        else if (tail_A_position != target_p_A && target_p_A >= c_n(*a)/2)
            RRA = 1;
        else
            stop = 1;
    }
    else if (find_rank_of_position(a, target_p_A) > curr_B_rank)
    {
        if ((*a)->position != target_p_A && target_p_A <= c_n(*a)/2)
            RA = 1;
        else if ((*a)->position != target_p_A && target_p_A > c_n(*a)/2)
            RRA = 1;
        else 
            stop = 1;
    }
}


void top_a_one(t_node **a, int target_p_A, int curr_B_rank, int tail_A_position, int *RA, int *RRA, int *stop)
{
    if (curr_B_rank > get_highest_rank(a))
    {
        if (tail_A_position != target_p_A && target_p_A < c_n(*a)/2)
            *RA = 1;
        else if (tail_A_position != target_p_A && target_p_A >= c_n(*a)/2)
            *RRA = 1;
        else
            *stop = 1;
    }
    else if (curr_B_rank < get_lowest_rank(a))
    {
        if ((*a)->position != target_p_A && target_p_A <= c_n(*a)/2)
            *RA = 1;
        else if ((*a)->position != target_p_A && target_p_A > c_n(*a)/2)
            *RRA = 1;
        else
            *stop = 1;
    }
}

int	decend_top(t_node **a, t_node **b, int *chunk, int num_chunk, int until_chunk, int n_operation)
{
	t_node *curr_B;
	t_node *tail_a;
	int RA;
	int RB;
	int RRA;
	int RRB;
	int target_p_A;

	while ((*b) != NULL && chunkid_avalable(b, until_chunk))
	{					
		label_position(b);
		if (is_even(num_chunk) || until_chunk < 5)
			curr_B = *b;
		else if (!is_even(num_chunk))
			curr_B = double_ll_convert(b);
		target_p_A =  get_target_p_a(a, curr_B->rank);
		n_operation = push_A(a, b, &curr_B, target_p_A, &RA, &RB, &RRA, &RRB, n_operation);
		n_operation = pa(a, b, 1, n_operation);
		if (!chunkid_avalable(b, num_chunk)) //when 5 finish, highest is 4, so plus two.
				num_chunk--;
	}
	return (n_operation);
}

int		get_median(t_node *lst)
{
	int sum;
	int median;
	t_node *curr;

	sum = 0;
	curr = lst;

	while (curr != NULL)
	{
		sum = sum + curr->x;
		curr = curr->next;
	}
	median = sum/(c_n(lst));
	ft_printf("Sum = %d, Median = %d\n", sum, median);
	return (median);
}

#include "push_swap.h"

void	chunk_maker(int nn, int *chunk, int denominator)
{
	float numerator;
	int i;
	// ft_printf("CHECK 1\n");
	numerator = 1;
	chunk[0] = 0;

	i = 1;
	while (numerator <= denominator)
	{
		chunk[i] = (numerator/denominator)*nn;
		i++;
		numerator++;
	}
}


void	mega_sort_one(t_node **a, t_node **b, t_node **otpt)
{
	t_node *A_tail;

	label_ranking(a); // simplify values to ranking to make chunk-sorting easier
	int nn = c_n(*a);
	int num_chunk;

	if (c_n(*a) <= 100)
		num_chunk = 5;
	else
		num_chunk = 10;

	// view_list(*a);
	// view_list_rank(*a);
	// view_list_position(*a);
	// view_list_backward(A_tail);
	// using 2 chunks
	// int denominator = 2;
	// int chunk[] = {0, 0.5*nn, nn};
	// using 4 chunks
	// int denominator = 4;
	// int chunk[] = {0, 0.25*nn, 0.5*nn, 0.75*nn, nn};
	// using 5 chunks
	// int denominator = 5;
	// int chunk[] = {0, 0.2*nn, 0.4*nn, 0.6*nn, 0.8*nn, nn};
	// using 10 chunks
	// int denominator= 10;
	// int chunk[] = {0, 0.1*nn, 0.2*nn, 0.3*nn, 0.4*nn, 0.5*nn, 0.6*nn, 0.7*nn, 0.8*nn, 0.9*nn, nn};
	// using 15 chunks;
	// int denominator = 15;
	// int chunk[] = {0, 0.07*nn, 0.13*nn, 0.20*nn, 0.27*nn, 0.33*nn, 0.40*nn, 0.47*nn, 0.53*nn, 0.60*nn, 0.67*nn, 0.73*nn, 0.80*nn, 0.87*nn, 0.93*nn, nn};
	// using 11 chunks
	// int denominator = 11;
	// int chunk[] = {0, 0.096*nn, 0.192*nn, 0.288*nn, 0.384*nn, 0.48*nn, 0.576*nn, 0.672*nn, 0.768*nn, 0.864*nn, 0.96*nn, nn};
	// using 20 chunks
	// int denominator = 20;
	// int chunk[] = {0, 0.05*nn, 0.1*nn, 0.15*nn, 0.2*nn, 0.25*nn, 0.3*nn, 0.35*nn, 0.4*nn, 0.45*nn, 0.5*nn, 0.55*nn, 0.6*nn, 0.65*nn, 0.7*nn, 0.75*nn, 0.8*nn, 0.85*nn, 0.9*nn, 0.95*nn, nn};
	// 
	// float numerator;
    // int denominator;
	// int i;
    // int chunk[100];
	// // ft_printf("CHECK 1\n");
	// denominator = 10; // << choose number of chunks here
	// n_operation = 0;
	// numerator = 1;
	// chunk[0] = 0;
	// 
	// i = 1;
	// while (numerator <= denominator)
	// {
	// 	chunk[i] = (numerator/denominator)*nn;
	// 	i++;
	// 	numerator++;
	// }
	int chunk[100];

	chunk_maker(nn, chunk, num_chunk);

	// decide ra or rra
	t_node *curr_forward;
	t_node *curr_reverse;
	int middle_position;

	// count steps taken to middle position
	int position_f;
	int position_b;
	int position_selected;
	int rank_selected;
	int a;
	int count = 1;
	a = 0;
	while (a < num_chunk)
	{
		A_tail = double_ll_convert(a); // make if readable from end to front of Stack a.
		middle_position = (c_n(*a)/2); // refresh middle position in Stack a
		label_position(a); // refresh the position of Stack a
		// count forward
		curr_forward = *a;
		while (curr_forward != NULL)
		{
			if (curr_forward->rank >= (chunk[a]+1) && curr_forward->rank <= chunk[a+1]) // rank is within 1 to 20, 21 to 40, 41 to 60 etc ...
			{
				position_f = curr_forward->position;
				// ft_printf("position_f = %d\n", position_f);
				break;
			}
			curr_forward = curr_forward->next;
		}
		// count reverse
		curr_reverse = A_tail;
		while (curr_reverse != NULL)
		{
			if (curr_reverse->rank >= (chunk[a]+1) && curr_reverse->rank <= chunk[a+1]) // rank is within 1 to 20, 21 to 40, 41 to 60 etc ...
			{
				position_b = curr_reverse->position;
				break;
			}
			curr_reverse = curr_reverse->prev;
		}
		// ft_printf("CHECK 1\n");
		if (curr_forward != NULL || curr_reverse != NULL) // if value in chunk[a] is found
		{
				// position_selected = position_f;
				// rank_selected = curr_forward->rank;
			// ft_printf("CHECK 2\n");
			if (position_f <= (nn - position_b)) // choose forward selection
			{
				position_selected = position_f;
				rank_selected = curr_forward->rank;
				// ft_printf("Rank selected: %d\n", rank_selected);
			}
			else if (position_f > (nn - position_b)) // choose backward selection
			{
				position_selected = position_b;
				rank_selected = curr_reverse->rank;
				// ft_printf("Rank selected: %d\n", rank_selected);
			}
			// ft_printf("CHECK 3\n");	
			// Strategy 2 for b. >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
			// getting Stack b into correct sort before Push b.
			// let's say target to push b is 8
			// make sure 7 to 1, (7, 6, 5 , 4, 3, 2, 1) is at the top of Stack b.
			// if not, make sure 15 to 9 is at the top of Stack b.
			// make sure when Stack b has more than two nodes.
			int position_selected_B = 0;
			int rank_selected_B = 0;
			int middle_position_B = 0;

			if (c_n(*b) > 1)
			{
				t_node *curr = *b;
				
				label_position(b);
				// view_list_position(*b);
				int rank_number;
				int lower_rank = rank_selected - 1;
				int higher_rank = rank_selected + 1;
				middle_position_B = (c_n(*b)/2);

				if (rank_selected < get_lowest_rank(b)) // smallest rank in Stack b
				{
					curr = *b;
					while (curr != NULL)
					{
						if (curr->rank == get_highest_rank(b))
						{
							position_selected_B = curr->position;
							rank_selected_B = curr->rank;
							break;
						}
						curr = curr->next;
					}
				}
				else if (rank_selected > 1)
				{
					while (lower_rank > 0) // looking for 7 to 1 rank
					{	
						curr = *b;
						while (curr != NULL)
						{
							// ft_printf("Lower rank: %d\n", lower_rank);
							if (curr->rank == lower_rank)
							{
								// ft_printf("Lower rank: >>>>>>>>>>>>>>> %d\n", lower_rank);
								position_selected_B = curr->position;
								rank_selected_B = curr->rank;
								break;
							}
							curr = curr->next;
						}
						if (rank_selected_B != 0)
							break;
						lower_rank--;
					}

					if (rank_selected_B == 0) // couldn't find any
					{
						while (higher_rank <= nn) // looking for 9 to 15
						{
							curr = *b;
							while (curr != NULL)
							{
								if (curr->rank == higher_rank)
								{
									position_selected_B = curr->position;
									rank_selected_B = curr->rank;
									break;
								}
								curr = curr->next;
							}
							if (rank_selected_B != 0)
								break;
							higher_rank++;
						}
					}
				}
			}
			// ft_printf("Loop: %d\n", a);
			while (((*a)->rank != rank_selected) || ((c_n(*b) > 1) && ((*b)->rank != rank_selected_B))) //make sure both selected rank at the top of both stacks
			{
				if ((c_n(*b) > 1) && ((*a)->rank != rank_selected) && ((*b)->rank != rank_selected_B))
				{
					if (position_selected <= middle_position && position_selected_B <= middle_position_B)
						rr(a, b, otpt, 1);
					else if (position_selected > middle_position && position_selected_B > middle_position_B)
						rrr(a, b, otpt, 1);
					else if ((*a)->rank != rank_selected)
					{
						if (position_selected <= middle_position)
						ra(a, b, otpt, 1);
						else if (position_selected > middle_position)
						rra(a, b, otpt, 1);
					}
					else if ((c_n(*b) > 1) && ((*b)->rank != rank_selected_B))
					{
						if (position_selected_B <= middle_position_B)
						rb(a, b, otpt, 1);
						else if (position_selected_B > middle_position_B)
						rrb(a, b, otpt, 1);
					}
				}
				else if ((*a)->rank != rank_selected)
				{
					if (position_selected <= middle_position)
						ra(a, b, otpt, 1);
					else if (position_selected > middle_position)
						rra(a, b, otpt, 1);
				}
				else if ((c_n(*b) > 1) && ((*b)->rank != rank_selected_B))
				{
					if (position_selected_B <= middle_position_B)
						rb(a, b, otpt, 1);
					else if (position_selected_B > middle_position_B)
						rrb(a, b, otpt, 1);
				}
				// view_list_rank(*a);
				// view_list_rank(*b);
			}
			pb(a, b, otpt, 1); //push to stack b
		}
		else if (curr_forward == NULL && curr_reverse == NULL) // if value in chunk[a] is not found
			a++;
				// if (rank_selected == 12)
				// {
				// 	view_list_rank(*b);
				// 	exit(1);
				// }
	}   ///////////////////////////////////////////////ending of the big while loop///////////////////////////////////////////////

	int highest_rank_B = get_highest_rank(b); //checked
	// ft_printf("highest_rank_B: %d\n", highest_rank_B);
	int position_highest_rank_B;
	int middle_position_B = (nn/2);
	t_node *curr_sort_B = *b;

	label_position(b);
	while (curr_sort_B != NULL)
	{
		if (curr_sort_B->rank == highest_rank_B) //MAKE SURE IF STATEMENT USING == NOT = !!!
		{
			position_highest_rank_B = curr_sort_B->position;
			break;
		}
		curr_sort_B = curr_sort_B->next;
	}
	while (!check_sorted_reverse(b) && (*b)->rank != highest_rank_B)
	{
		if (position_highest_rank_B <= middle_position_B)
			rb(a, b, otpt, 1);
		else if (position_highest_rank_B > middle_position_B)
			rrb(a, b, otpt, 1);
	}
	while ((*b) != NULL)
		{
			pa(a, b, otpt, 1);
		}
	// ft_printf("Denominator: %d\n", num_chunk);
	int i = 0;
	while (i <= num_chunk)
	{
		// printf("Chunks : %d\n", chunk[i]);
		i++;
	}
	if (!check_sorted(a))
	{
		ft_printf("SORT FAILED\n");
		// exit(1);
	}
	// else
	// 	ft_printf("Number of operation: %d\nCheck sorted >>> %d\n", n_operation, check_sorted(a));

}

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
	if (lst == NULL)
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
	if (*lst == NULL || (*lst)->x >= value)
	{
		insert_front(lst, value);
		return;
	}
	t_node *curr;
	curr = *lst;
	while (curr->next != NULL)
	{
		if (curr->next->x >= value)
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