/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-most <ael-most@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:38:40 by ael-most          #+#    #+#             */
/*   Updated: 2025/03/09 23:47:19 by ael-most         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_handle_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_is_sorted(*stack_a))
	{
		ft_free_lst(stack_a);
		ft_free_lst(stack_b);
		return;
	}
	if (ft_count_nodes(*stack_a) <= 5)
	{
		ft_simple_sort(stack_a, stack_b);
		//ft_print_lst(*stack_a);
		ft_free_lst(stack_a);
		ft_free_lst(stack_b);
		return;
	}
	else
	{
		ft_sort_algo(stack_a, stack_b);
		ft_sort_five(stack_a, stack_b);
		while (*stack_b)
			ft_execute_moves(stack_a, stack_b);
		ft_final_sorte(stack_a);
	}
}

void	ft_final_sorte(t_stack **stack)
{
	int max_idx;
	int	size;

	max_idx = ft_getmax_index(*stack);
	size = ft_count_nodes(*stack);
	while (!ft_is_sorted(*stack))
	{
		if (max_idx < size / 2)
			ra(stack);
		else
			rra(stack);
	}

}

int	ft_getmax_index(t_stack *stack)
{
	t_stack	*max_node;

	max_node = stack;
	while (stack)
	{
		if (max_node->data < stack->data)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node->index);
}
