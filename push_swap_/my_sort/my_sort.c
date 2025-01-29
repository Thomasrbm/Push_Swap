/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:35:13 by throbert          #+#    #+#             */
/*   Updated: 2025/01/29 20:31:35 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_chunks(t_stack **a, t_stack **b, int *pivots)
{
	int	size;

	size = stack_size(*a);
	while (size--)
	{
		if ((*a)->value <= pivots[0])
			pb(a, b);
		else if ((*a)->value <= pivots[1])
		{
			pb(a, b);
			rb(b);// pour garder le gros nombre a quelque rota au lieu de la laisser au middle en random ca les pack
		}// inchorent sur petit echantillon mais sur gros si.
		else
			ra(a);
	}
}

int	*dup_tab(t_stack *a, int size)
{
	int	*dupped_tab;
	int	i;

	i = 0;
	dupped_tab = malloc(sizeof(int) * size);
	if (!dupped_tab)
	{
		free(dupped_tab);
		return (0);
	}
	while (a && i < size)
	{
		dupped_tab[i] = a->value;
		a = a->next;
		i++;
	}
	return (dupped_tab);
}

int	get_dynamic_pivot(t_stack *a, int current_chunk, int chunks)
{
	int	size;
	int	*sorted;
	int	pivot;
	int	index;

	size = stack_size(a);
	if (size == 0)
		return (0);
	sorted = dup_tab(a, size);
	if (!sorted)
		return (0);
	sort_int_tab(sorted, size);
	index = (size * current_chunk) / chunks - 1;
	if (index < 0)
		index = 0;
	pivot = sorted[index];
	free(sorted);
	return (pivot);
}

void	chunk_sort(t_stack **a, t_stack **b, int chunks)
{
	int	current_chunk;
	int	pivots[2]; // moins de ra a faire, avec le rb s equilibre mais au total c est benef

	current_chunk = 1;
	while (current_chunk <= chunks)
	{
		pivots[0] = get_dynamic_pivot(*a, current_chunk, chunks);
		if (current_chunk < chunks)
			pivots[1] = get_dynamic_pivot(*a, current_chunk + 1, chunks);
		else
			pivots[1] = INT_MAX;
		push_chunks(a, b, pivots);
		current_chunk++;
	}
	while (*b != NULL)
		move_cheapest(a, b);
	final_adjustment(a);
}

void	my_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	chunks;

	size = stack_size(*a);
	if (size <= 1)
		return ;
	if (size <= 5)
	{
		if (size == 2)
			sort_two(a);
		else if (size == 3)
			sort_three(a);
		else
			sort_five(a, b);
		return ;
	}
	if (size > 100)
		chunks = 5;
	else
		chunks = 3;
	chunk_sort(a, b, chunks);
}

// But = envoyer les plus petit d abord dans b et les gros a la fin pour limiter les rotat a faire

// 2 pivot = un peu plus de rota de b vers a mais bcp moins de a vers b