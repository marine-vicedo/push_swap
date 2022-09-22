/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:12:16 by mvicedo           #+#    #+#             */
/*   Updated: 2022/09/22 14:21:12 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* decale une position vers le haut tous les elements de la pile a.
Le premier element devient le dernier*/
void	rotate(t_stack **head)
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

/* decale une position vers le bas tous les elements de la pile a.
Le dernier element devient le premier*/
void	reverse_rotate(t_stack **head)
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
	last->next->next = first; //transforme en liste circulaire
	*head = last->next; //debut de la liste au dernier noeud	
	last->next = NULL;//casse la chaine
}
