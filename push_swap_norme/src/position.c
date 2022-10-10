/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:33:19 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/10 16:25:17 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_position(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (temp != NULL)
	{
		temp->pos = i;
		temp = temp->next;
		i++;
	}
}

int	define_target_stack_a(t_stack **a, int index_b, int index_target,
							int target_pos_b)
{
	t_stack	*temp_a;

	temp_a = *a;
	while (temp_a != NULL)
	{
		if (temp_a->index > index_b && temp_a->index < index_target)
		{
			index_target = temp_a->index;
			target_pos_b = temp_a->pos;
		}
		temp_a = temp_a->next;
	}
	if (index_target != INT_MAX)
		return (target_pos_b);
	temp_a = *a;
	while (temp_a != NULL)
	{
		if (temp_a->index < index_target)
		{
			index_target = temp_a->index;
			target_pos_b = temp_a->pos;
		}
		temp_a = temp_a->next;
	}
	return (target_pos_b);
}

void	target_position_for_b(t_stack **a, t_stack **b)
{
	t_stack	*temp_b;
	int		target_pos_b;
	int		index_target;

	temp_b = *b;
	target_pos_b = 0;
	index_target = INT_MAX;
	get_position(a);
	get_position(b);
	while (temp_b != NULL)
	{
		target_pos_b = define_target_stack_a(a, temp_b->index, index_target,
				target_pos_b);
		temp_b->target_pos = target_pos_b;
		temp_b = temp_b->next;
	}
}
