/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:58:28 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/11 19:01:53 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_instructions(char *move, t_stack **a, t_stack **b, char **moves)
{
	if (ft_strcmp(move, "pa") == 0)
		pa(b, a);
	else if (ft_strcmp(move, "pb") == 0)
		pb(a, b);
	else if (ft_strcmp(move, "ra") == 0)
		ra(a);
	else if (ft_strcmp(move, "rb") == 0)
		rb(b);
	else if (ft_strcmp(move, "rr") == 0)
		rotate_both(a, b);
	else if (ft_strcmp(move, "rra") == 0)
		rra(a);
	else if (ft_strcmp(move, "rrb") == 0)
		rrb(b);
	else if (ft_strcmp(move, "rrr") == 0)
		reverse_rotate_both(a, b);
	else if (ft_strcmp(move, "sa") == 0)
		sa(a);
	else if (ft_strcmp(move, "sb") == 0)
		sb(b);
	else if (ft_strcmp(move, "ss") == 0)
		ss(a, b);
	else
		error_instruction(a, b, moves);
}

void	sort_stack(char **moves, t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while (moves[i])
	{
		do_instructions(moves[i], a, b, moves);
		i++;
	}
}

char	**tab_instructions(char *str)
{
	char	**tab;

	tab = NULL;
	tab = ft_split(str, '\n');
	free(str);
	return (tab);
}
