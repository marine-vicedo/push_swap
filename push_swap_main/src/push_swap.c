/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marinevicedo <marinevicedo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:08:30 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/03 11:43:30 by marineviced      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* check si la pile n'est pas deja triee.
Retourne 0 si elle est triee, 1 si elle n'est pas triee */
int	check_sort(t_stack **a)
{
	t_stack *temp;

	temp = *a;
	while (temp != NULL && temp->next != NULL)
	{
		if (temp->value < temp->next->value)
			temp = temp->next;
		else
			return (1);
	}
	return (0);
}

/* choisit une methode de tri en fonction de la taille de la pile */
void	push_swap(t_stack **a, t_stack **b, int stack_size_a)
{
	if (check_sort(a) == 0)
		return ;
	else if (stack_size_a == 2)
		sa(a);
	else if (stack_size_a == 3)
		algo_for_3(a);
	else
		big_sort(a, b, stack_size_a);
}
