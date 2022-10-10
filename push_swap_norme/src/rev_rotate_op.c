/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:17:07 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/10 16:03:05 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **head)
{
	t_stack	*first;
	t_stack	*last;

	first = *head;
	last = *head;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	while (last->next->next != NULL)
	{
		last = last->next;
	}
	last->next->next = first;
	*head = last->next;
	last->next = NULL;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	reverse_rotate_both(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}
