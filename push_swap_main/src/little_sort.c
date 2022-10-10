/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marinevicedo <marinevicedo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:34:04 by mvicedo           #+#    #+#             */
/*   Updated: 2022/09/30 15:04:40 by marineviced      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Cas		actions
1 2 3		=> aucune action
1 3 2		-> rra -> 2 1 3 -> sa  -> 1 2 3 => 2 actions
2 1 3		-> sa  -> 1 2 3 => 1 action
2 3 1		-> rra -> 1 2 3 => 1 action
3 1 2		-> ra  -> 1 2 3 => 1 action
3 2 1		-> ra  -> 2 1 3 -> sa  -> 1 2 3 => 2 actions*/


void	algo_for_3(t_stack **a)
{
	int	index_max;

	index_max = get_index_max(*a);
	if ((*a)->index == index_max)// 3 1 2 >> 123
		ra(a);
	else if ((*a)->next->index == index_max)// 3 2 1
		rra(a);
	if ((*a)->index > (*a)->next->index)
		sa(a);
}