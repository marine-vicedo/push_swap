/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:18:19 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/10 16:30:58 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **b, t_stack **a)
{
	t_stack	*temp;

	if (*b != NULL)
	{
		temp = *b;
		*b = (*b)->next;
		temp->next = *a;
		*a = temp;
	}
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*a != NULL)
	{
		temp = *a;
		*a = (*a)->next;
		temp->next = *b;
		*b = temp;
	}
	ft_putstr_fd("pb\n", 1);
}
