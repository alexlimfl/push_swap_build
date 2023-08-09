/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 21:57:15 by folim             #+#    #+#             */
/*   Updated: 2023/08/08 21:57:17 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

void	view_all(t_node *lst, t_node *lst2);
void	exit_message(void);
t_node	*ll_convert(char **str);
void	delete_list(t_node **lst);
char	**ft_split(char const *s, char c);
void	no_space_and_character_allowed(char **str);
void	check_duplicate(t_node **a);
int		check_sorted(t_node **a);
int		c_n(t_node *lst);

size_t	ft_strlen(const char *str);
void	*ft_bzero(void	*str, size_t	n);
void	*ft_calloc(size_t	nmemb, size_t	size);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_get_line_after_newline(char *s_str);
char	*ft_get_line_before_newline(char *s_str);
char	*ft_get_line_read(int fd, char *s_str);
char	*get_next_line(int fd);

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
void	clear_ll_exit(t_node **a, t_node **b, t_node **otpt, int s);


int	ft_printf(const char	*str, ...);
int	ft_strncmp(const char *str1, const char *str2, size_t n);




#endif
