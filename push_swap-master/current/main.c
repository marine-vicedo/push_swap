#include "push_swap.h"

int	check_integers(char *str)
{
	int i;
	i = 1;

	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 1)
		{
			printf("%c ", str[i]);
			i++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

void	swap_a(t_stack *a)
{
	t_stack	*temp;

	temp = a;

	if (temp != NULL && temp->next != NULL)
		swap(&temp->value, &temp->next->value);

}

void	push_swap(t_stack *a, int size)
{
	if (size == 2)
	{
		swap_a(a);
	}
}

int	main (int argc, char **argv)
{
    t_stack    *a;
	int	i;
	int n;
	int size;

    a = NULL;
	i = 1;
	if (argc == 1)
		return 0;
	//printf("%c", *argv[2]);
	//printf("%s", argv[0]);
	while (argv[i])
	{
		if (check_integers(argv[i]) == 1)
		{
			//printf("%s", argv[i]);
			i++;
		}
		else
			printf("Error");
	}
	i = 1;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		stack_add_back(&a, n);
		i++;
	}
	size = stack_size(a);
	printf("%d\n", size);
	printf("La liste avant swap \n");
	print_stack(a);
	//printf("%d\n %d\n", a->value, (a->next)->value);
	printf("La liste apres swap \n");
	push_swap(a, size);
	print_stack(a);
}