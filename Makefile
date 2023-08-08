# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 22:18:28 by folim             #+#    #+#              #
#    Updated: 2023/07/05 22:18:31 by folim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
BONUS_NAME = checker
CC = gcc
FLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
RCS = ar -rcs
RM = rm -rf
CFILES = push_swap.c check_1.c utils_1.c utils_2.c utils_3.c utils_4.c\
			operations_1.c operations_2.c operations_3.c sorting_category.c\
				ft_printf.c ft_printf_utils.c ft_hexapointer.c ft_split.c\
					mega_sort_utils_1.c mega_sort_utils_2.c mega_sort_utils_3.c mega_sort_utils_4.c\
						mega_sort_utils_5.c mega_sort_utils_6.c mega_sort_utils_7.c mega_sort_utils_8.c #$(wildcard ft_*.c)

CFILES_BONUS = checker.c check_1.c utils_1.c utils_2.c utils_3.c utils_4.c\
				operations_1.c operations_2.c operations_3.c sorting_category.c\
					ft_printf.c ft_printf_utils.c ft_hexapointer.c ft_split.c\
						mega_sort_utils_1.c mega_sort_utils_2.c mega_sort_utils_3.c mega_sort_utils_4.c\
							mega_sort_utils_5.c mega_sort_utils_6.c mega_sort_utils_7.c mega_sort_utils_8.c\
								ft_strncmp.c get_next_line.c get_next_line_utils.c

OBJS = $(CFILES:.c=.o)
OBJS_BONUS = $(CFILES_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $^ -o $(NAME)
#	$(RCS) $(NAME) $(OBJS)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_BONUS)
			$(CC) $(FLAGS) $^ -o $(BONUS_NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all



# debug: re
# 	$(CC) $(FLAGS) $(NAME) -o push_swap

.PHONY: all clean fclean re debug