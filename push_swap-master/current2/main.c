/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:08:30 by mvicedo           #+#    #+#             */
/*   Updated: 2022/09/22 18:00:10 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a, int stack_size)
{
	if (check_sort(a) == 0)
		return ;
	else if (stack_size == 2)
	{
		swap_nodes(a);
		printf("sa \n");
	}
	else if (stack_size == 3)
	{
		algo_for_3(a);
	}
}

t_stack	*init_stack_a(char **argv, t_stack *a)
{
	long int	n;
	int			i;

	i = 1;
	while (argv[i])
	{
		n = ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			exit_error(&a);
		stack_add_back(&a, n);
		i++;
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	//t_stack	*b;
	t_stack	*copy;
	int		stack_size;

	a = NULL;
	//b = NULL;
	if (argc == 1)
		return (0);
	if (check_input(argv) == 0)
	{
		a = init_stack_a(argv, a);
		if (check_duplicates(a) == 0)
		{
			stack_size = ft_stack_size(a);
			copy = ft_stack_copy(a);
			get_index(&copy, &a, stack_size);
			print_stack(a);
			push_swap(&a, stack_size);
			print_stack(a);
		}
		free_stack(&a);
		//free_stack(&b);
	}
	return (0);
}
