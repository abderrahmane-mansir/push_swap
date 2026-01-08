/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansir <amansir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:29:18 by amansir           #+#    #+#             */
/*   Updated: 2026/01/05 12:02:58 by amansir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	word_counter(char const *s, char c)
{
	int	i;
	int	r;

	i = 0;
	r = 1;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
			r++;
		i++;
	}
	return (r);
}

char	*word_copier(char const *p, char const *s)
{
	int		i;
	char	*copy;

	i = 0;
	copy = (char *)malloc(s - p + 1);
	if (!copy)
		return (NULL);
	while (p < s)
	{
		copy[i] = *p;
		p++;
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	**str_freer(char **res, int i)
{
	while (i > 0)
	{
		i--;
		free(res[i]);
	}
	free(res);
	return (NULL);
}

char	**result_maker(char const *s, char c, char const *p, char **res)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			p = s;
			while (*s && *s != c)
				s++;
			res[i] = word_copier(p, s);
			if (!res[i])
				return (str_freer(res, i));
			i++;
		}
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char const	*p;
	char		**res;

	p = NULL;
	if (!s)
		return (NULL);
	res = (char **)malloc((word_counter(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	return (result_maker(s, c, p, res));
}
