/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:47:28 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/11 19:07:43 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_tab(char **tab)
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

void	error_instruction(t_stack **a, t_stack **b, char **moves)
{
	free_all(a, b, moves);
	ft_putstr_fd("Error\n", 2);
	exit (0);
}

void	free_all(t_stack **a, t_stack **b, char **moves)
{	
	free_tab(moves);
	free_stack(a);
	free_stack(b);
}
