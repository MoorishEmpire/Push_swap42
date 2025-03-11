/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-most <ael-most@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:30:57 by ael-most          #+#    #+#             */
/*   Updated: 2025/03/10 02:50:10 by ael-most         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc < 2)
		return (1);
	ft_check_input(argc, argv);
	stack_a = ft_init_lst(argc, argv);
	stack_b = NULL;
	ft_check_lst(stack_a);
	//ft_print_lst(stack_a);
	ft_handle_sort(&stack_a, &stack_b);
	return (0);
}
