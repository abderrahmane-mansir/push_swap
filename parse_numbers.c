/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansir <amansir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:00:00 by amansir           #+#    #+#             */
/*   Updated: 2026/02/24 17:28:07 by amansir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char **words)
{
	int	count;

	count = 0;
	while (words[count])
		count++;
	return (count);
}

static void	free_words(char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}

static int	safe_atoi(const char *s)
{
	long long	n;
	int		sign;
	int		i;

	n = 0;
	sign = 1;
	i = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	if (s[i] == '\0')
		error_message();
	while (s[i])
	{
		if (!is_digit(s[i]))
			error_message();
		if (n > (2147483647 - (s[i] - '0')) / 10)
			error_message();
		n = n * 10 + (s[i] - '0');
		i++;
	}
	return ((int)(n * sign));
}

static void	check_duplicates(int *values, int count)
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
				error_message();
			j++;
		}
		i++;
	}
}

int	*parse_numbers(char *nums, int *out_count)
{
	char	**words;
	int		count;
	int		*values;
	int		i;

	words = ft_split(nums, ' ');
	if (!words)
		error_message();
	count = count_words(words);
	values = (int *)malloc(sizeof(int) * count);
	if (!values)
	{
		free_words(words);
		error_message();
	}
	i = -1;
	while (++i < count)
		values[i] = safe_atoi(words[i]);
	check_duplicates(values, count);
	free_words(words);
	if (out_count)
		*out_count = count;
	return (values);
}
