/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansir <amansir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:10:00 by amansir           #+#    #+#             */
/*   Updated: 2026/02/26 13:06:04 by amansir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*tmp;

	if (!stack || !stack->top)
		return (1);
	tmp = stack->top;
	while (tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	char		*nums;
	int			*values;
	int			count;
	t_stacks	*stacks;

	if (argc < 2)
		return (0);
	nums = parser(argc, argv);
	values = parse_numbers(nums, &count);
	stacks = init_stacks(values, count);
	set_stack_rank(stacks->a);
	if (!is_sorted(stacks->a))
	{
		if (stacks->a->size <= 5)
			sort_5(stacks->a, stacks->b);
		else
			radix_sort(stacks->a, stacks->b);
	}
	free_stacks(stacks);
	free(values);
	free(nums);
	return (0);
}
