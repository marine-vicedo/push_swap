/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:32:41 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/10 16:22:11 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost(t_stack **a, t_stack **b)
{
	t_stack	*temp_b;
	int		stack_size_a;
	int		stack_size_b;

	temp_b = *b;
	stack_size_a = ft_stack_size(*a);
	stack_size_b = ft_stack_size(*b);
	while (temp_b != NULL)
	{
		temp_b->cost_b = temp_b->pos;
		if (temp_b->pos > stack_size_b / 2)
			temp_b->cost_b = (stack_size_b - temp_b->pos) * (-1);
		temp_b->cost_a = temp_b->target_pos;
		if (temp_b->target_pos > stack_size_a / 2)
			temp_b->cost_a = (stack_size_a - temp_b->target_pos) * (-1);
		temp_b = temp_b->next;
	}
}

void	find_the_better_move(t_stack **a, t_stack **b)
{
	t_stack	*temp_b;
	int		better_move;
	int		cost_a;
	int		cost_b;

	temp_b = *b;
	better_move = INT_MAX;
	while (temp_b != NULL)
	{
		if (abs_nbr(temp_b->cost_a) + abs_nbr(temp_b->cost_b)
			< abs_nbr(better_move))
		{
			better_move = abs_nbr(temp_b->cost_a) + abs_nbr(temp_b->cost_b);
			cost_a = temp_b->cost_a;
			cost_b = temp_b->cost_b;
		}
		temp_b = temp_b->next;
	}
	stack_rotations(a, b, cost_a, cost_b);
}
