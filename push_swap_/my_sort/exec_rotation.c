/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:42:35 by throbert          #+#    #+#             */
/*   Updated: 2025/01/27 14:31:55 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	exec_rotations(t_stack **a, t_stack **b, t_cost *min_cost)
{
	while (min_cost->moves_to_top_b > 0 && min_cost->moves_to_top_a > 0
		&& min_cost->direction_rb == min_cost->direction_ra)
	{
		if (min_cost->direction_rb == 1) // si c est init cost le best
			rr(a, b);
		else
			rrr(a, b);
		min_cost->moves_to_top_b--;
		min_cost->moves_to_top_a--;
	}
	while (min_cost->moves_to_top_b-- > 0)
	{
		if (min_cost->direction_rb == 1) // wtf ?
			rb(b);
		else
			rrb(b);
	}
	while (min_cost->moves_to_top_a-- > 0)
	{
		if (min_cost->direction_ra == 1)
			ra(a);
		else
			rra(a);
	}
}

void	final_adjustment(t_stack **a)
{
	int	min_pos;
	int	size;

	min_pos = position_of_min(*a);
	size = stack_size(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(a);
	}
	else
	{
		min_pos = size - min_pos;
		while (min_pos-- > 0)
			rra(a);
	}
}

void	sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
