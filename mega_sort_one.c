#include "push_swap.h"


void	chunk_maker(int nn, int *chunk, int denominator)
{
	float numerator;
	int i;
	// ft_printf("CHECK 1\n");
	numerator = 1;
	chunk[0] = 0;

	i = 1;
	while(numerator <= denominator)
	{
		chunk[i] = (numerator/denominator)*nn;
		i++;
		numerator++;
	}
}







int		mega_sort_one(Node **A, Node **B, int n_operation)
{
	Node *A_tail;

	label_ranking(A); // simplify values to ranking to make chunk-sorting easier
	int nn = count_node(*A);
	int num_chunk;

	if(count_node(*A) <= 100)
		num_chunk = 5;
	else
		num_chunk = 10;

	// view_list(*A);
	// view_list_rank(*A);
	// view_list_position(*A);
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
	// while(numerator <= denominator)
	// {
	// 	chunk[i] = (numerator/denominator)*nn;
	// 	i++;
	// 	numerator++;
	// }
	int chunk[100];

	chunk_maker(nn, chunk, num_chunk);

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
	while(a < num_chunk)
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
				break;
			}
			curr_reverse = curr_reverse->prev;
		}
		// ft_printf("CHECK 1\n");
		if(curr_forward != NULL || curr_reverse != NULL) // if value in chunk[a] is found
		{
				// position_selected = position_f;
				// rank_selected = curr_forward->rank;
			// ft_printf("CHECK 2\n");
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
			// ft_printf("CHECK 3\n");	
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
			// ft_printf("Loop: %d\n", a);
			while(((*A)->rank != rank_selected) || ((count_node(*B) > 1) && ((*B)->rank != rank_selected_B))) //make sure both selected rank at the top of both stacks
			{
				if((count_node(*B) > 1) && ((*A)->rank != rank_selected) && ((*B)->rank != rank_selected_B))
				{
					if(position_selected <= middle_position && position_selected_B <= middle_position_B)
						n_operation = rr(A, B, 1, n_operation);
					else if(position_selected > middle_position && position_selected_B > middle_position_B)
						n_operation = rrr(A, B, 1, n_operation);
					else if((*A)->rank != rank_selected)
					{
						if(position_selected <= middle_position)
						n_operation = ra(A, 1, n_operation);
						else if(position_selected > middle_position)
						n_operation = rra(A, 1, n_operation);
					}
					else if((count_node(*B) > 1) && ((*B)->rank != rank_selected_B))
					{
						if(position_selected_B <= middle_position_B)
						n_operation = rb(B, 1, n_operation);
						else if(position_selected_B > middle_position_B)
						n_operation = rrb(B, 1, n_operation);
					}
				}
				else if((*A)->rank != rank_selected)
				{
					if(position_selected <= middle_position)
						n_operation = ra(A, 1, n_operation);
					else if(position_selected > middle_position)
						n_operation = rra(A, 1, n_operation);
				}
				else if((count_node(*B) > 1) && ((*B)->rank != rank_selected_B))
				{
					if(position_selected_B <= middle_position_B)
						n_operation = rb(B, 1, n_operation);
					else if(position_selected_B > middle_position_B)
						n_operation = rrb(B, 1, n_operation);
				}
				// view_list_rank(*A);
				// view_list_rank(*B);
			}
			n_operation = pb(A, B, 1, n_operation); //push to stack B
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
			n_operation = rb(B, 1, n_operation);
		else if(position_highest_rank_B > middle_position_B)
			n_operation = rrb(B, 1, n_operation);
	}
	while((*B) != NULL)
		{
			n_operation = pa(A, B, 1, n_operation);
		}
	// ft_printf("Denominator: %d\n", num_chunk);
	int i = 0;
	while(i <= num_chunk)
	{
		// printf("Chunks : %d\n", chunk[i]);
		i++;
	}
	if(!check_sorted(A))
	{
		ft_printf("SORT FAILED\n");
		// exit(1);
	}
	// else
		// ft_printf("Number of operation: %d\nCheck sorted >>> %d\n", n_operation, check_sorted(A));

	return (n_operation);
}


