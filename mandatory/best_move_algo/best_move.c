/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-most <ael-most@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:48:34 by ael-most          #+#    #+#             */
/*   Updated: 2025/03/09 22:18:37 by ael-most         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_execute_moves(t_stack **stack_a, t_stack **stack_b)
{
	t_move_infos	move;

	ft_update_indexes(*stack_a);
	ft_update_indexes(*stack_b);
	move = ft_best_move(*stack_a, *stack_b);

	ft_sync_rotate(stack_a, stack_b, move);
	ft_align_stack_a(stack_a, move.a_idx);
	ft_align_stack_b(stack_b, move.b_idx);

	pa(stack_b, stack_a);
}

t_move_infos	ft_best_move(t_stack *stack_a, t_stack *stack_b)
{
	t_stack			*current;
	t_move_infos	best_move;
	t_move_infos	temp_move;

	ft_analyze_moves(stack_a, stack_b, stack_b->data, &best_move);

	current = stack_b->next;
	while (current)
	{
		ft_analyze_moves(stack_a, stack_b, current->data, &temp_move);
		if (temp_move.cost < best_move.cost)
			best_move = temp_move;
		current = current->next;
	}
	return (best_move);
}

void	ft_analyze_moves(t_stack *stack_a, t_stack *stack_b, int target, t_move_infos *move)
{
	int	best_match;
	int	size_a;
	int	size_b;

	best_match = ft_find_bestmatch(stack_a, target);

	size_a = ft_count_nodes(stack_a);
	size_b = ft_count_nodes(stack_b);

	move->b_idx = ft_get_element_position(stack_b, target);
	if (move->b_idx <= size_b / 2)
		move->cost_b = move->b_idx;
	else
		move->cost_b = size_b - move->b_idx;


	move->a_idx = ft_get_element_position(stack_a, best_match);
	if (move->a_idx <= size_a / 2)
		move->cost_a = move->a_idx;
	else
		move->cost_a = size_a - move->a_idx;

	move->cost = move->cost_a + move->cost_b;	
}

int	ft_find_bestmatch(t_stack *stack_a, int target)
{
	t_stack	*temp;
	int	closest;

	closest = INT_MAX;
	temp = stack_a;
	while (temp)
	{
		if (temp->data > target && temp->data < closest)
			closest = temp->data;
		temp = temp->next;
	}
	if (closest == INT_MAX)
		return (ft_get_min(stack_a));
	else
		return (closest);
}

void	ft_sync_rotate(t_stack **stack_a, t_stack **stack_b, t_move_infos move)
{
	if (move.a_idx <= ft_count_nodes(*stack_a) / 2 && move.b_idx <= ft_count_nodes(*stack_b) / 2)
	{
		while ((*stack_a)->index != move.a_idx && (*stack_b)->index != move.b_idx)
			rr(stack_a, stack_b);
	}
	else if (move.a_idx > ft_count_nodes(*stack_a) / 2 && move.b_idx > ft_count_nodes(*stack_b) / 2)
	{
		while ((*stack_a)->index != move.a_idx && (*stack_b)->index != move.b_idx)
			rrr(stack_a, stack_b);
	}
}
