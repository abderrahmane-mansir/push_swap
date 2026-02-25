/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansir <amansir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:10:00 by amansir           #+#    #+#             */
/*   Updated: 2026/02/25 06:24:53 by amansir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	str_len(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static void	write_str(const char *s)
{
	write(1, s, str_len(s));
}

static void	write_char(char c)
{
	write(1, &c, 1);
}

static void	write_int(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write_char('-');
		nb = -nb;
	}
	if (nb >= 10)
		write_int((int)(nb / 10));
	write_char((char)('0' + (nb % 10)));
}

static char	*dup_str(const char *s)
{
	char	*dst;
	size_t	i;
	size_t	len;

	len = str_len(s);
	dst = (char *)malloc(len + 1);
	if (!dst)
		error_message();
	i = 0;
	while (i < len)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static void	print_stack_forward(t_stack *stack)
{
	t_node	*cur;

	write_str("forward: ");
	cur = stack->top;
	while (cur)
	{
		write_int(cur->value);
		write_char(' ');
		cur = cur->next;
	}
	write_char('\n');
}

static void	print_stack_backward(t_stack *stack)
{
	t_node	*cur;
	t_node	*tail;

	write_str("backward: ");
	cur = stack->top;
	tail = NULL;
	while (cur)
	{
		tail = cur;
		cur = cur->next;
	}
	while (tail)
	{
		write_int(tail->value);
		write_char(' ');
		tail = tail->prev;
	}
	write_char('\n');
}

static int	verify_prev_links(t_stack *stack)
{
	t_node	*cur;
	t_node	*prev;

	cur = stack->top;
	prev = NULL;
	while (cur)
	{
		if (cur->prev != prev)
			return (0);
		prev = cur;
		cur = cur->next;
	}
	return (1);
}

int	main(void)
{
	char		*nums;
	int			*values;
	int			count;
	t_stacks	*stacks;

	nums = dup_str("3 2 -1 0 5");
	values = parse_numbers(nums, &count);
	stacks = init_stacks(values, count);
	print_stack_forward(stacks->a);
	print_stack_backward(stacks->a);
	if (verify_prev_links(stacks->a))
		write_str("prev links: OK\n");
	else
		write_str("prev links: ERROR\n");
	free_stacks(stacks);
	free(values);
	free(nums);
	return (0);
}
