/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:33:19 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/04 10:33:21 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* get_position:
*	Assigns a position to each element of a stack from top to bottom
*	in ascending order.
*	Example stack:
*		value:		 3	 0	 9	 1
*		index:		[3]	[1]	[4]	[2]
*		position:	<0>	<1>	<2>	<3>
*	This is used to calculate the cost of moving a certain number to
*	a certain position. If the above example is stack b, it would cost
*	nothing (0) to push the first element to stack a. However if we want to
*	push the highest value, 9, which is in third position, it would cost 2 extra
*	moves to bring that 9 to the top of b before pushing it to stack a.
*/

void    get_position(t_stack **stack)
{
    t_stack	*temp;
    int		i;

    temp = *stack;
    i = 0;
    while (temp != NULL)
    {
        temp->pos = i;
        temp = temp->next;
        i++;
    }
}

/* get_target:
*	Picks the best target position in stack A for the given index of
*	an element in stack B. First checks if the index of the B element can
*	be placed somewhere in between elements in stack A, by checking whether
*	there is an element in stack A with a bigger index. If not, it finds the
*	element with the smallest index in A and assigns that as the target position.
*	--- Example:
*		target_pos starts at INT_MAX
*		B index: 3
*		A contains indexes: 9 4 2 1 0
*		9 > 3 && 9 < INT_MAX 	: target_pos updated to 9
*		4 > 3 && 4 < 9 			: target pos updated to 4
*		2 < 3 && 2 < 4			: no update!
*	So target_pos needs to be the position of index 4, since it is
*	the closest index.
*	--- Example:
*		target_pos starts at INT_MAX
*		B index: 20
*		A contains indexes: 16 4 3
*		16 < 20					: no update! target_pos = INT_MAX
*		4  < 20					: no update! target_pos = INT_MAX
*		3  < 20					: no update! target_pos = INT_MAX
*	... target_pos stays at INT MAX, need to switch strategies.
*		16 < 20					: target_pos updated to 20
*		4  < 20					: target_pos updated to 4
*		3  < 20					: target_pos updated to 3
*	So target_pos needs to be the position of index 3, since that is
*	the "end" of the stack.
*/

int    define_target_stack_a(t_stack **a, int index_b, int index_target, int target_pos_b)
{
	t_stack	*temp_a;

	temp_a = *a;
	while (temp_a != NULL)
	{
		if (temp_a->index > index_b && temp_a->index < index_target)
		{
			index_target = temp_a->index;
			target_pos_b = temp_a->pos;
		}
		temp_a = temp_a->next;
	}
	if (index_target != INT_MAX)
		return (target_pos_b);
	temp_a = *a;
	while (temp_a != NULL)
	{
		if (temp_a->index < index_target)
		{
			index_target = temp_a->index;
			target_pos_b = temp_a->pos;
		}
		temp_a = temp_a->next;
	}
	return (target_pos_b);
}

/* get_target_position:
*	Assigns a target position in stack A to each element of stack A.
*	The target position is the spot the element in B needs to
*	get to in order to be sorted correctly. This position will
*	be used to calculate the cost of moving each element to
*	its target position in stack A.
*/

void    target_position_for_b(t_stack **a, t_stack **b)
{
    t_stack	*temp_b;
    int		target_pos_b;
	int		index_target;

	temp_b = *b;
	target_pos_b = 0;
	//index_target = get_index_max(*a);
	index_target = INT_MAX;
	//printf("index target est %d\n", index_target);
	get_position(a);
	get_position(b);
	while (temp_b != NULL)
	{
		target_pos_b = define_target_stack_a(a, temp_b->index, index_target, target_pos_b);
		temp_b->target_pos = target_pos_b;
		temp_b = temp_b->next;
	}
}
