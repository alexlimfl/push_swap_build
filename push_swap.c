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
            if(c > 1 && str[c][d] == ' ') // if second argument contains ' '
            {
                ft_printf("'%c'\n", str[c][d]);
                ft_printf("Error\n");
                // ft_printf("Space found in argv[%d].\n", d);
                exit(1);
            }
            if(str[1][d] == ' ') // if first argument has ' '
                {
                    if(str[2]) // if second argument isn't NULL
                    {
                        ft_printf("Error\n");
                        exit(0);
                    }
                }
            if(str[c][d] != ' ' && (str[c][d] < '0' || str[c][d] > '9'))
            {
                ft_printf("'%c'\n", str[c][d]);
                ft_printf("Error\n");
                // ft_printf("Characters found in argv[%d].\n", d);
                exit(1);
            }
            d++;
        }
        c++;
    }
    // ft_printf("No space and character found\n");
}

char **split_string(char **str)// not neccesary, remove after complete
{
	char **output;
	int c;
	int d;

	if (!str[2]) //argv[2] isn't NULL
	{
		c = 1;
		output = ft_split(str[c], ' ');
		d = 0;
		while(output[d]) //loops when string is not null
		{
			ft_printf("string[%d]: %s\n", d, output[d]);
			d++;
		}
	}
	return (output);
}

Node *ll_convert(char **str)
{
    Node *head;
    head = NULL;
    int nb;
    int c,d;
    c = 0;
    d = 0;
    while (str[c])
    {
        nb = ft_atoi(str[c]);
		insert_back(&head, nb);
        c++;
    }
    return (head);
}

int main(int argc, char *argv[])
{
    
	int n_operation = 0;
    n_operation = 0;
    Node *A;
	Node *B;
    char **str;
    
    A = NULL;
    B = NULL;
	argc_more_than_one(argc);
    no_space_and_character_allowed(argv);
	if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		A = ll_convert(str);
	}
    else
        A = ll_convert(argv+1);

    if(count_node(A) < 2)
    {
        ft_printf("Error\n");
        exit(1);
    }

    check_duplicate(&A);
    // ft_printf("Operations >>>\n");
    
    if (!check_sorted(&A))
    {   
        if(count_node(A) <= 3)
            n_operation = tiny_sort(&A, n_operation);
        else if(count_node(A) <= 5)
            n_operation = medium_sort(&A, &B, n_operation);
        else
		    n_operation = mega_sort_one(&A, &B, n_operation);
    }

    // ft_printf("FINAL >>> \n");
    // ft_printf("Check sorted = %d\n", check_sorted(&A));
    // ft_printf("Check MAIN\n");
    // ft_printf("Number of operations: %d\n", n_operation);

    // ft_printf("Stack A:\n");
	// view_list(A);
    // ft_printf("Stack B:\n");
	// view_list(B);

    // ft_printf("Deallocation >>> \n");
	delete_list(&A);
	delete_list(&B);

    // ft_printf("Check memory leaks >>> \n");
	// system("leaks -q push_swap");

    return (0);
}