#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b, int stack_size)
{
	if (ft_is_sorted(a) == 1)
		return;
	else if (stack_size == 2)
	{
		swap_nodes(a);
		printf("sa \n");
	}
	else if (stack_size > 2)
	{
		push_b(&a, &b);
		push_b(&a, &b);
		printf("pb \n");
		print_stack(a);
		print_stack(b);
		rotate(&a);
		reverse_rotate(&a);
		printf("ra \n");
		print_stack(a);
		print_stack(b);
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
	t_stack	*b;
	int stack_size;

    a = NULL;
	b = NULL;
	if (argc == 1)
		return 0;
	if (check_input(argv))
	{
		a = fill_stack_args(argc, argv, a);
		stack_size = ft_stack_size(a);
		push_swap(a, b, stack_size);
		print_stack(a);
		ft_clearstack(&a);
		ft_clearstack(&b);
	}
	return 0;
}