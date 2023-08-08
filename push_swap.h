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
// # include <stdio.h>
# include <limits.h>

typedef struct s_node
{
	int				x;
	int				c;
	int				rank;
	int				position;
	int				chunk_id;
	int				sorted_h_tail;
	int				num_chunk;
	int				inner_chunk[100];
	int				outer_chunk[100];
	int				median;
	int				largest;
	int				smallest;
	char			*str;
	struct s_node	*curr_b;
	struct s_node	*next;
	struct s_node	*prev;
}t_node;

typedef struct s_var
{
	int	i;
	int	c1;
	int	c2;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	stop;
	int	tail_a_p;

}t_var;


// check_1
int		check_sorted(t_node **a);
int		check_sorted_reverse(t_node **a);
void	check_duplicate(t_node **a);
void	no_space_and_character_allowed(char **str);
int		check_sorted_plus(t_node **a);

// utils 1
void	view_list(t_node *lst);
void	view_list_rank(t_node *lst);
void	view_list_position(t_node *lst);
void	view_list_backward(t_node *lst);
void	view_all(t_node *lst, t_node *lst2);
// utils 2
t_node	*double_ll_convert(t_node **lst);
void	insert_back(t_node **lst, int value);
void	delete_list(t_node **lst);
void	label_ranking(t_node **lst);
void	label_position(t_node **lst);
// utils 3
int		c_n(t_node *lst);
int		get_largest(t_node **lst);
int		get_smallest(t_node **lst);
int		get_lowest_rank(t_node **lst);
int		get_highest_rank(t_node **lst);
// utils 4
int		last_node_value(t_node *lst);
void	exit_message(void);
long	ft_atoi(const char *str);
t_node	*ll_convert(char **str);

// operations 1
void	sa(t_node **a, t_node **b, t_node **otpt, int print);
void	sb(t_node **a, t_node **b, t_node **otpt, int print);
void	ss(t_node **a, t_node **b, t_node **otpt, int print);
void	pa(t_node **a, t_node **b, t_node **otpt, int print);
void	pb(t_node **a, t_node **b, t_node **otpt, int print);
// operations 2
void	ra(t_node **a, t_node **b, t_node **otpt, int print);
void	rb(t_node **a, t_node **b, t_node **otpt, int print);
void	rr(t_node **a, t_node **b, t_node **otpt, int print);
void	rra(t_node **a, t_node **b, t_node **otpt, int print);
void	rrb(t_node **a, t_node **b, t_node **otpt, int print);
// operations 3
void	rrr(t_node **a, t_node **b, t_node **otpt, int print);
void	print_output(t_node **otpt);
int		optimizer(t_node **otpt, int find, int substi);
void	mega_sort(t_node **a, t_node **b, t_node **otpt);

// sorting category file
void	sorting_type_assign(t_node **a, t_node **b, t_node **otpt);
void	tiny_sort_attach(t_node **a, t_node **b, t_node **otpt, t_node *curr);
void	tiny_sort(t_node **a, t_node **b, t_node **otpt);
void	medium_sort_attach(t_node **a, t_node **b, t_node **otpt);
void	medium_sort(t_node **a, t_node **b, t_node **otpt);

// ft_printf_utils
int		ft_putchar(int c, int count);
int		ft_putstr(char *str, int count);
int		ft_putnbr(int nb, int count);
int		ft_un_int_putnbr(unsigned int nb, int count);
void	*ft_bzero(void	*str, size_t n);
// ft_printf
void	*f_calloc(size_t	nmemb, size_t	size);
int		ft_convesion(va_list args, char c, int count);
int		ft_printf(const char *str, ...);

// ft_hexapointer
int		ft_hexadecimal(unsigned int nb, int c, int count);
int		ft_puthexadecimal(uintptr_t address, int count);
int		ft_pointer(void *ptr, int count);

//ft_split
char	**ft_split(char const *s, char c);

