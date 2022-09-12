#include "push_swap.h"

t_stack	*ft_stack_init()
{
	t_stack *stack = malloc(sizeof(*stack));
	stack->first = NULL;

	return stack;
}

void	ft_add_back(t_stack *stack, int value)
{
	//node *nodecurrent;
	node *newnode = malloc(sizeof(*newnode));

	if (stack == NULL || newnode == NULL)
	{
		exit(EXIT_FAILURE);
	}

	newnode->content = value;
	newnode->next = NULL;
	/* On se positionne à la fin de la file */
	if (stack->first != NULL)
	{
		node *tmp = stack->first;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = newnode;
	}
	else /* La file est vide, notre node est le premier */
	{
		stack->first = newnode;
	}
}

void ft_print_stack(t_stack *stack)
{
	if (stack == NULL)
	{
		exit(EXIT_FAILURE);
	}

	node *node = stack->first;
	while (node != NULL)
	{
		printf("%d -> ", node->content);
		node = node->next;
	}
	printf("NULL");
}
