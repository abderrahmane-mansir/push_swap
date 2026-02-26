/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansir <amansir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 00:00:00 by amansir           #+#    #+#             */
/*   Updated: 2026/02/26 00:12:22 by amansir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_stack_indices(t_stack *stack)
{
	t_node	*cur;
	int		idx;

	cur = stack->top;
	idx = 0;
	while (cur)
	{
		cur->index = idx;
		idx++;
		cur = cur->next;
	}
}
