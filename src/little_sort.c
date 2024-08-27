/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:34:04 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/10 16:22:55 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_for_3(t_stack **a)
{
	int	index_max;

	index_max = get_index_max(*a);
	if ((*a)->index == index_max)
		ra(a);
	else if ((*a)->next->index == index_max)
		rra(a);
	if ((*a)->index > (*a)->next->index)
		sa(a);
}
