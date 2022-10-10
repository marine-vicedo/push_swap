/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:33:43 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/04 10:33:44 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rev_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while(*cost_a < 0 && *cost_b < 0)
	{
		reverse_rotate_both(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}	
}

static void	do_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while(*cost_a > 0 && *cost_b > 0)
	{
		rotate_both(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}	
}

static void	do_rotations_for_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if(*cost > 0)
		{
			rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(b);
			(*cost)++;
		}
	}
}

static void	do_rotations_for_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if(*cost > 0)
		{
			ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra(a);
			(*cost)++;
		}
	}
}

void	stack_rotations(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
		do_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(a, b, &cost_a, &cost_b);
	do_rotations_for_a(a, &cost_a);
	do_rotations_for_b(b, &cost_b);
	pa(b, a);
}