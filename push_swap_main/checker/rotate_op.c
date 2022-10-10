/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:12:16 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/06 18:31:02 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rotate(t_stack **head)
{
	t_stack	*first;
	t_stack	*last;

	first = *head;//fixe
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
}

void	rb(t_stack **b)
{
	rotate(b);	
}

void	rotate_both(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	
}