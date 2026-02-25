/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansir <amansir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:55:06 by amansir           #+#    #+#             */
/*   Updated: 2026/02/24 20:06:03 by amansir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	char_checker(char *nums)
{
	int	i;

	i = 0;
	while (nums[i])
	{
		if (!is_sign(nums[i]) && !is_space(nums[i]) && !is_digit(nums[i]))
			return (0);
		i++;
	}
	return (1);
}

int	sign_checker(char *nums)
{
	int	i;

	i = 0;
	while (nums[i])
	{
		if (is_sign(nums[i]))
		{
			if (!is_digit(nums[i + 1]))
				return (0);
			if (i > 0 && !is_space(nums[i - 1]))
				return (0);
		}
		else if (!is_digit(nums[i]) && !is_space(nums[i]))
			return (0);
		i++;
	}
	return (1);
}
