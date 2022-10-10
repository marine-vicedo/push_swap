/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:16:11 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/04 10:16:12 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push_all_save_three:
*	Pushes all the elements of stack a into stack b, except the three last ones.
*	Pushes the smaller values first, and then the larger values to help with
*	sorting efficiency. */

void	push_all_in_b(t_stack **a, t_stack **b, int stack_size_a)
{
	int	i;
	int middleList;
	int	count_pb;

	i = 0;
	middleList = stack_size_a / 2;
	count_pb = 0;
	while (stack_size_a > 6 && i < stack_size_a && count_pb < middleList)
	{
		if ((*a)->index <= middleList)
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

/* shift_stack:
*	After the bulk of the stack is sorted, shifts stack a until the lowest
*	value is at the top. If it is in the bottom half of the stack, reverse
*	rotate it into position, otherwise rotate until it is at the top of the
*	stack.
*/
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

/* sort:
*	Sorting algorithm for a stack larger than 3.
*		Push everything but 3 numbers to stack B.
*		Sort the 3 numbers left in stack A.
*		Calculate the most cost-effective move.
*		Shift elements until stack A is in order.
*/
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
