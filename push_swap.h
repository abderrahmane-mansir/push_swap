/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansir <amansir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 10:39:29 by amansir           #+#    #+#             */
/*   Updated: 2026/02/24 16:51:45 by amansir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
#include <limits.h>
# include <stdio.h>

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*parser(int ac, char **av);
char	*joiner(int ac, char **av);
char	*char_checker(char *nums);
char	*sign_checker(char *nums);
char	*twin_checker(char *nums);
int	    *parse_numbers(char *nums, int *out_count);
int		is_digit(int c);
int		is_space(int c);
int		is_sign(int c);
int		is_twins(char *nums, int c, int p);
void	error_message();
// char	*twin_checker(char *num);

#endif
