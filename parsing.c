/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansir <amansir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:30:56 by amansir           #+#    #+#             */
/*   Updated: 2026/02/24 17:09:50 by amansir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	error_message()
{
	write(2,"Error\n",6);
	exit(1);
}
int is_empty(char *str)
{
	if(!str || !str[0])
		error_message();
	while (*str)
	{
		if(*str != ' ')
			return 0;
		str++;
	}
	return 1;
}
char	*parser(int ac, char **av)
{
	char	*nums;
	int 	i;

	i = 0;
	if (av[1][0] == '\0')
		error_message();
	while(i < ac)
	{
		if(is_empty(av[i]))
			error_message();
		i++;
	}
	nums = joiner(ac, av);
	nums = char_checker(nums);
	nums = sign_checker(nums);
	return (nums);
}

int main(int argc, char *argv[])
{
	char	*nums;
	int	*values;
	int	count;

	if (argc < 2)
		return (0);
	nums = parser(argc, argv);
	values = parse_numbers(nums, &count);
	printf("nums: %s\n", nums);
	while(count > 0)
	{
		printf("values: %d\n", values[count - 1]);
		count--;
	}
	free(values);
	free(nums);
	return (0);
}
