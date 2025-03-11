/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-most <ael-most@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:51:20 by ael-most          #+#    #+#             */
/*   Updated: 2025/03/10 00:27:39 by ael-most         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

t_stack	*ft_init_lst(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*new;
	char	**split;
	int		i;
	int		j;
	int		nbr;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		j = 0;
		while (split[j])
		{
			nbr = ft_atol(split[j]);
			new = ft_make_new(nbr);
			ft_store_instack(&stack_a, new);
			j++;
		}
		ft_free(split, j);
		i++;
	}
	return (stack_a);
}

t_stack	*ft_make_new(int new_data)
{
	t_stack	*new_node;

	new_node = ft_calloc(1, sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = new_data;
	new_node->index = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	ft_store_instack(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return;
	if (!*stack)
	{
		*stack = new;
		return;
	}
	last = get_last(*stack);

	last->next = new;
	new->prev = last;
	/*
	if (*stack)
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new;
	*/
}

void	ft_print_lst(t_stack *stack)
{
	int i;
	int size;

	size = ft_count_nodes(stack);
	i = 0;
	while (i < size)
	{
		printf ("(node %d: data->%d)", i, stack->data);
		if (stack->next)
			printf("->");
		stack = stack->next;
		i++;
	}
	printf("\n");
}

int	ft_count_nodes(t_stack *stack)
{
	int count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
		

