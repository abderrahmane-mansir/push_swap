/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansir <amansir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:50:54 by amansir           #+#    #+#             */
/*   Updated: 2026/01/15 17:33:24 by amansir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_sign(int c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	is_space(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}
