/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:12:16 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/10 16:11:28 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **head)
{
	t_stack	*first;
	t_stack	*last;

	first = *head;
	last = *head;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = first;
	*head = first->next;
	first->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rotate_both(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}
