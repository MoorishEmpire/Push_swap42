/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-most <ael-most@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:58:57 by ael-most          #+#    #+#             */
/*   Updated: 2025/03/06 21:44:45 by ael-most         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	ft_move_min_totop(stack_a);
	pb(stack_a, stack_b);
	ft_sort_four(stack_a, stack_b);
	pa(stack_b, stack_a);
}

void	ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	ft_move_min_totop(stack_a);
	pb(stack_a, stack_b);
	ft_sort_three(stack_a);
	pa(stack_b, stack_a);
}

void	ft_sort_three(t_stack **stack_a)
{
	t_stack	*max_node;

	max_node = ft_find_max(*stack_a);
	if (max_node == *stack_a)
		ra(stack_a);
	else if (max_node == (*stack_a)->next)
		rra(stack_a);
	if ((*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a);
}

void	ft_move_min_totop(t_stack **stack)
{
	int	min_pos;
	int	lst_size;

	min_pos = ft_find_min_position(*stack);
	lst_size = ft_count_nodes(*stack);
	if (min_pos <= lst_size/2)
		while (min_pos--)
			ra(stack);
	else
		while (min_pos++ < lst_size)
			rra(stack);
}

int	ft_find_min_position(t_stack *stack)
{
	int	min_pos;
	int	min_val;
	int	current_pos;

	min_pos = 0;
	current_pos = 0;
	min_val = stack->data;
	while (stack)
	{
		if (stack->data < min_val)
		{
			min_pos = current_pos;
			min_val = stack->data;
		}
		current_pos++;
		stack = stack->next;
	}
	return (min_pos);
}
