/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_ 3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:34:04 by mvicedo           #+#    #+#             */
/*   Updated: 2022/09/22 18:30:36 by mvicedo          ###   ########.fr       */
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
	//printf("%d\n", (*a)->index);
	if ((*a)->index == 3)// 3 1 2 >> 123
	{
		rotate(a);
		printf("ra\n");
	}
	else if ((*a)->next->index == 3)// 3 2 1
	{
		reverse_rotate(a);
		printf("rra\n");
	}
	if ((*a)->index > (*a)->next->index)
	{
		swap_nodes(a);
		printf("sa\n");
	}
	

}