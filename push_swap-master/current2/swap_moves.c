/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:18:01 by mvicedo           #+#    #+#             */
/*   Updated: 2022/09/22 18:01:55 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* intervertit les 2 premiers elements au sommet de la pile a */
void	swap_nodes(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (temp != NULL && temp->next != NULL)
	{
		swap(&temp->value, &temp->next->value);
		swap(&temp->index, &temp->next->index);
	}

}

void	swap_ss(t_stack **a, t_stack **b)
{
	swap_nodes(a);
	swap_nodes(b);
}
