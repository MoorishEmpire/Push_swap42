/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_checker_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-most <ael-most@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:54:38 by ael-most          #+#    #+#             */
/*   Updated: 2025/03/10 15:34:02 by ael-most         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_handle_checker(t_stack **stack_a, t_stack **stack_b)
{
	char *operation;

	if (ft_is_sorted(*stack_a))
	{
		ft_putstr_fd("OK\n", 1);
		return;
	}
	operation = get_next_line(0);
	while (operation)
	{
		ft_apply_moves(stack_a, stack_b,  operation);
		operation = get_next_line(0);
	}
	if (!ft_count_nodes(*stack_b) && ft_is_sorted(*stack_a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_free_lst(stack_a);
	ft_free_lst(stack_b);
}

void	ft_apply_moves(t_stack **stack_a, t_stack **stack_b, char *operation)
{
	int	size;

	size = ft_strlen(operation);

	if (!ft_strncmp("sa\n", operation, size))
		sa(stack_a);
	else if (!ft_strncmp("sb\n", operation, size))
		sb(stack_a);
	else if (!ft_strncmp("ss\n", operation, size))
		ss(stack_a, stack_b);
	else if (!ft_strncmp("ra\n", operation, size))
		ra(stack_a);
	else if (!ft_strncmp("rra\n", operation, size))
		rra(stack_a);
	else if (!ft_strncmp("rb\n", operation, size))
		rb(stack_b);
	else if (!ft_strncmp("rrb\n", operation, size))
		rrb(stack_b);
	else if (!ft_strncmp("rr\n", operation, size))
		rr(stack_a, stack_b);
	else if (!ft_strncmp("rrr\n", operation, size))
		rrr(stack_a, stack_b);
	else if (!ft_strncmp("pa\n", operation, size))
		pa(stack_b, stack_a);
	else if (!ft_strncmp("pb\n", operation, size))
		pb(stack_a, stack_b);
	else
		ft_print_error("ERROR");
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
