/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_Input_ITOA.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:36:17 by folim             #+#    #+#             */
/*   Updated: 2023/07/05 21:36:18 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	exit_message()
{
	ft_printf("Error\n");
	exit(1);
}


void argc_more_than_one(int argc)
{
    if (argc < 2)
    {
        ft_printf("Error\n");
        exit (1);
    }
}

void no_space_and_character_allowed(char **str)
{
    int c;
    int d;

    c = 1;
    while(str[c])
    {
        d = 0;
        while(str[c][d])
        {
            if(c > 1 && str[c][d] == ' ')
                exit_message();
            if(str[1][d] == ' ')
			{
				if(str[2])
					exit_message();
			}
            if(str[c][d] != ' ' && str[c][d] != '-' && (str[c][d] < '0' || str[c][d] > '9'))
				exit_message();
            d++;
        }
        c++;
    }
}

char **split_string(char **str)
{
	char **output;
	int c;
	int d;

	if (!str[2])
	{
		c = 1;
		output = ft_split(str[c], ' ');
		d = 0;
		while(output[d])
			d++;
	}
	return (output);
}

t_node *ll_convert(char **str)
{
    t_node *head;
    long nb;
    int c;
	int	d;

    head = NULL;
    c = 0;
    d = 0;
    while (str[c])
    {
        nb = ft_atoi(str[c]);
		if (nb < -2147483648 || nb > 2147483647)
			exit_message();
		insert_back(&head, nb);
        c++;
    }
    return (head);
}

void	sorting_type_assign(t_node **A, t_node **B, t_node **output)
{
	check_duplicate(A);
	if (!check_sorted(A))
	{   
		if(c_node(*A) <= 3)
			tiny_sort(A, output);
		else if(c_node(*A) <= 5)
			medium_sort(A, B, output);
		else
			mega_sort_two(A, B, output);
	}
}

int main(int argc, char *argv[])
{
	t_node	*A;
	t_node	*B;
	t_node	*output;
	char	**str;

	A = NULL;
	B = NULL;
	output = NULL;
	argc_more_than_one(argc);
	no_space_and_character_allowed(argv);
	if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		A = ll_convert(str);
	}
	else
		A = ll_convert(argv+1);
	sorting_type_assign(&A, &B, &output);
	print_output(&output);
	delete_list(&output);
	delete_list(&A);
	delete_list(&B);
	// system("leaks -q push_swap");
	return (0);
}