/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marinevicedo <marinevicedo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:12:16 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/03 11:23:59 by marineviced      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* decale une position vers le haut tous les elements de la pile a.
Le premier element devient le dernier*/
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
	last->next = first;//pointeur first sur le dernier elememt // circle list
	*head = first->next; //debut de liste au 2nd element
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