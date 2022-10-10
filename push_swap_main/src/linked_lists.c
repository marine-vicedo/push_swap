/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marinevicedo <marinevicedo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:06:38 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/03 12:14:05 by marineviced      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_add_back(t_stack **stack, int value)
{
	t_stack	*newnode;
	t_stack	*last;

	last = *stack;
	newnode = malloc(sizeof(t_stack));
	if (newnode == NULL)
		exit(EXIT_FAILURE);
	newnode->value = value;
	newnode->index = 1;
	newnode->pos = 0;
	newnode->target_pos = 0; 
	newnode->cost_a = 0;
	newnode->cost_b = 0;
	newnode->next = NULL;
	if (*stack == NULL)
		*stack = newnode;
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = newnode;
	}
}

int	ft_stack_size(t_stack *stack)
{
	size_t	size;

	size = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

void	print_stack(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp != NULL)
	{
		printf("%d -> [%d] | <%d> | (%d) | cost a : %d | cost b : %d\n", temp->value, temp->index, temp->pos, temp->target_pos, temp->cost_a, temp->cost_b);
		temp = temp->next;
	}
	printf("NULL \n");
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}