//	mega sort utils 1
void	view_chunk(int *chunk, int num_chunk);
int		ps_c_id(t_node **lst, int chunk_one, int chunk_two);
int		ps_c_id_r(t_node **lst, int chunk_one, int chunk_two);
int		va_wi_ch_av(t_node **lst, int *chunk, int i);
int		chunkid_avalable(t_node **lst, int id);
//	mega sort utils 2
void	pb_m_f_cid(t_node **a, t_node **b, t_node **otpt, t_var *c);
void	lable_chunk(t_node **lst, t_node **otpt);
void	rotate(t_node **a, t_node **b, t_var *op, t_node **otpt);
void	reverse_rotate(t_node **a, t_node **b, t_var *op, t_node **otpt);
int		check_sorted_h_tail(t_node **lst);
//	mega sort utils 3
void	push_top_chunk_attach(t_node **a, t_node **b, t_var *r, t_node **otpt);
void	push_top_chunk(t_node **a, t_node **b, t_var *r, t_node **otpt);
void	inner_chunk_maker(t_node **otpt, int nn);
void	outer_chunk_maker(t_node **otpt, int nn);
int		target_a_largest_b(t_node **a, int rank_b);
//	mega sort utils 4
int		target_a_smallest_b(t_node **a, int rank_b);
int		target_a_poaition_h(t_node **a, int rank_b);
int		target_a(t_node **a, int rank_b);
int		find_rank_of_position(t_node **lst, int position);
int		is_even(int num);
//	mega sort utils 5
int		get_target_p_a(t_node **a, int curr_B_rank);
void	top_a_one(t_node **a, t_var *op, int target_p_a, int curr_B_rank);
void	top_a_two(t_node **a, t_var *op, int target_p_a, int curr_B_rank);
void	reset_op(t_var *op);
void	push_a(t_node **a, t_node **b, t_node **otpt, int target_p_a);
//	mega sort utils 6
void	decend_top(t_node **a, t_node **b, t_node **otpt, int until_chunk);
void	decending_bot(t_node **a, t_node **b, t_node **otpt, int until_chunk);
int		get_median_rank_within_chunk(t_node **lst, int chunkid);
void	rot_b_median_top(t_node **a, t_node **b, t_node **otpt, int chunkid);
void	rot_b_median_bot(t_node **a, t_node **b, t_node **otpt, int chunkid);
//	mega sort utils 7
void	split_chunk_top(t_node **a, t_node **b, t_node **otpt, int chunkid);
void	split_chunk_bottom(t_node **a, t_node **b, t_node **otpt, int chunkid);
int		ghighest_rankwithin_chunk(t_node **lst, int chunkid);
int		glowest_rankwithin_chunk(t_node **lst, int chunkid);
int		get_three_median(t_node **b, int chunkid, int choose);
//	mega sort utils 8
int		above_median_available(t_node **lst, int median);
void	finalization_attach(t_node **a, t_node **b, t_node **otpt, int m);
void	finalization(t_node **a, t_node **b, t_node **otpt);
void	quick_sort(t_node **a, t_node **b, t_node **otpt);
void	final_sort(t_node **a, t_node **b, t_node **otpt);

// unused files
void	mega_sort_one(t_node **a, t_node **b, t_node **otpt);
void	insert_front(t_node **lst, int value);
void	insert_after(t_node *lst, int value);
void	insert_sorted(t_node **lst, int value);
void	delete_an_element(t_node **lst, int value);
void	delete_all_element(t_node **lst, int value);
void	reverse(t_node **lst);
int		check_loop(t_node *lst);
int		ps_w_chk(t_node **a, int *chunk, int i);
int		ps_w_chk_r(t_node **a, int *chunk, int i);
void	pa_s_w_f(t_node **a, t_node **b, t_node **otpt, int *chunk, int i);
int		pb_m_w_f(t_node **a, t_node **b, t_node **otpt, int *chunk, int i);
int		c_node_wc(t_node *lst, int chunkid);
int		get_four_median(t_node **b, int chunkid, int choose);
int		get_median(t_node *lst);
#endif