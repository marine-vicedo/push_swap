/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:33:02 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/10 15:42:34 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/* verfie si les arguments entres sont corrects si oui, initialise la stack, lui attribue des indexes et la tri.
Enfin, libere la memoire et fin du programme. */

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		stack_size_a;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (check_input(argv) == 1)
		exit_error(&a, NULL);
	a = init_stack_a(argv, a);
	if (check_duplicates(a) == 1)
		exit_error(&a, NULL);
	stack_size_a = ft_stack_size(a);
	get_index(a);
	push_swap(&a, &b, stack_size_a);
	//printf("print stack a apres pushswap:\n");
	//print_stack(a);
	//print_stack(b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}