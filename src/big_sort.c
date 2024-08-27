/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:16:11 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/10 16:29:59 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_in_b(t_stack **a, t_stack **b, int stack_size_a)
{
	int	i;
	int	middle_list;
	int	count_pb;

	i = 0;
	middle_list = stack_size_a / 2;
	count_pb = 0;
	while (stack_size_a > 6 && i < stack_size_a && count_pb < middle_list)
	{
		if ((*a)->index <= middle_list)
		{
			pb(a, b);
			count_pb++;
		}
		else
			ra(a);
		i++;
	}
	while (stack_size_a - count_pb > 3)
	{
		pb(a, b);
		count_pb++;
	}
}

int	get_position_index_min(t_stack **a)
{
	t_stack	*temp;
	int		pos_min;

	temp = *a;
	pos_min = 0;
	get_position(a);
	while (temp != NULL)
	{
		if (temp->index == 1)
				pos_min = temp->pos;
		temp = temp->next;
	}
	return (pos_min);
}

void	last_sort_for_a(t_stack **a, int stack_size_a)
{
	int		pos_min;

	pos_min = get_position_index_min(a);
	if (pos_min > stack_size_a / 2)
	{
		while (pos_min < stack_size_a)
		{
			rra(a);
			pos_min++;
		}
	}
	else
	{
		while (pos_min > 0)
		{
			ra(a);
			pos_min--;
		}
	}
}

void	big_sort(t_stack **a, t_stack **b, int stack_size_a)
{
	push_all_in_b(a, b, stack_size_a);
	algo_for_3(a);
	while (*b != NULL)
	{
		target_position_for_b(a, b);
		cost(a, b);
		find_the_better_move(a, b);
	}
	if (check_sort(a) == 1)
		last_sort_for_a(a, stack_size_a);
}
