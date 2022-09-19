#include "push_swap.h"

int	ft_is_sorted(t_stack *a)
{
	while (a != NULL && a->next != NULL)
	{
		if (a->value < a->next->value)
		{
			a = a->next;
		}
		else
			return 0;
	}
	return 1;
}

int check_input(char **argv)
{
	int	i;
	
	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == 0)
		{
			printf("Error check\n");
			return 0;
		}
		i++;
	}
	return (1);
}