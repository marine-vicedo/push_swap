#include "push_swap.h"

void    stack_add_back(t_stack **head, int value)
{
    t_stack *newnode;
    t_stack *last;

    last = *head;
    newnode = malloc(sizeof(newnode));
    if (newnode == NULL)
        exit(EXIT_FAILURE);
    newnode->value = value;
    newnode->next = NULL;
    if (*head == NULL)
        *head = newnode;

    else
    {
        while (last->next != NULL)
            last = last->next;
        last->next = newnode;
    }
}

int	ft_stack_size(t_stack *stack) //libft
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


void print_stack(t_stack *stack)
{
    t_stack *temp;

    temp = stack;
    while (temp != NULL)
    {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL \n");
}

void ft_clearstack(t_stack **head)
{
	t_stack	*temp;
	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
}
