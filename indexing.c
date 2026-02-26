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

#include "push_swap.h"

void	set_stack_rank(t_stack *stack)
{
	t_node	*cur;
	t_node	*cmp;
	int		rank;

	cur = stack->top;
	while (cur)
	{
		rank = 0;
		cmp = stack->top;
		while (cmp)
		{
			if (cmp->value < cur->value)
				rank++;
			cmp = cmp->next;
		}
		cur->index = rank;
		cur = cur->next;
	}
}
