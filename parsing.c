/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansir <amansir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:30:56 by amansir           #+#    #+#             */
/*   Updated: 2026/01/03 18:44:05 by amansir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include"stdio.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (dest == src)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	len1;
	size_t	len2;

	if (s1 != NULL)
		len1 = ft_strlen(s1);
	else
		len1 = 0;
	if (s2 != NULL)
		len2 = ft_strlen(s2);
	else
		len2 = 0;
	joined = malloc(len1 + len2 + 1);
	if (!joined)
		return (NULL);
	if (s1)
		ft_memcpy(joined, s1, len1);
	if (s2)
		ft_memcpy(joined + len1, s2, len2);
	joined[len1 + len2] = '\0';
	return (joined);
}

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

char	*parser(int ac, char **av)
{
	int		i;
	char	*nums;
	
	nums = "";
	i = 1;
	while (i < ac)
	{
		av[i] = ft_strjoin(" ", av[i]);
		nums = ft_strjoin(nums, av[i]);
		i++;
		
	}
	return nums;
}

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

// char	*twin_checker(char *num)

int	ft_atoi(const char *nptr)
{
	long	n;
	int		s;
	int		i;

	s = 1;
	n = 0;
	i = 0;
	while (nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)(n * s));
}

int main(int argc,char *argv[])
{
	/*
		The program must work with several numerical arguments
		./push_swap 1 3 5 +9 20 -4 50 60 04 08
		
		The program also works if you receive a single character list as a parameter
		./push_swap "3 4 6 8 9 74 -56 +495"
		
		☑ ✓ The program should NOT work if it encounters another character
		The program should NOT work if it encounters a double number
		The program should work with INT MAX & INT MIN
		
		./push_swap "95 99 -9 10 9"
		this example should work because -9 & 9 are not equal

		./push_swap 1 3 58 9 3
		./push_swap 3 03
		./push_swap " 49 128     50 38   49"
		these examples should work and sort your list
		./push_swap 2147483647 2 4 7
		./push_swap 99 -2147483648 23 545
		./push_swap "2147483647 843 56544 24394"
		./push_swap 54867543867438 3
		./push_swap -2147483647765 4 5
		./push_swap "214748364748385 28 47 29"
		these examples should return "Error\n"
		Nothing has been specified when strings and int are mixed. It's up to you what you want to do
	*/
	char *nums = parser(argc, argv);
	nums = char_checker(nums);
	nums = sign_checker(nums);
	printf("%s\n",nums);
	
}
