/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansir <amansir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:30:56 by amansir           #+#    #+#             */
/*   Updated: 2026/01/21 18:12:35 by amansir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include <stdio.h>

void	error_message()
{
	write(2,"Error\n",6);
	exit(1);
}

char	*parser(int ac, char **av)
{
	char	*nums;

	if (av[1][0] == '\0')
		error_message();
	nums = joiner(ac, av);
	printf("Joined : %s",nums);
	nums = char_checker(nums);
	printf("Char Checked : %s",nums);
	nums = sign_checker(nums);
	printf("Sign Checked : %s",nums);
	return (nums);
}

int main(int argc,char *argv[])
{
	if (argc < 2)
		return (0);
	char *nums = parser(argc, argv);
	printf("%s\n",nums);	
}
