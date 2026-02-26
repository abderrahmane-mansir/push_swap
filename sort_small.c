/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansir <amansir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:02:03 by amansir           #+#    #+#             */
/*   Updated: 2026/02/26 13:05:21 by amansir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*ft_find_max_rank(t_stack *stack)
{
    t_node	*max_node;
    t_node	*current;

    if (!stack || !stack->top)
        return (NULL);
    max_node = stack->top;
    current = stack->top->next;
    while (current)
    {
        if (current->index > max_node->index)
            max_node = current;
        current = current->next;
    }
    return (max_node);
}

static t_node	*ft_find_min_rank(t_stack *stack)
{
    t_node	*min_node;
    t_node	*current;

    if (!stack || !stack->top)
        return (NULL);
    min_node = stack->top;
    current = stack->top->next;
    while (current)
    {
        if (current->index < min_node->index)
            min_node = current;
        current = current->next;
    }
    return (min_node);
}

void	sort_3(t_stack *a)
{
	t_node	*max_node;

	max_node = ft_find_max_rank(a);
	if (a->top == max_node)
		ft_ra(a);
	else if (a->top->next == max_node)
		ft_rra(a);
	if (a->top->index > a->top->next->index)
		ft_sa(a);
}

void	sort_5(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		t_node	*min_node = ft_find_min_rank(a);
		if (a->top == min_node)
			ft_pb(a, b);
		else if (a->top->next == min_node)
			ft_sa(a);
		else
			ft_ra(a);
	}
	sort_3(a);
	while (b->size > 0)
		ft_pa(a, b);
}
