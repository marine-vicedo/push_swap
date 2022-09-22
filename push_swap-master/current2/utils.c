/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:23:52 by mvicedo           #+#    #+#             */
/*   Updated: 2022/09/22 17:39:52 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*int	ft_compare(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (s1[i] == '+' && s2[j] != '+') // nbs2 soit - soit positif
		i++; // on skippe le '+' de s1
	else if (s1[i] != '+' && s2[j] == '+')
		j++; //on skippe le '+' de s2
	while ((s1[i] || s2[j]) && (s1[i] == s2[j]))
	{
		i++;
		j++;
	}
	return (s1[i] - s2[j]);
}*/

long int	ft_atoi(const char *str)
{
	int			i;
	long int	sign;
	long int	resultat;

	i = 0;
	sign = 1;
	resultat = 0;
	while ((str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat = resultat * 10 + (str[i] - 48);
		i++;
	}
	return (resultat * sign);
}

void	exit_error(t_stack **a)
{
	if (a == NULL || *a != NULL)
		free_stack(a);
	printf("Error");
	exit (0);
}
