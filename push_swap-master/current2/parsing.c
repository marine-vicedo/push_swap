/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:21:42 by mvicedo           #+#    #+#             */
/*   Updated: 2022/09/22 17:59:29 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack **a)
{
	while (*a != NULL && (*a)->next != NULL)
	{
		if ((*a)->value < (*a)->next->value)
		{
			(*a) = (*a)->next;
		}
		else
			return (1);
	}
	return (0);
}

int	check_for_numbers(const char *str) //ft_atoi adapte
{
	int	i;

	i = 0;
	while ((str[i] == '+' || str[i] == '-') && str[i + 1] != '\0')
		i++;
	while (str[i] && str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
		{
			printf("Error not a number");
			return (1);
		}
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
			{
				printf("doubles !");
				return (1);
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	return (0);
}

int	check_input(char **argv)// 0 IS CORRECT INPUT ; 1 IS ERROR
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (check_for_numbers(argv[i]) == 1)
		{
			printf("Error check for numbers\n");
			return (1);
		}
		i++;
	}
	return (0);
}
