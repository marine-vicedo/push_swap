#include "push_swap.h"

	/* PSEUDO CODE
	if (check_integers(argv) = 1 || check_duplicate(argv) = 1
		|| check_int_max(argv) = 1)
		fprintf(stderr, "Error\n");

int	check_integers(char *argv)
{
	int i;

	i = 1;
	while ()
	{
		if (argv[i] <= '0' && argv[i] >= '9')
			return 0;
		else
			return 1;
		i++;
	}
	return 0;
}*/

int	main (int argc, char **argv)
{
	t_stack	*a;
	int	i;
	int n;

	i = 1;
	if (argc == 1)
		return 0;
	//if (check_integers(argv) = 1)
		//printf("Error");
	a = ft_stack_init();
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		ft_add_back(a, n);
		i++;
	}
	ft_print_stack(a);
}

