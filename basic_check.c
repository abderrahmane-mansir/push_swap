/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansir <amansir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:50:54 by amansir           #+#    #+#             */
/*   Updated: 2026/01/05 14:28:12 by amansir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_plus(int c)
{
	if (c == '+')
		return (1);
	return (0);
}

int	is_minus(int c)
{
	if (c == '-')
		return (1);
	return (0);
}

int	is_space(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	is_twins(char *nums, int c, int p)
{
	int i;

	i = 0;
	while (nums[i])
	{
		if (i == p)
			i++;
		if (nums[i] == c)
			return (1);
		i++;
	}
	return (0);
}
