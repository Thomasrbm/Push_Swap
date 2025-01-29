/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 04:51:53 by throbert          #+#    #+#             */
/*   Updated: 2025/01/29 20:30:44 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	get_max_value(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	position_of_min(t_stack *stack)
{
	int	min;
	int	position;
	int	min_pos;

	min = INT_MAX;
	position = 0;
	min_pos = 0;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_pos = position;
		}
		position++;
		stack = stack->next;
	}
	return (min_pos);
}

int	find_position(t_stack *a, int value) /// COMMMENT CA MARCHE ????????
{
	int		position;
	int		best_pos;
	int		min_diff;
	int		diff;
	t_stack	*tmp_stack;

	tmp_stack = a;
	position = 0; // index de la pile a
	best_pos = 0;
	min_diff = INT_MAX;
	while (tmp_stack)
	{
		diff = tmp_stack->value - value;
		if (diff > 0 && diff < min_diff) // diff > 0 == assure insertion avant nombre plus grand    +   plus petit ecart
		{
			min_diff = diff;
			best_pos = position;
		}
		position++;
		tmp_stack = tmp_stack->next;
	}
	if (min_diff == INT_MAX)
		best_pos = position_of_min(a);
	return (best_pos);
}

int	get_position(t_stack *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->value == value)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}
