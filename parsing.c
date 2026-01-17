/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansir <amansir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:30:56 by amansir           #+#    #+#             */
/*   Updated: 2026/01/17 11:56:16 by amansir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include <stdio.h>

void	error_message()
{
	write(1,"Error",5);
}

char	*parser(int ac, char **av)
{
	char	*nums;

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
	argc =  argc;
	char *nums = parser(argc, argv);
	printf("%s\n",nums);	
}
