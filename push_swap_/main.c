/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 07:52:54 by throbert          #+#    #+#             */
/*   Updated: 2025/01/29 20:23:27 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int	index;

	*a = NULL;  // sinon risque de creer des conditionnal jump apres  : car contiennent garbage value meme dans stack  = comportement indeterminée
	*b = NULL;
	index = count - 1;
	while (index >= 0)
	{
		if (!push(a, numbers[index]))
		{
			clear_stack(a);
			free(numbers);
			return (0);
		}
		index--;
	}
	free(numbers);
	return (1);
}

int	initialize_program(int argc, char **argv, t_stack **a, t_stack **b)
{
	int	*numbers;
	int	count;

	numbers = parse_arguments(argc, argv, &count);
	if (!numbers)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!initialize_stacks(numbers, count, a, b))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (is_sorted(*a))
	{
		clear_stack(a);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (!initialize_program(argc, argv, &a, &b))
		return (1);
	my_sort(&a, &b);
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}

// FOR FUTURE UPGRADE ===> you wanna beat world record
// try to stop the while in chunk sort  (for push chunk) if stack 
//a is already sorted with the top max value in order 
// if you do it well you could be lucky to find the right seed
// and do maybe 2000 moves

// didn't do it, affraid of breaking code after a lot of work.

//  + maybe try find a way to use the switch command