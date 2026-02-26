# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amansir <amansir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/05 12:06:44 by amansir           #+#    #+#              #
#    Updated: 2026/02/26 13:06:21 by amansir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

SRCS = ft_split.c ft_strjoin.c parsing.c basic_check.c checking.c \
		parse_numbers.c parse_numbers_validate.c stack.c swap.c \
		indexing.c radix_sort.c main.c push.c rotate.c reverse_rotate.c \
		sort_small.c

OB = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

$(NAME): $(SRCS) $(OB)
	$(CC) $(CFLAGS) -o $@ $(SRCS)
	
all: $(NAME)

clean:
	rm -f $(OB)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : clean fclean