/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-most <ael-most@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:23:44 by ael-most          #+#    #+#             */
/*   Updated: 2025/03/10 11:54:44 by ael-most         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

t_stack	*get_last(t_stack *stack)
{
	t_stack *last;

	last = stack;
	if (stack)
	{
		while (last->next)
			last = last->next;
	}
	return (last);
}

t_stack	*pop_front(t_stack **stack)
{
	t_stack	*first;

	if (!stack || !*stack)
		return (NULL);
	first = *stack;
	if ((*stack)->next)
		*stack = (*stack)->next;
	else
		*stack = NULL;
	first->next = NULL;
	return (first);
}

t_stack	*pop_back(t_stack **stack)
{
	t_stack	*last;

	if (!stack || !*stack)
		return (NULL);
	last = get_last(*stack);

	if (last->prev)
		last->prev->next = NULL;
	else
		*stack = NULL;
	last->prev = NULL;
	return (last);
}
