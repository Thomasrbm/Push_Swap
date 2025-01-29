/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:15:18 by throbert          #+#    #+#             */
/*   Updated: 2025/01/26 02:25:13 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	eval_scenario(t_cost *best, t_scenario cur_scenar)
{
	int	new_potential_best;
	int	cur_best_scenar;

	cur_best_scenar = get_max_value(best->moves_to_top_b, best->moves_to_top_a); // mieux que moyenne
	new_potential_best = get_max_value(cur_scenar.tmp_moves_to_top_b,			// 8 et 2 = 5   et 5 5 = 5  mais avec rota simul mieux le double 5
			cur_scenar.tmp_moves_to_top_a);
	if (new_potential_best < cur_best_scenar)
	{
		best->moves_to_top_b = cur_scenar.tmp_moves_to_top_b;
		best->moves_to_top_a = cur_scenar.tmp_moves_to_top_a;
		best->direction_rb = cur_scenar.tmp_direction_rb;
		best->direction_ra = cur_scenar.tmp_direction_ra;
	}
	if (new_potential_best < cur_best_scenar)
		return (new_potential_best);
	return (cur_best_scenar);
}

void	init_best_rr(t_cost *best, int pos_a, int pos_b)
{
	best->moves_to_top_b = pos_a;
	best->moves_to_top_a= pos_b;
	best->direction_rb = 1; // test  rr
	best->direction_ra = 1;
}

void	calculate_cost(t_stack *a, t_stack *b, t_calc *current_elem, t_cost *best)
{
	t_scenario	cur_scenar;

	current_elem->pos_b = get_position(b, current_elem->value); // pos top = 0  car move to top b === 0
	current_elem->pos_a = find_position(a, current_elem->value);  // move to top a
	current_elem->sz_b = stack_size(b);
	current_elem->sz_a = stack_size(a);
	init_best_rr(best, current_elem->pos_b, current_elem->pos_a); // met curr elem pos  sinon = valeur indeterminem fausse calcul	
															// fait que si en pos 0 alors eval scenario aura aucun effet car best move to top sera a 0 et donc aucun scenar sera en dessous
	cur_scenar.tmp_moves_to_top_b = current_elem->sz_b - current_elem->pos_b;
	cur_scenar.tmp_moves_to_top_a = current_elem->sz_a - current_elem->pos_a;
	cur_scenar.tmp_direction_rb = -1;
	cur_scenar.tmp_direction_ra = -1;
	eval_scenario(best, cur_scenar);
	cur_scenar.tmp_moves_to_top_b = current_elem->pos_b;
	cur_scenar.tmp_moves_to_top_a = current_elem->sz_a - current_elem->pos_a;
	cur_scenar.tmp_direction_rb = 1;
	cur_scenar.tmp_direction_ra = -1;
	eval_scenario(best, cur_scenar);
	cur_scenar.tmp_moves_to_top_b = current_elem->sz_b - current_elem->pos_b;
	cur_scenar.tmp_moves_to_top_a = current_elem->pos_a;
	cur_scenar.tmp_direction_rb = -1;
	cur_scenar.tmp_direction_ra = 1;
	eval_scenario(best, cur_scenar);
	best->best = get_max_value(best->moves_to_top_b, best->moves_to_top_a);
}

t_cost	find_min_cost_scenar(t_stack *a, t_stack *b)
{
	t_cost	min_cost;
	t_cost	best;
	t_calc	current_elem;
	t_stack	*tmp_stack; // pour pas perdre acces au haut de b / sinon on stock haut de b et remet b a la gin	

	min_cost.best = INT_MAX; // pour la premiere compa
	tmp_stack = b;
	best.best = 0; 
	while (tmp_stack)
	{
		current_elem.value = tmp_stack->value;
		calculate_cost(a, b, &current_elem, &best);
		if (best.best < min_cost.best)
			min_cost = best;
		tmp_stack = tmp_stack->next;
	}
	return (min_cost);
}

void	move_cheapest(t_stack **a, t_stack **b)
{
	t_cost		min_cost;

	min_cost = find_min_cost_scenar(*a, *b);
	exec_rotations(a, b, &min_cost);
	pa(a, b);
}
