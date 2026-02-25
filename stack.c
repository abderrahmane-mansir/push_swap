/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansir <amansir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:00:00 by amansir           #+#    #+#             */
/*   Updated: 2026/02/24 18:00:00 by amansir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		error_message();
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	if (!stack)
		error_message();
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		error_message();
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	free(stack);
}

t_stacks	*init_stacks(int *values, int count)
{
	t_stacks	*stacks;
	int			i;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		error_message();
	stacks->a = create_stack();
	stacks->b = create_stack();
	if (!stacks->a || !stacks->b)
	{
		free_stack(stacks->a);
		free_stack(stacks->b);
		free(stacks);
		error_message();
	}
	i = count - 1;
	while (i >= 0)
	{
		push(stacks->a, values[i]);
		i--;
	}
	return (stacks);
}

void	free_stacks(t_stacks *stacks)
{
	if (!stacks)
		return ;
	free_stack(stacks->a);
	free_stack(stacks->b);
	free(stacks);
}
