#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stddef.h>
#include <unistd.h>

typedef struct stack
{
    int value;
    struct stack *next;
    int index;
} t_stack;

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

void print_stack(t_stack *stack)
{
    t_stack *temp;

    temp = stack;
    while (temp != NULL)
    {
        printf("%d -> %d\n", temp->value, temp->index);
        temp = temp->next;
    }
    printf("NULL \n");
}


void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
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


void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

long int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	resultat;

	i = 0;
	sign = 1;
	resultat = 0;	
	while ((str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat = resultat * 10 + (str[i] - 48);
		i++;
	}
	return (resultat * sign);
}


t_stack	*fill_stack_values(int ac, char **av, t_stack *stack_a)
{
	long int	nb;
	int			i;

	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&stack_a, NULL);
		else
			stack_add_back(&stack_a, nb);
		i++;
	}
	return (stack_a);
}

void	swap(int *a, int *b)
{
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

t_stack   *bubble_sort(t_stack **a)
{
    t_stack *temp1;
    t_stack *temp2;

    temp1 = *a;
    if (a == NULL)
        return 0;
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

int	main (int argc, char **argv)
{
    t_stack *a;
	t_stack	*b;
	t_stack	*copy;
	int stack_size;

    a = NULL;
	b = NULL;
	if (argc == 1)
		return 0;
	a = fill_stack_values(argc, argv, a);
	stack_size = ft_stack_size(a);
	copy = ft_stack_copy(a);
	get_index(&copy, &a, stack_size);
	print_stack(a);
	free_stack(&a);
	free_stack(&b);
	return 0;
}
