/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:17:07 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/06 18:31:13 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
}

void	reverse_rotate_both(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	
}
