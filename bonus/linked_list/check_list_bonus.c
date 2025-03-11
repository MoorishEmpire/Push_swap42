/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-most <ael-most@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:25:08 by ael-most          #+#    #+#             */
/*   Updated: 2025/03/10 11:53:45 by ael-most         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	ft_check_lst(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next;

	current = stack;
	while (current->next)
	{
		next = current->next;
		while (next)
		{
			if (current->data == next->data)
			{
				ft_free_lst(&stack);
				ft_print_error("ERROR");
			}
			next = next->next;
		}
		current = current->next;
	}
}

void	ft_free_lst(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
