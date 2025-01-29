/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:00:48 by throbert          #+#    #+#             */
/*   Updated: 2025/01/29 01:12:23 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}

void	pa(t_stack **a, t_stack **b)
{
	int	value;

	value = pop(b);
	if (value != -1)
	{
		push(a, value);
		ft_printf("pa\n");
	}
}

void	pb(t_stack **a, t_stack **b)
{
	int	value;

	value = pop(a);
	if (value != -1)
	{
		push(b, value);
		ft_printf("pb\n");
	}
}
