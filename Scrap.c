#include "push_swap.h"

int push_A(t_node **A, t_node **B, t_node **curr_B, int target_p_A, int *RA, int *RB, int *RRA, int *RRB, int n_operation)
{
    t_node *tail_A;
    
    int stop;
    stop = 0;
	while(*curr_B != NULL && (*B)->rank != (*curr_B)->rank || /*(*A) != NULL && c_node(*A) > 1 && */stop == 0)
    {
        tail_A = double_ll_convert(A);
        *RA = 0;
        *RB = 0;
        *RRA = 0;
        *RRB = 0;
        if(*curr_B != NULL && (*B)->rank != (*curr_B)->rank)
        {
            if((*curr_B)->position <= c_node(*B)/2)
                *RB = 1;
            else
                *RRB = 1;
        }
        if(/*(*A) != NULL && c_node(*A) > 1 && */stop == 0)
        {
            if ((*curr_B)->rank > get_highest_rank(A) || (*curr_B)->rank < get_lowest_rank(A))
                top_A_one(A, target_p_A, (*curr_B)->rank, tail_A->position, RA, RRA, &stop);
            else
                top_A_two(A, target_p_A, (*curr_B)->rank, tail_A->position, RA, RRA, &stop);
        }
        n_operation = rotate(A, B, *RA, *RB, n_operation);
        n_operation = reverse_rotate(A, B, *RRA, *RRB, n_operation);
    }
    return (n_operation);
}

void top_A(t_node **A, int target_p_A, int curr_B_rank, int tail_A_position, int *RA, int *RRA, int *stop)
{
    if (find_rank_of_position(A, target_p_A) < curr_B_rank)
    {
        if (tail_A_position != target_p_A && target_p_A < c_node(*A)/2)
            RA = 1;
        else if (tail_A_position != target_p_A && target_p_A >= c_node(*A)/2)
            RRA = 1;
        else
            stop = 1;
    }
    else if (find_rank_of_position(A, target_p_A) > curr_B_rank)
    {
        if ((*A)->position != target_p_A && target_p_A <= c_node(*A)/2)
            RA = 1;
        else if ((*A)->position != target_p_A && target_p_A > c_node(*A)/2)
            RRA = 1;
        else 
            stop = 1;
    }
}


void top_A_one(t_node **A, int target_p_A, int curr_B_rank, int tail_A_position, int *RA, int *RRA, int *stop)
{
    if (curr_B_rank > get_highest_rank(A))
    {
        if (tail_A_position != target_p_A && target_p_A < c_node(*A)/2)
            *RA = 1;
        else if (tail_A_position != target_p_A && target_p_A >= c_node(*A)/2)
            *RRA = 1;
        else
            *stop = 1;
    }
    else if (curr_B_rank < get_lowest_rank(A))
    {
        if ((*A)->position != target_p_A && target_p_A <= c_node(*A)/2)
            *RA = 1;
        else if ((*A)->position != target_p_A && target_p_A > c_node(*A)/2)
            *RRA = 1;
        else
            *stop = 1;
    }
}

int	decending_from_top(t_node **A, t_node **B, int *chunk, int num_chunk, int until_chunk, int n_operation)
{
	t_node *curr_B;
	t_node *tail_A;
	int RA;
	int RB;
	int RRA;
	int RRB;
	int target_p_A;

	while((*B) != NULL && chunkID_avalable(B, until_chunk))
	{					
		label_position(B);
		if (is_even(num_chunk) || until_chunk < 5)
			curr_B = *B;
		else if (!is_even(num_chunk))
			curr_B = double_ll_convert(B);
		target_p_A =  get_target_p_A(A, curr_B->rank);
		n_operation = push_A(A, B, &curr_B, target_p_A, &RA, &RB, &RRA, &RRB, n_operation);
		n_operation = pa(A, B, 1, n_operation);
		if(!chunkID_avalable(B, num_chunk)) //when 5 finish, highest is 4, so plus two.
				num_chunk--;
	}
	return (n_operation);
}