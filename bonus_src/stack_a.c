/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:01:00 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/10 17:01:24 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	print_stack(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp != NULL)
	{
		printf("%d \n", temp->value);
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
