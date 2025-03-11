/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-most <ael-most@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:38:52 by ael-most          #+#    #+#             */
/*   Updated: 2025/03/10 11:50:20 by ael-most         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_check_input(int argc, char **argv)
{
	char	**split;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			ft_print_error("ERROR");
		if (ft_check_duplicates(split))
			ft_print_error("ERROR");
		j = 0;
		while (split[j])
		{
			if (!ft_isnbr(split[j]))
				ft_print_error("ERROR");
			if (ft_atol(split[j]) > INT_MAX || ft_atol(split[j]) < INT_MIN)
				ft_print_error("ERROR");
				j++;
		}
		ft_free(split, j);
		i++;
	}
}

int	ft_check_duplicates(char **args)
{
	int i;
	int j;

	i = 0;
	while (args[i + 1])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atol(args[i]) == ft_atol(args[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_isnbr(char *argv)
{
	int i;

	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
