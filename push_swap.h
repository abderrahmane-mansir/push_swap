/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansir <amansir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 10:39:29 by amansir           #+#    #+#             */
/*   Updated: 2026/02/26 10:26:57 by amansir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				index;
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

void		set_stack_rank(t_stack *stack);
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
int			push(t_stack *stack, int value);
void		free_stack(t_stack *stack);
void		push_node(t_stack *from, t_stack *to);
void		rotate_node(t_stack *stack);
t_stacks	*init_stacks(int *values, int count);
void		free_stacks(t_stacks *stacks);
void		radix_sort(t_stack *a, t_stack *b);
int			ft_lstsize(t_stack *lst);
void		ft_sa(t_stack *a);
void		ft_sb(t_stack *b);
void		ft_ss(t_stack *a, t_stack *b);
void		ft_pa(t_stack *a, t_stack *b);
void		ft_pb(t_stack *a, t_stack *b);
void		ft_ra(t_stack *a);
void		ft_rb(t_stack *b);
void		ft_rr(t_stack *a, t_stack *b);
void		ft_rra(t_stack *a);
void		ft_rrb(t_stack *b);
void		ft_rrr(t_stack *a, t_stack *b);

#endif
