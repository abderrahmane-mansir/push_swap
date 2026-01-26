/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansir <amansir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:55:06 by amansir           #+#    #+#             */
/*   Updated: 2026/01/21 18:09:54 by amansir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*char_checker(char *nums)
{
	int i;

	i = 0;
	while (nums[i])
	{
		if (!is_sign(nums[i]) && !is_space(nums[i]))
			error_message();
		i++;
	}
	return (nums);
}

char	*sign_checker(char *nums)
{
    int i = 0;

    while (nums[i])
    {
        if (is_sign(nums[i]))
        {
            if (!is_digit(nums[i + 1]))
                return ("Error not digit\n");
            if (i > 0 && !is_space(nums[i - 1]))
                return ("Error not sign\n");
        }
        else if (!is_digit(nums[i]) && !is_space(nums[i]))
        {
			printf("%s",nums);
            return ("Error not digit or space\n");
        }
        i++;
    }
    return (nums);
}
