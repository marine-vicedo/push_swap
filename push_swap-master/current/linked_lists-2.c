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

int	stack_size(t_stack *a)
{
	size_t	size;

	size = 0;
	while (a != NULL)
	{
	    a = a->next;
		size++;
	}
	return (size);
}


void print_stack(t_stack *a)
{
    while (a != NULL)
    {
        printf("%d -> ", a->value);
        a = a->next;
    }
    printf("NULL \n");
}
