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

typedef struct Node
{
	int x;
	int rank;
	int position;
	int chunk_id;
	char *str;
	struct Node *next;
	struct Node *prev;
} Node;

// linked list functions
void 	view_list(Node *lst);
void	view_list_rank(Node *lst);
void	view_list_position(Node *lst);
void 	view_all(Node *lst, Node *lst2);
void 	view_list_backward(Node *lst);
void	insert_back(Node **lst, int value);
void	delete_list(Node **lst);
void	insert_front(Node **lst, int value);
void	insert_after(Node *lst, int value);
void	insert_sorted(Node **lst, int value);
void	delete_an_element(Node **lst, int value);
void	delete_all_element(Node **lst, int value);
void	reverse(Node **lst);
int		check_loop(Node *lst);
int		count_node(Node *lst);

// operations
void	sa(Node **A, int c);
void	sb(Node **B, int c);
void	ss(Node **A, Node **B);
void	pa(Node **A, Node **B);
void	pb(Node **A, Node **B);
void	ra(Node **A, int c);
void	rb(Node **B, int c);
void	rr(Node **A, Node **B);
void	rra(Node **A, int c);
void	rrb(Node **B, int c);
void	rrr(Node **A, Node **B);

// sorting category
int		tiny_sort(Node **A, int n_operation);
int		medium_sort(Node **A, Node **B, int n_operation);
int		mega_sort_one(Node **A, Node **B, int n_operation);
int		mega_sort_two(Node **A, Node **B, int n_operation);

// check conditions
int		check_sorted(Node **A);
int		check_sorted_reverse(Node **A);
void	check_duplicate(Node **A);
void	argc_more_than_one(int argc);
void	no_space_and_character_allowed(char **str);

// get values
int		get_largest(Node **lst);
int		get_smallest(Node **lst);
int		get_lowest_rank(Node **lst);
int		get_highest_rank(Node **lst);
int		get_median(Node *lst);
int		last_node_value(Node *lst);
void	label_ranking(Node **lst);
void 	label_position(Node **lst);


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
Node	*double_ll_convert(Node **lst);
void	chunk_maker(int nn, int *chunk, int denominator);
int	position_s_within_chunk(Node **A, int *chunk, int i);

// int		action_one_1(Node **A, Node **B, int rank_selected, int rank_selected_B, int middle_position, int middle_position_B, int position_selected, int position_selected_B, int n_operation);
// void	action_one_2(Node **A, Node **B, int rank_selected, int rank_selected_B, int middle_position, int middle_position_B, int position_selected, int position_selected_B);


int		main(int argc, char *argv[]);

#endif