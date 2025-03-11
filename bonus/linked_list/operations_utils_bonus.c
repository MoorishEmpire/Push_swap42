/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-most <ael-most@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:55:25 by ael-most          #+#    #+#             */
/*   Updated: 2025/03/10 11:55:11 by ael-most         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*top;

	if (!src || !*src || !dest)
		return;
	top = pop_front(src);
	if (*dest)
	{
		top->next = *dest;
		(*dest)->prev = top;
	}
	*dest = top;
}

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return;
	first = *stack;	
	second = (*stack)->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
}

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return;

	first = *stack;
	last = get_last(*stack);

	*stack = first->next;
	(*stack)->prev = NULL;

	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*befor_last;

	if (!stack || !*stack || !(*stack)->next)
		return;

	last = get_last(*stack);
	befor_last = last->prev;
	befor_last->next = NULL;

	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}
