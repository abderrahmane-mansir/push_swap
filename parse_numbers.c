/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansir <amansir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:00:00 by amansir           #+#    #+#             */
/*   Updated: 2026/02/25 01:44:39 by amansir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	safe_atoi(const char *s)
{
	long long	n;
	int			sign;
	int			i;

	n = 0;
	sign = 1;
	i = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		n = n * 10 + (s[i] - '0');
		i++;
	}
	return ((int)(n * sign));
}

static int	check_duplicates(int *values, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (values[i] == values[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	*words_to_values(char **words, int count, char *nums)
{
	int	*values;
	int	i;

	values = (int *)malloc(sizeof(int) * count);
	if (!values)
	{
		free_words(words);
		free(nums);
		error_message();
	}
	i = -1;
	while (++i < count)
		values[i] = safe_atoi(words[i]);
	if (check_duplicates(values, count))
	{
		free(values);
		free_words(words);
		free(nums);
		error_message();
	}
	return (values);
}

int	*parse_numbers(char *nums, int *out_count)
{
	char	**words;
	int		count;
	int		*values;

	words = ft_split(nums, ' ');
	if (!words)
	{
		free(nums);
		error_message();
	}
	count = count_words(words);
	if (!validate_words(words, count))
	{
		free_words(words);
		free(nums);
		error_message();
	}
	values = words_to_values(words, count, nums);
	free_words(words);
	if (out_count)
		*out_count = count;
	return (values);
}
