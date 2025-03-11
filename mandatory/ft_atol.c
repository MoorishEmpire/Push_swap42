/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-most <ael-most@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:14:17 by ael-most          #+#    #+#             */
/*   Updated: 2025/02/27 15:19:29 by ael-most         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	long	nbr;
	int		signe;
	int		i;

	signe = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (nbr > (LONG_MAX - (str[i] - '0')) / 10)
		{
			if (signe == 1)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (signe * nbr);
}
