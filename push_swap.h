/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 22:29:16 by folim             #+#    #+#             */
/*   Updated: 2023/07/05 22:29:18 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_node
{
	int				x;
	int				rank;
	int				position;
	int				chunk_id;
	int				sorted_h_tail;
	int				num_chunk;
	int				inner_chunk[100];
	int				outer_chunk[100];
	int				median;
	char			*str;
	struct s_node	*curr_b;
	struct s_node	*next;
	struct s_node	*prev;
}		t_node;

typedef struct s_var
{
	int	i;
	int c1;
	int	c2;
	int	ra;
	int rb;
	int rra;
	int rrb;
	int stop;
	int	tail_a_p;

}		t_var;


// check 1
int		check_sorted(t_node **A);
int		check_sorted_reverse(t_node **A);
void	check_duplicate(t_node **A);
void	argc_more_than_one(int argc);
void	no_space_and_character_allowed(char **str);
// check 2
int		check_sorted_plus(t_node **A);
void	exit_message();


// utils 1
void 	view_list(t_node *lst);
void	view_list_rank(t_node *lst);
void	view_list_position(t_node *lst);
void 	view_list_backward(t_node *lst);
void 	view_all(t_node *lst, t_node *lst2);
// utils 2
t_node	*double_ll_convert(t_node **lst);
void	insert_back(t_node **lst, int value);
void	delete_list(t_node **lst);
void	label_ranking(t_node **lst);
void 	label_position(t_node **lst);
// utils 3
int		c_node(t_node *lst);
int		get_largest(t_node **lst);
int		get_smallest(t_node **lst);
int		get_lowest_rank(t_node **lst);
int		get_highest_rank(t_node **lst);
// utils 4
int		last_node_value(t_node *lst);

// push operations 1
void	sa(t_node **A, t_node **output, int print);
void	sb(t_node **B, t_node **output, int print);
void	ss(t_node **A, t_node **B, t_node **output, int print);
void	pa(t_node **A, t_node **B, t_node **output, int print);
void 	pb(t_node **A, t_node **B, t_node **output, int print);
// push operations 2
void	ra(t_node **A, t_node **output, int print);
void	rb(t_node **B, t_node **output, int print);
void 	rr(t_node **A, t_node **B, t_node **output, int print);
void 	rra(t_node **A, t_node **output, int print);
void	rrb(t_node **B, t_node **output, int print);
// push operations 3
void	rrr(t_node **A, t_node **B, t_node **output, int print);
void    print_output(t_node **output);

// sorting category file
void	sorting_type_assign(t_node **A, t_node **B, t_node **output);
void	tiny_sort(t_node **A, t_node **output);
void	medium_sort(t_node **A, t_node **B, t_node **output);
void 	mega_sort_two(t_node **A, t_node **B, t_node **output);



// ft_printf files 1
void	*ft_bzero(void	*str, size_t	n);
void	*f_calloc(size_t	nmemb, size_t	size);
int		ft_convesion(va_list args, char c, int count);
int		ft_putchar(int c, int count);
int		ft_putstr(char *str, int count);
// ft_printf files 2
int		ft_putnbr(int nb, int count);
int		ft_un_int_putnbr(unsigned int nb, int count);
int		ft_hexadecimal(unsigned int nb, int c, int count);
int		ft_pointer(void *ptr, int count);
int		ft_puthexadecimal(uintptr_t address, int count);
// ft_prinft files 3
int		ft_printf(const char *str, ...);

// utilities functions
long		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	**split_string(char **str);
void	chunk_maker(int nn, int *chunk, int denominator);


//	mega sort utils 1
void	view_chunk(int *chunk, int num_chunk);
int		ps_chk_id(t_node **lst, int chunk_one, int chunk_two);
int		ps_chk_id_r(t_node **lst, int chunk_one, int chunk_two);
int		va_wi_ch_av(t_node **lst, int *chunk, int i);
int		chunkID_avalable(t_node **lst, int id);
//	mega sort utils 2
void	PB_multi_find_chunkID(t_node **A, t_node **B, t_node **output, t_var *c);
void	lable_chunk(t_node **lst, t_node **output);
void	rotate(t_node **A, t_node **B, t_var *op, t_node **output);
void	reverse_rotate(t_node **A, t_node **B, t_var *op, t_node **output);
int		check_sorted_h_tail(t_node **lst);
//	mega sort utils 3
void	push_top_chunk_attach(t_node **A, t_node **B, t_var *r, t_node **output);
void	push_top_chunk(t_node **A, t_node **B, t_var *r, t_node **output);
void	inner_chunk_maker(t_node **output, int nn);
void	outer_chunk_maker(t_node **output, int nn);
int		target_A_largest_B(t_node **A, int rank_b);
//	mega sort utils 4
int		target_A_smallest_B(t_node **A, int rank_b);
int		target_A_poaition_h(t_node **A, int rank_b);
int		target_A(t_node **A, int rank_b);
int		find_rank_of_position(t_node **lst, int position);
int		is_even(int num);
//	mega sort utils 5
int		get_target_p_A(t_node **A, int curr_B_rank);
void	top_A_one(t_node **A, t_var *op, int target_p_a, int curr_B_rank);
void	top_A_two(t_node **A, t_var *op, int target_p_a, int curr_B_rank);
void	reset_op(t_var *op);
void	push_a(t_node **A, t_node **B, t_node **output, int target_p_a);
//	mega sort utils 6
void	decending_from_top(t_node **A, t_node **B, t_node **output, int until_chunk);
void	decending_from_bottom(t_node **A, t_node **B, t_node **output, int until_chunk);
int		get_median_rank_within_chunk(t_node **lst, int chunkID);
void	rotate_below_median_top(t_node **A, t_node **B, t_node **output, int chunkID);
void	rotate_below_median_bottom(t_node **A, t_node **B, t_node **output, int chunkID);
//	mega sort utils 7
void	split_chunk_top(t_node **A, t_node **B, t_node **output, int chunkID);
int		split_chunk_bottom(t_node **A, t_node **B, t_node **output, int chunkID);
int		ghighest_rankwithin_chunk(t_node **lst, int chunkID);
int		glowest_rankwithin_chunk(t_node **lst, int chunkID);
int		get_three_median(t_node **B, int chunkID, int choose);
//	mega sort utils 8
int		above_median_available(t_node **lst, int median);
int		finalization_attach(t_node **A, t_node **B, t_node **output, int m);
int		finalization(t_node **A, t_node **B, t_node **output);
void	quick_sort(t_node **A, t_node **B, t_node **output);
int		final_sort(t_node **A, t_node **output);

// unused files
void	mega_sort_one(t_node **A, t_node **B, t_node **output);
void	insert_front(t_node **lst, int value);
void	insert_after(t_node *lst, int value);
void	insert_sorted(t_node **lst, int value);
void	delete_an_element(t_node **lst, int value);
void	delete_all_element(t_node **lst, int value);
void	reverse(t_node **lst);
int		check_loop(t_node *lst);
int		ps_w_chk(t_node **A, int *chunk, int i);
int		ps_w_chk_r(t_node **A, int *chunk, int i);
void	push_A_single_way_find(t_node **A, t_node **B, t_node **output, int *chunk, int i);
int		push_B_multi_way_find(t_node **A, t_node **B, t_node **output, int *chunk, int i);
int		c_node_wc(t_node *lst, int chunkID);
int		get_four_median(t_node **B, int chunkID, int choose);
int		get_median(t_node *lst);
#endif