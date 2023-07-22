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

int		check_sorted(Node **A)
{
	Node *curr;
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

int		check_sorted_reverse(Node **A)
{
	Node *curr;
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

int		get_largest(Node **lst)
{
	int largest;
	Node *curr;

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

int		get_highest_rank(Node **lst)
{
	int highest_rank;
	Node *curr;

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

int		get_smallest(Node **lst)
{
	int smallest;
	Node *curr;

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

int		get_lowest_rank(Node **lst)
{
	int lowest_rank;
	Node *curr;

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

int		tiny_sort(Node **A, int n_operation)
{
	Node *curr;
	int largest;
	int c;

	if(count_node(*A) > 3)
		return (n_operation);
	largest = get_largest(A);
	curr = *A;
	c = 1;
	while (!check_sorted(A))
	{
		if(c == 1 && largest == curr->x)
		{
			ra(A, 0);
			n_operation += 1;
			curr = *A;
			c = 1;
			view_list(*A);
		}
		if(c == 2 && largest == curr->x)
		{
			rra(A, 0);
			n_operation += 1;
			curr = *A;
			c = 1;
			view_list(*A);
		}
		if(c == 3 && largest == curr->x)
		{
			sa(A, 0);
			n_operation += 1;
			curr = *A;
			c = 1;
			view_list(*A);
		}
		c++;
		curr = curr->next;
	}
	return (n_operation);
}

void	check_duplicate(Node **A)
{
	Node *curr;
	Node *temp;

	temp = *A;
	curr = temp->next;
	while(curr != NULL)
	{
		
		while(curr != NULL)
		{
			if(temp->x == curr->x)
			{

				ft_printf("%d\n", temp->x);
				ft_printf("%d\n", curr->x);
				ft_printf("Error (Duplicate found)\n");
				exit(1);
			}
			curr = curr->next;
		}
		temp = temp->next;
		curr = temp->next;
	}
}

int		get_median(Node *lst)
{
	int sum;
	int median;
	Node *curr;

	sum = 0;
	curr = lst;

	while(curr != NULL)
	{
		sum = sum + curr->x;
		curr = curr->next;
	}
	median = sum/(count_node(lst));
	ft_printf("Sum = %d, Median = %d\n", sum, median);
	return (median);
}

int 	last_node_value(Node *lst)
{
	Node *curr;
	curr = lst;
	while(curr->next != NULL)
		curr = curr->next;
	return (curr->x);
}

int		medium_sort(Node **A, Node **B, int n_operation)
{
	int largest;
	int smallest;
	
	if(count_node(*A) > 5)
		return (n_operation);
	
	largest = get_largest(A);
	smallest = get_smallest(A);

	pb(A, B);
	pb(A, B);
	n_operation += 2;

	n_operation = tiny_sort(A, n_operation);

	while(*B != NULL)
	{
		// view_list(*A);
		// view_list(*B);

		if((*B)->x == largest && (*B)->x && get_largest(A) == last_node_value(*A))
		{
			// ft_printf("CHECK 1\n");
			pa(A, B);
		}
		else if((*B)->x == smallest && get_smallest(A) == (*A)->x)
		{
			// ft_printf("CHECK 2\n");
			pa(A, B);
		}
		else if((*B)->x > last_node_value(*A) && (*B)->x < (*A)->x)
		{
			// ft_printf("CHECK 3\n");
			pa(A, B);
		}
		else if(check_sorted(A) && (*B)->x < (*A)->x)
		{
			// ft_printf("CHECK 4\n");
			pa(A, B);
		}
		else if(check_sorted(A) && (*B)->x > last_node_value(*A))
		{
			// ft_printf("CHECK 4.5\n");
			pa(A, B);
		}
		else
		{
			// ft_printf("CHECK 5\n");
			ra(A, 0);
		}
		n_operation += 1;
	}

	while(!check_sorted(A))
	{
		// ft_printf("CHECK 6\n");
		ra(A, 0);
		n_operation += 1;
	}
	return (n_operation);
}

Node	*double_ll_convert(Node **lst)
{
	if (*lst == NULL)
	{
		ft_printf("Warning (double_ll_convert argument is NULL)\n");
		return (NULL);
	}

	Node *prev;
	Node *curr;
	Node *tail;

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

void	label_ranking(Node **lst)
{
	int max_rank;
	int	bigger_than_nb;
	int	nb;
	Node *curr;
	Node *curr_two;

	max_rank = count_node(*lst);
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

void 	label_position(Node **lst)
{
	Node *curr;
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

int		mega_sort_one(Node **A, Node **B, int n_operation)
{
	Node *A_tail;

	label_ranking(A); // simplify values to ranking to make chunk-sorting easier

	// view_list(*A);
	// view_list_rank(*A);
	// view_list_position(*A);
	// view_list_backward(A_tail);

	int n_nodes = count_node(*A);

	// using 5 chunks
	int chunk[] = {0, (0.20)*n_nodes, (0.40)*n_nodes, (0.60)*n_nodes, (0.80)*n_nodes, n_nodes};

	// decide ra or rra
	Node *curr_forward;
	Node *curr_reverse;
	int middle_position;

	// count steps taken to middle position
	int position_f;
	int position_b;
	int position_selected;
	int rank_selected;
	int a;
	int count = 1;
	a = 0;
	while(a < 5)
	{
		A_tail = double_ll_convert(A); // make if readable from end to front of Stack A.
		// ft_printf("BEFORE -------, loop number = %d, a = %d\n", count++, a);
		// ft_printf("Stack A :\n");
		// view_list_rank(*A);
		// ft_printf("Stack B :\n");
		// view_list_rank(*B);
		// ft_printf("BEFORE -------\n");

		middle_position = (count_node(*A)/2); // refresh middle position in Stack A
		label_position(A); // refresh the position of Stack A
		
		
		// count forward
		curr_forward = *A;
		while(curr_forward != NULL)
		{
			if(curr_forward->rank >= (chunk[a]+1) && curr_forward->rank <= chunk[a+1]) // rank is within 1 to 20, 21 to 40, 41 to 60 etc ...
			{
				position_f = curr_forward->position;
				// ft_printf("position_f = %d\n", position_f);
				break;
			}
			curr_forward = curr_forward->next;
		}
		// count reverse
		curr_reverse = A_tail;
		while(curr_reverse != NULL)
		{
			if(curr_reverse->rank >= (chunk[a]+1) && curr_reverse->rank <= chunk[a+1]) // rank is within 1 to 20, 21 to 40, 41 to 60 etc ...
			{
				position_b = curr_reverse->position;
				// ft_printf("position_b = %d\n", position_b);
				break;
			}
			curr_reverse = curr_reverse->prev;
		}
		ft_printf("CHECK 1\n");
		if(curr_forward != NULL || curr_reverse != NULL) // if value in chunk[a] is found
		{
			ft_printf("CHECK 2\n");
			if(position_f <= (n_nodes - position_b)) // choose forward selection
			{
				position_selected = position_f;
				rank_selected = curr_forward->rank;
				// ft_printf("Rank selected: %d\n", rank_selected);
			}
			else if(position_f > (n_nodes - position_b)) // choose backward selection
			{
				position_selected = position_b;
				rank_selected = curr_reverse->rank;
				// ft_printf("Rank selected: %d\n", rank_selected);
			}

			ft_printf("CHECK 3\n");
			// rotation
			while((*A)->rank != rank_selected) // loop until rank_selected is at the top
			{
				if (position_selected <= middle_position)
					ra(A, 0);
				else if (position_selected > middle_position)
					rra(A, 0);
				n_operation += 1;
			}
			
			// Strategy 2 for B.
			// getting Stack B into correct sort before Push B.
			// let's say target to push B is 8
			// make sure 7 to 1, (7, 6, 5 , 4, 3, 2, 1) is at the top of Stack B.
			// if not, make sure 15 to 9 is at the top of Stack B.
			// make sure when Stack B has more than two nodes.

			if (count_node(*B) > 1)
			{
				Node *curr = *B;
				
				label_position(B);
				int rank_number;
				int position_selected_B = 0;
				int lower_rank = rank_selected - 1;
				int higher_rank = rank_selected + 1;
				int rank_selected_B = 0;
				int middle_position_B = (count_node(*B)/2);

				while(lower_rank > 0) // looking for 7 to 1 rank
				{	
					curr = *B;
					while(curr != NULL)
					{
						// ft_printf("Lower rank: %d\n", lower_rank);
						if(curr->rank == lower_rank)
						{
							// ft_printf("Lower rank: >>>>>>>>>>>>>>> %d\n", lower_rank);
							position_selected_B = curr->position;
							rank_selected_B = curr->rank;
							break;
						}
						curr = curr->next;
					}
					if(rank_selected_B != 0)
						break;
					lower_rank--;
				}
				if(rank_selected_B == 0) // couldn't find any
				{
					while(higher_rank <= count_node(*B)) // looking for 9 to 15
					{
						curr = *B;
						while(curr != NULL)
						{
							if(curr->rank == higher_rank)
							{
								position_selected_B = curr->position;
								rank_selected_B = curr->rank;
								break;
							}
							curr = curr->next;
						}
						if(rank_selected_B != 0)
							break;
						higher_rank++;
					}
				}


				// 	ft_printf("(*B)->rank: %d\nrank_selected_B: %d\nposition_selected_B: %d\nmiddle_positioin_B: %d\n",
				// 	(*B)->rank,rank_selected_B,position_selected_B,middle_position_B);
				while((*B)->rank != rank_selected_B)
				{
					if(position_selected_B <= middle_position_B)
					{		
						// ft_printf("position_selected_B: %d\nmiddle_positioin_B: %d\n",position_selected_B,middle_position_B);
						rb(B, 0);
					}
					else if(position_selected_B > middle_position_B && position_selected_B != // last)
						rrb(B, 0);
					n_operation += 1;
				}

			}
			pb(A, B); //push to stack B
			n_operation += 1;
		}
		else if(curr_forward == NULL && curr_reverse == NULL) // if value in chunk[a] is not found
			a++;
		ft_printf("Stack B >>>>>>>>>>>>>>>>>>>>>>>>>:\n");
		view_list_rank(*B);
	}
		ft_printf("AFTER -------------1111---------------\n");
		ft_printf("Stack A :\n");
		view_list_rank(*A);
		ft_printf("Stack B >>>>>>>>>>>>>>>>>>>>>>>>>:\n");
		view_list_rank(*B);
		ft_printf("AFTER -------------1111--------------\n");
	// ft_printf("Number of operation (Sorting): %d\n", n_operation);
	// sort Stack B

	int highest_rank_B = get_highest_rank(B); //checked
	// ft_printf("highest_rank_B: %d\n", highest_rank_B);
	int position_highest_rank_B;
	int middle_position_B = (n_nodes/2);
	label_position(B);
	view_list_position(*B); // checked
	view_list_rank(*B); // checked
	Node *curr_sort_B = *B;
	while(curr_sort_B != NULL)
	{
		if(curr_sort_B->rank == highest_rank_B) //MAKE SURE IF STATEMENT USING == NOT = !!!
		{
			position_highest_rank_B = curr_sort_B->position;
			ft_printf("HR: %d , PHR: %d\n", highest_rank_B, position_highest_rank_B);
			break;
		}
		curr_sort_B = curr_sort_B->next;
	}
	ft_printf("position_highest_rank_B: %d\n", position_highest_rank_B);
	
	while(!check_sorted_reverse(B) && (*B)->rank != highest_rank_B)
	{
		if(position_highest_rank_B <= middle_position_B)
			rb(B, 0);
		else if(position_highest_rank_B > middle_position_B)
			rrb(B, 0);
		n_operation +=1;
	}

		ft_printf("AFTER ----------------------------\n");
		ft_printf("Stack A :\n");
		view_list_rank(*A);
		ft_printf("Stack B >>>>>>>>>>>>>>>>>>>>>>>>>:\n");
		view_list_rank(*B);
		ft_printf("AFTER ----------------------------\n");

	while((*B) != NULL)
		{
			pa(A, B);
			n_operation += 1;
		}


	return (n_operation);
}

			// // Stack B operation
			// B_tail = double_ll_convert(B);
			// label_position(B);
			// middle_position = (count_node(*B)/2); // refresh middle position in Stack B

			// // rb or rrb
			// curr_forward = *B;
			// while(curr_forward != NULL)
			// {
			// 	if(curr_forward->rank == highest_rank_B)
			// 	{
			// 		position_f = curr_forward->position;
			// 		break;
			// 	}
			// 	curr_forward = curr_forward->next;
			// }

			// curr_reverse = B_tail;
			// while(curr_reverse != NULL)
			// {
			// 	if(curr_reverse->rank == highest_rank_B);
			// 	{
			// 		position_b = curr_reverse->position;
			// 		break;
			// 	}
			// 	curr_reverse = curr_reverse->next;
			// }

			// ft_printf("CHECK 4\n");
			// while((*B) != NULL && (*B)->next != NULL && (*B)->rank != highest_rank_B) //B is not NULL, B next is not NULL;
			// {
			// 	if(position_f <= middle_position)
			// 		rb(B, 0);
			// 	else if (position_b > middle_position)
			// 		rrb(B, 0);
			// 	n_operation += 1;
			// }

			// // clear to push B