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
	struct s_node	*next;
	struct s_node	*prev;
}		t_node;

typedef struct s_var
{
	int	ra;
	int rb;
	int rra;
	int rrb;
	int stop;

}		t_var;

// linked list functions
void 	view_list(t_node *lst);
void	view_list_rank(t_node *lst);
void	view_list_position(t_node *lst);
void 	view_all(t_node *lst, t_node *lst2);
void 	view_list_backward(t_node *lst);
void	insert_back(t_node **lst, int value);
void	delete_list(t_node **lst);
void	insert_front(t_node **lst, int value);
void	insert_after(t_node *lst, int value);
void	insert_sorted(t_node **lst, int value);
void	delete_an_element(t_node **lst, int value);
void	delete_all_element(t_node **lst, int value);
void	reverse(t_node **lst);
int		check_loop(t_node *lst);
int		c_node(t_node *lst);

// operations
void	sa(t_node **A, t_node **output, int print);
void	sb(t_node **B, t_node **output, int print);
void	ss(t_node **A, t_node **B, t_node **output, int print);
void	pa(t_node **A, t_node **B, t_node **output, int print);
void 	pb(t_node **A, t_node **B, t_node **output, int print);
void	ra(t_node **A, t_node **output, int print);
void	rb(t_node **B, t_node **output, int print);
void 	rr(t_node **A, t_node **B, t_node **output, int print);
void 	rra(t_node **A, t_node **output, int print);
void	rrb(t_node **B, t_node **output, int print);
void	rrr(t_node **A, t_node **B, t_node **output, int print);
void    print_output(t_node **output);

// sorting category
void	tiny_sort(t_node **A, t_node **output);
void	medium_sort(t_node **A, t_node **B, t_node **output);
void	mega_sort_one(t_node **A, t_node **B, t_node **output);
void 	mega_sort_two(t_node **A, t_node **B, t_node **output);

// check conditions
int		check_sorted(t_node **A);
int		check_sorted_reverse(t_node **A);
void	check_duplicate(t_node **A);
void	argc_more_than_one(int argc);
void	no_space_and_character_allowed(char **str);

// get values
int		get_largest(t_node **lst);
int		get_smallest(t_node **lst);
int		get_lowest_rank(t_node **lst);
int		get_highest_rank(t_node **lst);
int		get_median(t_node *lst);
int		last_node_value(t_node *lst);
void	label_ranking(t_node **lst);
void 	label_position(t_node **lst);


// ft_printf
void	*ft_bzero(void	*str, size_t	n);
void	*f_calloc(size_t	nmemb, size_t	size);
int		ft_convesion(va_list args, char c, int count);
int		ft_putchar(int c, int count);
int		ft_putstr(char *str, int count);
int		ft_putnbr(int nb, int count);
int		ft_un_int_putnbr(unsigned int nb, int count);
int		ft_hexadecimal(unsigned int nb, int c, int count);
int		ft_pointer(void *ptr, int count);
int		ft_puthexadecimal(uintptr_t address, int count);
int		ft_printf(const char *str, ...);

// utilities functions
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	**split_string(char **str);
t_node	*double_ll_convert(t_node **lst);
void	chunk_maker(int nn, int *chunk, int denominator);
int		ps_w_chk(t_node **A, int *chunk, int i);
int		ps_w_chk_r(t_node **A, int *chunk, int i);


// int		action_one_1(t_node **A, t_node **B, int rank_selected, int rank_selected_B, int middle_position, int middle_position_B, int position_selected, int position_selected_B, int n_operation);
// void	action_one_2(t_node **A, t_node **B, int rank_selected, int rank_selected_B, int middle_position, int middle_position_B, int position_selected, int position_selected_B);


int		main(int argc, char *argv[]);

#endif