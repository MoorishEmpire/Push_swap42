/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-most <ael-most@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:26:13 by ael-most          #+#    #+#             */
/*   Updated: 2025/03/10 15:04:39 by ael-most         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

// Stack data struture
typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// Data structure for tracking movement costs
typedef struct s_move_infos
{
	int	cost_a;
	int	cost_b;
	int	a_idx;
	int	b_idx;
	int	a_size;
	int	b_size;
	int	cost;
} t_move_infos;

//check_input.c
void	ft_check_input(int argc, char **argv);
int		ft_check_duplicates(char **args);

//init_list.c
t_stack	*ft_init_lst(int argc, char **argv);
t_stack	*ft_make_new(int new_data);
void	ft_store_instack(t_stack **stack, t_stack *new);
void	ft_print_lst(t_stack *head);
int		ft_isnbr(char *arg);
int		ft_count_nodes(t_stack *stack);

//check_list.c
void	ft_check_lst(t_stack *stack);
void	ft_free_lst(t_stack **stack);

//linked_list_utils.c
t_stack	*get_last(t_stack *stack);
t_stack	*pop_back(t_stack **stack);
t_stack	*pop_front(t_stack **stack);

//operations_utils.c
void	push(t_stack **src, t_stack **dest);
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);

//operation.c
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
//
//hande_checker.c
void	ft_handle_checker(t_stack **stack_a, t_stack **stack_b);
void	ft_apply_moves(t_stack **stack_a, t_stack **stack_b, char *operation);
int		ft_is_sorted(t_stack *stack);

//print_error.c
void	ft_print_error(char *str);

//ft_atol.c
long	ft_atol(char *str);

#endif
