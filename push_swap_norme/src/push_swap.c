/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:08:30 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/10 16:03:39 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack **a)
{
	t_stack	*temp;

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
