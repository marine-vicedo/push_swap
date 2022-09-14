#include "push_swap.h"

/* intervertit les 2 premiers elements au sommet de la pile a */
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
}

void push_a(t_stack **b, t_stack **a)
{
	t_stack *temp;

	if (a != NULL)
	{
		temp = (*b)->next;
		(*b)->next = *a;
		*a = *b;
		*b = temp;
	}

}*/



/* prend le permier element au sommet de a et le met sur b. Ne fait rien si a est vide */

void push_b(t_stack **a, t_stack **b)
{
	/*t_stack *temp;

	if (*a != NULL)
	{
		temp = (*a)->next;
		(*a)->next = *b;
		*b = *a;
		*a = temp;
	}*/

	t_stack *temp;

	if (*a != NULL)
	{
		temp = *a;
		*a = (*a)->next;
		temp->next = *b;
		*b = temp;
	}

}

/* decale une position vers le bas tous les elements de la pile a. Le dernier element devient le premier*/
void reverse_rotate_a(t_stack **a)
{

	/*t_stack *temp;

	temp = *a;
	while (temp != NULL && temp->next != NULL)
	{
		temp = (temp)->next;//on avance temp jusqu'au dernier element
	}
	temp->next = *a;
	(*a)->next = *a;*/
}