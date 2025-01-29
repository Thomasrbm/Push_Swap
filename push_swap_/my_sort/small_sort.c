/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:35:13 by throbert          #+#    #+#             */
/*   Updated: 2025/01/28 18:01:26 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min(t_stack *a)
{
	int	min;

	if (!a)
		return (0);
	min = a->value;
	while (a)
	{
		if (a->value < min)
			min = a->value;
		a = a->next;
	}
	return (min);
}

void	sort_two(t_stack **a)
{
	if (*a && (*a)->next && (*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	if (!a || !(*a) || !(*a)->next || !(*a)->next->next)
		return ;
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	push_min_to_b(t_stack **a, t_stack **b)
{
	int	min;
	int	pos;

	min = find_min(*a);
	pos = position_of_min(*a);
	if (pos == 1)
		sa(a);
	else if (pos <= stack_size(*a) / 2)
	{
		while ((*a)->value != min)
			ra(a);
	}
	else
	{
		while ((*a)->value != min)
			rra(a);
	}
	pb(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	size;
	int	to_push;

	size = stack_size(*a);
	if (size == 5)
		to_push = 2;
	else
		to_push = 1;
	while (to_push--)
		push_min_to_b(a, b);
	sort_three(a);
	while (*b)
		pa(a, b);
	if (*a && (*a)->next && (*a)->value > (*a)->next->value)
		sa(a);
}
