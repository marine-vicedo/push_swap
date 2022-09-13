#include "push_swap.h"

void	swap_a(t_stack *a)
{
	t_stack	*temp;

	temp = a;

	if (temp != NULL && temp->next != NULL)
		swap(&temp->value, &temp->next->value);

}

/*void	swap_b(t_stack *b)
{
	t_stack *temp;

	temp = b;

	if (temp != NULL && temp->next != NULL)
		swap(&temp->value, &temp->next->value);
}

void	swap_ss(t_stack *a, t_stack *b)
{
	swap_a(a);
	swap_b(b));
}*/

void push_b(t_stack *a, t_stack	*b)
{
	if (a = NULL)
		return;	
}