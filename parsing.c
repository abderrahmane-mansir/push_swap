/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansir <amansir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:30:56 by amansir           #+#    #+#             */
/*   Updated: 2026/02/26 01:28:56 by amansir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_message(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static int	is_empty(char *str)
{
	if (!str || !str[0])
		error_message();
	while (*str)
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

char	*parser(int ac, char **av)
{
	char	*nums;
	int		i;

	i = 0;
	if (av[1][0] == '\0')
		error_message();
	while (i < ac)
	{
		if (is_empty(av[i]))
			error_message();
		i++;
	}
	nums = joiner(ac, av);
	if (!char_checker(nums))
	{
		free(nums);
		error_message();
	}
	if (!sign_checker(nums))
	{
		free(nums);
		error_message();
	}
	return (nums);
}
