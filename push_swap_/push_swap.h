/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 04:51:53 by throbert          #+#    #+#             */
/*   Updated: 2025/01/29 20:38:11 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_cost
{
	int	best;
	int	moves_to_top_b;
	int	moves_to_top_a;
	int	direction_rb;
	int	direction_ra;
}	t_cost;

typedef struct s_calc
{
	int		value;
	int		dir;
	int		pos_b;
	int		pos_a;
	int		sz_b;
	int		sz_a;
}	t_calc;

typedef struct s_scenario
{
	int	tmp_moves_to_top_b;
	int	tmp_moves_to_top_a;
	int	tmp_direction_rb;
	int	tmp_direction_ra;
}	t_scenario;

int		is_sorted(t_stack *stack);

void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);

/* Error handling */
void	exit_with_error(t_stack **a, t_stack **b);
void	clear_stack(t_stack **stack);

/* Stack operations */
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rra(t_stack **a);
void	rb(t_stack **b);
void	rrb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
int		push(t_stack **stack, int value);
int		pop(t_stack **stack);
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);

/* Cost calculation */
void	init_best(t_cost *cost, int pos_a, int pos_b);
int		eval_scenario(t_cost *best, t_scenario scenario);
void	calculate_cost(t_stack *a, t_stack *b, t_calc *current_elem, t_cost *best);
void	move_cheapest(t_stack **a, t_stack **b);

/* Rotations */
void	exec_rotations(t_stack **a, t_stack **b, t_cost *cost);

/* Sorting utilities */
int		stack_size(t_stack *stack);
int		get_max_value(int a, int b);
int		position_of_min(t_stack *stack);
int		find_position(t_stack *a, int value);
int		get_position(t_stack *stack, int value);
void	final_adjustment(t_stack **a);
void	sort_int_tab(int *tab, int size);
int		get_dynamic_pivot(t_stack *a, int current_chunk, int chunks);
void	push_inferior_or_equal_chunk(t_stack **a, t_stack **b, int pivot);
void	chunk_sort(t_stack **a, t_stack **b, int chunks);
void	my_sort(t_stack **a, t_stack **b);

/* Argument parsing */
int		*parse_arguments(int argc, char **argv, int *count);
int		check_duplicates(int *numbers, int count);
int		*dup_tab(t_stack *a, int size);

#endif
