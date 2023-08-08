#include "push_swap.h"

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