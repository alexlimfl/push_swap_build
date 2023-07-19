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


NAME = push_swap.exe
CC = gcc
FLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
RCS = ar -rcs
RM = rm -rf
CFILES = $(wildcard ft_*.c) push_swap.c push_swap_utils.c
OBJS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(RCS) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: re
	$(CC) $(FLAGS) $(NAME) -o push_swap

.PHONY: all clean fclean re debug