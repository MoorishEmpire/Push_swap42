/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-most <ael-most@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:04:05 by ael-most          #+#    #+#             */
/*   Updated: 2025/03/09 23:55:13 by ael-most         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_algo(t_stack **stack_a, t_stack **stack_b)
{
	int avg;

	while (*stack_a && ft_count_nodes(*stack_a) > 5)
	{
		avg = ft_average_calcul(*stack_a);
		if ((*stack_a)->data <= avg)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	ft_update_indexes(*stack_a);
	ft_update_indexes(*stack_b);
}

int	ft_average_calcul(t_stack *stack)
{
	int	sum;
	int	lst_size;

	lst_size = ft_count_nodes(stack);
	sum = 0;
	while (stack)
	{
		sum += stack->data;
		stack = stack->next;
	}

	return (sum/lst_size);
}
