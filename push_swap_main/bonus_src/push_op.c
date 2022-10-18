/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:18:19 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/06 18:31:20 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
}

/* prend le permier element au sommet de a et le met sur b.
Ne fait rien si a est vide */
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
}
