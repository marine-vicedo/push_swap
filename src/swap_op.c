/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:18:01 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/11 15:20:38 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	swap_nodes(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (temp != NULL && temp->next != NULL)
	{
		swap(&temp->value, &temp->next->value);
		swap(&temp->index, &temp->next->index);
	}
}

void	sa(t_stack **a)
{
	swap_nodes(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b)
{
	swap_nodes(b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	swap_nodes(a);
	swap_nodes(b);
	ft_putstr_fd("ss\n", 1);
}
