#include "push_swap.h"

void	push_swap(t_stack *a, int stack_size)
{
	if (ft_is_sorted(a) == 1)
		return;
	else if (stack_size == 2)
	{
		swap_a(a);
		printf("sa \n");
	}
}

void check_input(char **argv)
{
	int	i;
	
	i = 1;
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
		{
			printf("Error\n");
			break;
		}
	}
}

t_stack	*fill_stack_args(int argc, char **argv, t_stack *a)
{
	int	n;
	int	i;

	i = 1;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		stack_add_back(&a, n);
		i++;
	}
	return (a);
}

int	main (int argc, char **argv)
{
    t_stack *a;
	//t_stack	*b;
	int stack_size;

    a = NULL;
	//b = NULL;
	if (argc == 1)
		return 0;
	check_input(argv);
	a = fill_stack_args(argc, argv, a);
	stack_size = ft_stack_size(a);
	push_swap(a, stack_size);
	print_stack(a);
	ft_clearstack(&a);
}