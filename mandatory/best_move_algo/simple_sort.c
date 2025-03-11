/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-most <ael-most@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:49:20 by ael-most          #+#    #+#             */
/*   Updated: 2025/03/06 21:50:55 by ael-most         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	lst_size;

	if (!stack_a || !stack_b)
		return; 

	if (ft_is_sorted(*stack_a))
		return;

	lst_size = ft_count_nodes(*stack_a);
	if (lst_size == 5)
		ft_sort_five(stack_a, stack_b);
	else if (lst_size == 4)
		ft_sort_four(stack_a, stack_b);
	else if (lst_size == 3)
		ft_sort_three(stack_a);
	else
		sa(stack_a);
}

int	ft_is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack	*ft_find_max(t_stack *stack)
{
	t_stack	*current;
	t_stack	*max;

	current = stack;
	max = stack;
	while (current)
	{
		if (current->data > max->data)
			max = current;
		current = current->next;
	}
	return (max);
}
