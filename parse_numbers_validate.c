/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers_validate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansir <amansir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:00:00 by amansir           #+#    #+#             */
/*   Updated: 2026/02/25 01:55:13 by amansir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char **words)
{
	int	count;

	count = 0;
	while (words[count])
		count++;
	return (count);
}

void	free_words(char **words)
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

static void signer(char *word, int *sign, int *j)
{
    if (word[*j] == '+' || word[*j] == '-')
	{
		if (word[*j] == '-')
			*sign = -1;
        else
            *sign = 1;
		(*j)++;
	}
}

static int	is_valid_word(char *word)
{
	int			j;
	long long	n;
	int			sign;

	j = 0;
	n = 0;
    signer(word, &sign, &j);
	if (word[j] == '\0')
		return (0);
	while (word[j])
	{
		if (!is_digit(word[j]))
			return (0);
		n = n * 10 + (word[j] - '0');
		if ((sign > 0 && n > 2147483647)
			|| (sign < 0 && n > 2147483648))
			return (0);
		j++;
	}
	return (1);
}

int	validate_words(char **words, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!is_valid_word(words[i]))
			return (0);
		i++;
	}
	return (1);
}
