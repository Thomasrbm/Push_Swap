/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 02:29:19 by throbert          #+#    #+#             */
/*   Updated: 2025/01/29 01:13:15 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	handle_swap_push(char *cmd, t_stack **a, t_stack **b)
{
	int	value;

	if (!ft_strcmp(cmd, "sb"))
		swap(b);
	else if (!ft_strcmp(cmd, "ss"))
	{
		swap(a);
		swap(b);
	}
	else if (!ft_strcmp(cmd, "pa"))
	{
		value = pop(b);
		if (value != -1)
			push(a, value);
	}
	else if (!ft_strcmp(cmd, "pb"))
	{
		value = pop(a);
		if (value != -1)
			push(b, value);
	}
	else
		return (0);
	return (1);
}

int	handle_rotate_cmd(char *cmd, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(cmd, "sa"))
		swap(a);
	else if (!ft_strcmp(cmd, "ra"))
		rotate(a);
	else if (!ft_strcmp(cmd, "rb"))
		rotate(b);
	else if (!ft_strcmp(cmd, "rr"))
	{
		rotate(a);
		rotate(b);
	}
	else if (!ft_strcmp(cmd, "rra"))
		reverse_rotate(a);
	else if (!ft_strcmp(cmd, "rrb"))
		reverse_rotate(b);
	else if (!ft_strcmp(cmd, "rrr"))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else
		return (0);
	return (1);
}

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	initialize_stacks(int *numbers, int count, t_stack **a, t_stack **b)
{
	int	i;

	*a = NULL;
	*b = NULL;
	i = count - 1;
	while (i >= 0)
	{
		if (!push(a, numbers[i]))
		{
			clear_stack(a);
			free(numbers);
			return (0);
		}
		i--;
	}
	free(numbers);
	return (1);
}

void	clear_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
