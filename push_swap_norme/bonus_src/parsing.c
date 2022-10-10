/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:21:42 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/10 16:46:56 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_for_numbers(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] == '+' || str[i] == '-') && str[i + 1] != '\0')
		i++;
	if (str[i] == '\0')
		return (1);
	while (str[i] && str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

int	check_duplicates(t_stack *a)
{
	t_stack	*temp1;
	t_stack	*temp2;

	temp1 = a;
	while (temp1 != NULL)
	{
		temp2 = temp1->next;
		while (temp2 != NULL)
		{
			if (temp1->value == temp2->value)
				return (1);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	return (0);
}

void	exit_error(t_stack **a, t_stack **b)
{
	if (a == NULL || *a != NULL)
		free_stack(a);
	if (b == NULL || *b != NULL)
		free_stack(b);
	ft_putstr_fd("Error\n", 2);
	exit (0);
}

int	check_input(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (check_for_numbers(argv[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
