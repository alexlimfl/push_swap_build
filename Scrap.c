#include "push_swap.h"

int push_A(Node **A, Node **B, Node *curr_B, int target_p_A, int n_operation)
{
    int RA;
    int RB;
    int RRA;
    int RRB;
    int stop;
    Node *tail_A;

    stop = 0;
    while(curr_B != NULL && (*B)->rank != curr_B->rank || (*A) != NULL && count_node(*A) > 1 && stop == 0)
    {
        tail_A = double_ll_convert(A);
        RA = 0;
        RB = 0;
        RRA = 0;
        RRB = 0;
        if(curr_B != NULL && (*B)->rank != curr_B->rank)
        {
            if(curr_B->position <= count_node(*B)/2)
            {
                RB = 1;
            }
            else
                RRB = 1;
        }
        if((*A) != NULL && count_node(*A) > 1 && stop == 0)
        {
            if (curr_B->rank > get_highest_rank(A))
            {
                if (tail_A->position != target_p_A && target_p_A < count_node(*A)/2)
                    RA = 1;
                else if (tail_A->position != target_p_A && target_p_A >= count_node(*A)/2)
                    RRA = 1;
                else
                    stop = 1;
            }
            else if (curr_B->rank < get_lowest_rank(A))
            {
                if ((*A)->position != target_p_A && target_p_A <= count_node(*A)/2)
                    RA = 1;
                else if ((*A)->position != target_p_A && target_p_A > count_node(*A)/2)
                    RRA = 1;
                else
                    stop = 1;
            }
            else
            {
                if (find_rank_of_position(A, target_p_A) < curr_B->rank)
                {
                    // ft_printf("check 2\n");
                    if (tail_A->position != target_p_A && target_p_A < count_node(*A)/2)
                        RA = 1;
                    else if (tail_A->position != target_p_A && target_p_A >= count_node(*A)/2)
                    {
                        // ft_printf("check 3,  %d, %d, %d\n", tail_A->position, target_p_A, (*B)->chunk_id);
                        RRA = 1;
                    }
                    else
                        stop = 1;
                }
                else if (find_rank_of_position(A, target_p_A) > curr_B->rank)
                {
                    // ft_printf("check 3\n");
                    if ((*A)->position != target_p_A && target_p_A <= count_node(*A)/2)
                        RA = 1;
                    else if ((*A)->position != target_p_A && target_p_A > count_node(*A)/2)
                        RRA = 1;
                    else 
                        stop = 1;
                }
            }
        }
        n_operation = rotate(A, B, RA, RB, n_operation);
        n_operation = reverse_rotate(A, B, RRA, RRB, n_operation);
        return (n_operation);
    }
}

void top_A(Node **A, int target_p_A, int curr_B_rank, int tail_A_position, int *RA, int *RRA, int *stop)
{
    if (find_rank_of_position(A, target_p_A) < curr_B_rank)
    {
        if (tail_A_position != target_p_A && target_p_A < count_node(*A)/2)
            RA = 1;
        else if (tail_A_position != target_p_A && target_p_A >= count_node(*A)/2)
            RRA = 1;
        else
            stop = 1;
    }
    else if (find_rank_of_position(A, target_p_A) > curr_B_rank)
    {
        if ((*A)->position != target_p_A && target_p_A <= count_node(*A)/2)
            RA = 1;
        else if ((*A)->position != target_p_A && target_p_A > count_node(*A)/2)
            RRA = 1;
        else 
            stop = 1;
    }
}


void top_A_one(Node **A, int target_p_A, int curr_B_rank, int tail_A_position, int *RA, int *RRA, int *stop)
{
    if (curr_B_rank > get_highest_rank(A))
    {
        if (tail_A_position != target_p_A && target_p_A < count_node(*A)/2)
            *RA = 1;
        else if (tail_A_position != target_p_A && target_p_A >= count_node(*A)/2)
            *RRA = 1;
        else
            *stop = 1;
    }
    else if (curr_B_rank < get_lowest_rank(A))
    {
        if ((*A)->position != target_p_A && target_p_A <= count_node(*A)/2)
            *RA = 1;
        else if ((*A)->position != target_p_A && target_p_A > count_node(*A)/2)
            *RRA = 1;
        else
            *stop = 1;
    }
}