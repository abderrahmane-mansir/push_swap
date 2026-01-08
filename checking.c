/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansir <amansir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:55:06 by amansir           #+#    #+#             */
/*   Updated: 2026/01/05 18:12:18 by amansir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*char_checker(char *nums)
{
	int i;

	i = 0;
	while (nums[i])
	{
		if (!(is_digit(nums[i]) || is_plus(nums[i]) || is_minus(nums[i]) || is_space(nums[i])))
		{
			nums = "Error\n";
			return (nums);
		}
		i++;
	}
	return (nums);
}

char	*sign_checker(char *nums)
{
	int i;

	i = 0;
	while (nums[i])
	{
		if ((is_plus(nums[i]) || is_minus(nums[i])) && !(is_digit(nums[i+1])))
		{
			nums = "Error\n";
			return (nums);
		}
		i++;
	}
	return (nums);
}
