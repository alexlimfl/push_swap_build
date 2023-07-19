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
        printf("Error (no numbers found)\n");
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
                printf("'%c'\n", str[c][d]);
                printf("Error (space found)\n");
                // printf("Space found in argv[%d].\n", d);
                exit(1);
            }
            if(str[1][d] == ' ') // if first argument has ' '
                {
                    if(str[2]) // if second argument isn't NULL
                    {
                        printf("Error (empty argv)\n");
                        exit(0);
                    }
                }
            if(str[c][d] != ' ' && (str[c][d] < '0' || str[c][d] > '9'))
            {
                printf("'%c'\n", str[c][d]);
                printf("Error (characters found)\n");
                // printf("Characters found in argv[%d].\n", d);
                exit(1);
            }
            d++;
        }
        c++;
    }
    // printf("No space and character found\n");
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
			printf("string[%d]: %s\n", d, output[d]);
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
        printf("Error (less than one number)\n");
        exit(1);
    }

    check_duplicate(&A);

    // Stack B
    // insert_back(&B, 95);
    // insert_back(&B, 96);
    // insert_back(&B, 97);
    // insert_back(&B, 98);
    // insert_back(&B, 99);
    
    printf("///A\n");
	view_list(A);
    printf("///B\n");
	view_list(B);
    printf("checkpoint\n");
    
    if (!check_sorted(&A))
    {
        tiny_sort(&A);
        medium_sort(&A, &B);
    }

    printf("FINAL >>> ");
    
    check_sorted(&A);

    printf("///A\n");
	view_list(A);
    printf("///B\n");
	view_list(B);

    printf("checkpoint\n");

	delete_list(&A);
	delete_list(&B);

	printf("checkpoint\n");	

    printf("///A\n");
	view_list(A);
    printf("///B\n");
	view_list(B);

    return (0);
}