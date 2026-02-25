/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansir <amansir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 10:39:29 by amansir           #+#    #+#             */
/*   Updated: 2026/02/25 04:11:51 by amansir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}	t_stacks;

char		**ft_split(char const *s, char c);
char		*ft_strjoin(char *s1, char *s2);
char		*parser(int ac, char **av);
char		*joiner(int ac, char **av);
int			char_checker(char *nums);
int 		sign_checker(char *nums);
int			*parse_numbers(char *nums, int *out_count);
int			count_words(char **words);
void		free_words(char **words);
int			validate_words(char **words, int count);
int			is_digit(int c);
int			is_space(int c);
int			is_sign(int c);
void		error_message(void);
t_stack		*create_stack(void);
void		push(t_stack *stack, int value);
void		free_stack(t_stack *stack);
t_stacks	*init_stacks(int *values, int count);
void		free_stacks(t_stacks *stacks);

#endif
