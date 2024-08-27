/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:39:06 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/10 16:26:40 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index_max(t_stack *stack)
{
	int	index_max;

	index_max = stack->index;
	while (stack != NULL)
	{
		if (stack->index > index_max)
			index_max = stack->index;
		stack = stack->next;
	}
	return (index_max);
}

void	get_index(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = a;
	tmp2 = a;
	while (tmp != NULL)
	{
		while (a != NULL)
		{
			if (a->value > tmp->value)
				a->index = a->index + 1;
			a = a->next;
		}
		tmp = tmp->next;
		a = tmp2;
	}
}
