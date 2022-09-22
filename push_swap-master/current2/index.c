/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:39:06 by mvicedo           #+#    #+#             */
/*   Updated: 2022/09/22 17:40:03 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*bubble_sort(t_stack **a)
{
	t_stack	*temp1;
	t_stack	*temp2;

	temp1 = *a;
	if (a == NULL)
		return (0);
	while (temp1->next != NULL)
	{
		temp2 = *a;
		while (temp2->next != NULL)
		{
			if (temp2->value > temp2->next->value)
			{
				swap(&temp2->value, &temp2->next->value);
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	return (*a);
}

void	get_index(t_stack **copy, t_stack **a, int stack_size)
{
    t_stack *temp;
	t_stack *sort_stack;
	int i;

	sort_stack = bubble_sort(copy);
	temp = *a;
    i = 1;
	while (i <= stack_size)
	{
		if (temp->value == sort_stack->value) 
		{
			temp->index = i;
			i++;
		}
		temp = temp->next;
		if (temp == NULL)
		{
			sort_stack = sort_stack->next;
			temp = *a;
		}
	}       
}

/*smallest index is 'temp->index == 1'
biggest index is 'temp->index == stack_size'*/

t_stack	*ft_stack_copy(t_stack *a)
{
	t_stack	*copy;
	t_stack	*temp;
	
	copy = NULL;
	temp = a;
	while (temp != NULL)
	{
		stack_add_back(&(copy), temp->value);
		temp = temp->next;

	}
	return (copy);
}
