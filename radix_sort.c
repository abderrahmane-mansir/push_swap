/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansir <amansir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 00:10:00 by amansir           #+#    #+#             */
/*   Updated: 2026/02/26 11:43:51 by amansir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	t_node	*tmp;
	int		i;

	i = 0;
	if (!lst)
		return (0);
	tmp = lst->top;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	max_bits;
	int	max;
	int	size;

	size = a->size;
	max = size - 1;
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	j = 0;
	while (j < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((a->top->index >> j) & 1) == 0)
				ft_pb(a, b);
			else
				ft_ra(a);
			i++;
		}
		while (b->size)
			ft_pa(a, b);
		j++;
	}
}
