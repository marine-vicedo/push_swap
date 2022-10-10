#include "checker.h"

int	check_sort(t_stack **a)
{
	t_stack *temp;

	temp = *a;
	while (temp != NULL && temp->next != NULL)
	{
		if (temp->value < temp->next->value)
			temp = temp->next;
		else
			return (1);
	}
	return (0);
}

t_stack	*init_stack_a(char **argv, t_stack *a)
{
	long int	n;
	int			i;

	n = 0;
	i = 1;
	while (argv[i])
	{
		n = ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			exit_error(&a, NULL);
		stack_add_back(&a, n);
			i++;
	}
	return (a);
}

void free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	char	**moves;
	t_stack	*b;
	char	*str;

	a = NULL;
	moves = NULL;
	b = NULL;
	str = NULL;
	if (argc == 1)
		return (0);
	if (check_input(argv) == 1)
		exit_error(&a, NULL);
	a = init_stack_a(argv, a);
	if (check_duplicates(a) == 1)
		exit_error(&a, NULL);
	str = read_instructions(0);
	moves = tab_instructions(str);
	sort_stack(moves, &a, &b);
	if (check_sort(&a) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free (str);
	free_tab(moves);
	//print_stack(a);
	free_stack(&a);
	free_stack(&b);	
}