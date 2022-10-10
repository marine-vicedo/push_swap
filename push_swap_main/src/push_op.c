/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marinevicedo <marinevicedo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:18:19 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/03 11:24:44 by marineviced      ###   ########.fr       */
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
	ft_putstr_fd("pb\n", 1);
}
