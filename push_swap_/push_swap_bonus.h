/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 07:42:33 by throbert          #+#    #+#             */
/*   Updated: 2025/01/29 15:49:00 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "../gnl_bonus/get_next_line_bonus.h"
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
	int	best_;
	int	moves_a;
	int	moves_b;
	int	direction_a;
	int	direction_b;
}	t_cost;

typedef struct s_calc
{
	int		value;
	int		dir;
	t_stack	*src;
	t_stack	*dst;
	int		pos_s;
	int		pos_d;
	int		sz_s;
	int		sz_d;
}	t_calc;

typedef struct s_scenario
{
	int	moves_a;
	int	moves_b;
	int	direction_a;
	int	direction_b;
}	t_scenario;

void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);

int		handle_rotate_cmd(char *cmd, t_stack **a, t_stack **b);
int		handle_swap_push(char *cmd, t_stack **a, t_stack **b);

int		is_valid_command(char *cmd);
void	exec_command(char *cmd, t_stack **a, t_stack **b);

/* Error handling */
void	exit_with_error(t_stack **a, t_stack **b);
void	clear_stack(t_stack **stack);

/* bonus */
int		initialize_stacks(int *numbers, int count,
			t_stack **a, t_stack **b);
void	clear_stack(t_stack **stack);
int		is_sorted(t_stack *stack);

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
void	calculate_cost(t_calc *current_elem, t_cost *c);
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
