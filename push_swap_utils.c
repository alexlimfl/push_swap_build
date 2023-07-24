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

	int nn = count_node(*A);

	// using 2 chunks
	// int denominator = 2;
	// int chunk[] = {0, 0.5*nn, nn};

	// using 4 chunks
	// int denominator = 4;
	// int chunk[] = {0, 0.25*nn, 0.5*nn, 0.75*nn, nn};

	// using 5 chunks
	int denominator = 5;
	int chunk[] = {0, 0.2*nn, 0.4*nn, 0.6*nn, 0.8*nn, nn};

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

	// float numerator;
    // int denominator;
	// int i;
    // float chunk[denominator];

	// denominator = 1;
	// while(denominator == 1 || n_operation < 7000)
	// {
	// 	numerator = 1;
	// 	i = 0;
	// 	chunk[i++] = 0;
	// 	while(numerator <= denominator)
	// 	{
	// 		chunk[i] = (numerator/denominator)*nn;
	// 		numerator++;
	// 		i++;
	// 	}


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
	while(a < denominator)
	{
		A_tail = double_ll_convert(A); // make if readable from end to front of Stack A.
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
			if(position_f <= (nn - position_b)) // choose forward selection
			{
				position_selected = position_f;
				rank_selected = curr_forward->rank;
				// ft_printf("Rank selected: %d\n", rank_selected);
			}
			else if(position_f > (nn - position_b)) // choose backward selection
			{
				position_selected = position_b;
				rank_selected = curr_reverse->rank;
				// ft_printf("Rank selected: %d\n", rank_selected);
			}
			ft_printf("CHECK 3\n");	
			// Strategy 2 for B. >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
			// getting Stack B into correct sort before Push B.
			// let's say target to push B is 8
			// make sure 7 to 1, (7, 6, 5 , 4, 3, 2, 1) is at the top of Stack B.
			// if not, make sure 15 to 9 is at the top of Stack B.
			// make sure when Stack B has more than two nodes.
			int position_selected_B = 0;
			int rank_selected_B = 0;
			int middle_position_B = 0;

			if (count_node(*B) > 1)
			{
				Node *curr = *B;
				
				label_position(B);
				// view_list_position(*B);
				int rank_number;
				int lower_rank = rank_selected - 1;
				int higher_rank = rank_selected + 1;
				middle_position_B = (count_node(*B)/2);

				if(rank_selected < get_lowest_rank(B)) // smallest rank in Stack B
				{
					curr = *B;
					while(curr != NULL)
					{
						if(curr->rank == get_highest_rank(B))
						{
							position_selected_B = curr->position;
							rank_selected_B = curr->rank;
							break;
						}
						curr = curr->next;
					}
				}
				else if(rank_selected > 1)
				{
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
						while(higher_rank <= nn) // looking for 9 to 15
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
				}
			}
			ft_printf("Loop: %d\n", a);
			while(((*A)->rank != rank_selected) || ((count_node(*B) > 1) && ((*B)->rank != rank_selected_B))) //make sure both selected rank at the top of both stacks
			{
				ft_printf("rank selected: %d\n", rank_selected);
				ft_printf("rank selected B: %d\n", rank_selected_B);
				ft_printf("count node B: %d\n", count_node(*B));
				if((count_node(*B) > 1) && ((*A)->rank != rank_selected) && ((*B)->rank != rank_selected_B))
				{
					if(position_selected <= middle_position && position_selected_B <= middle_position_B)
					{
						ft_printf("CHECK 41\n");
						rr(A, B);
					}
					else if(position_selected > middle_position && position_selected_B > middle_position_B)
					{
						ft_printf("CHECK 42\n");
						rrr(A, B);
					}
					else if((*A)->rank != rank_selected)
					{
						if(position_selected <= middle_position)
						ra(A, 0);
						else if(position_selected > middle_position)
						rra(A, 0);
					}
					else if((count_node(*B) > 1) && ((*B)->rank != rank_selected_B))
					{
						if(position_selected_B <= middle_position_B)
						rb(B, 0);
						else if(position_selected_B > middle_position_B)
						rrb(B, 0);
					}
				}
				else if((*A)->rank != rank_selected)
				{
					if(position_selected <= middle_position)
						ra(A, 0);
					else if(position_selected > middle_position)
						rra(A, 0);
				}
				else if((count_node(*B) > 1) && ((*B)->rank != rank_selected_B))
				{
					if(position_selected_B <= middle_position_B)
						rb(B, 0);
					else if(position_selected_B > middle_position_B)
						rrb(B, 0);
				}
				n_operation += 1;
				// view_list_rank(*A);
				// view_list_rank(*B);
			}
			pb(A, B); //push to stack B
			n_operation += 1;
		}
		else if(curr_forward == NULL && curr_reverse == NULL) // if value in chunk[a] is not found
			a++;
				// if(rank_selected == 12)
				// {
				// 	view_list_rank(*B);
				// 	exit(1);
				// }
	}   ///////////////////////////////////////////////ending of the big while loop///////////////////////////////////////////////

	int highest_rank_B = get_highest_rank(B); //checked
	// ft_printf("highest_rank_B: %d\n", highest_rank_B);
	int position_highest_rank_B;
	int middle_position_B = (nn/2);
	Node *curr_sort_B = *B;

	label_position(B);
	while(curr_sort_B != NULL)
	{
		if(curr_sort_B->rank == highest_rank_B) //MAKE SURE IF STATEMENT USING == NOT = !!!
		{
			position_highest_rank_B = curr_sort_B->position;
			break;
		}
		curr_sort_B = curr_sort_B->next;
	}
	while(!check_sorted_reverse(B) && (*B)->rank != highest_rank_B)
	{
		if(position_highest_rank_B <= middle_position_B)
			rb(B, 0);
		else if(position_highest_rank_B > middle_position_B)
			rrb(B, 0);
		n_operation +=1;
	}
	while((*B) != NULL)
		{
			pa(A, B);
			n_operation += 1;
		}
	ft_printf("Number of operation: %d\n", n_operation);
	if(!check_sorted(A))
	{
		ft_printf("SORT FAILED\n");
		exit(1);
	}
	// 	denominator++;
	// }
	return (n_operation);
}