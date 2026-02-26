/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansir <amansir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 01:37:19 by amansir           #+#    #+#             */
/*   Updated: 2026/02/26 10:28:26 by amansir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"


static void	ft_push(t_stack *src, t_stack *dest)
{
	t_node	*node_to_push;

	if (!src || !src->top)
		return ;
	node_to_push = src->top;
	src->top = src->top->next;
	if (src->top)
		src->top->prev = NULL;
	node_to_push->next = dest->top;
	if (dest->top)
		dest->top->prev = node_to_push;
	dest->top = node_to_push;
	dest->top->prev = NULL;
	src->size--;
	dest->size++;
}

void	ft_pa(t_stack *a, t_stack *b)
{
	ft_push(b, a);
	write(1,"pa\n", 3);
}

void	ft_pb(t_stack *a, t_stack *b)
{
	ft_push(a, b);
	write(1,"pb\n", 3);
}
