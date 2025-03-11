/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-most <ael-most@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:42:38 by ael-most          #+#    #+#             */
/*   Updated: 2025/03/09 22:21:18 by ael-most         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_align_stack_a(t_stack **stack_a, int index)
{
	int size;

	size = ft_count_nodes(*stack_a);
	while ((*stack_a)->index != index)
	{
		if (index <= size / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	ft_align_stack_b(t_stack **stack_b, int index)
{
	int size;

	size = ft_count_nodes(*stack_b);
	while ((*stack_b)->index != index)
	{
		if (index <= size / 2)
			rb(stack_b);
		else
			rrb(stack_b);
	}
}

int	ft_get_element_position(t_stack *stack, int target)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		if (current->data == target)
			return (current->index);
		current = current->next;
	}
	return (-1);
}

int	ft_get_min(t_stack *stack_a)
{
	int		min;

	min = stack_a->data;
	while (stack_a)
	{
		if (stack_a->data < min)
			min = stack_a->data;
		stack_a = stack_a->next;
	}
	return (min);
}

void	ft_update_indexes(t_stack *stack)
{
	int idx;

	idx = 0;
	while (stack)
	{
		stack->index = idx;
		idx++;
		stack = stack->next;
	}
}
