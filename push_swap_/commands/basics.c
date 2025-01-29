/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:47:10 by throbert          #+#    #+#             */
/*   Updated: 2025/01/27 18:53:48 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*create_node(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		exit_with_error(NULL, NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

int	push(t_stack **stack, int value)
{
	t_stack	*new_node;

	new_node = create_node(value);
	if (!new_node)
		return (0);
	new_node->next = *stack;
	*stack = new_node;
	return (1);
}

int	pop(t_stack **stack)
{
	t_stack	*temp;
	int		value;

	if (*stack == NULL)
		return (-1);
	temp = *stack;
	value = temp->value;
	*stack = temp->next;
	free(temp);
	return (value);
}

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}
