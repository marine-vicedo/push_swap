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

int	ft_stack_size(t_stack *a)
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

/*void    push_stack(t_stack **head, int value)
{
    t_stack *newnode;

    newnode = malloc(sizeof(newnode));
    if (newnode == NULL)
        exit(EXIT_FAILURE);
    newnode->value = value;
    newnode->next = *head;
    *head = newnode;
}*/