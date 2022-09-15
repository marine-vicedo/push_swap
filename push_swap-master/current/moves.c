#include "push_swap.h"

/* intervertit les 2 premiers elements au sommet de la pile a */
void	swap_nodes(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;

	if (temp != NULL && temp->next != NULL)
		swap(&temp->value, &temp->next->value);

}


/*void	swap_ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
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
	t_stack *temp;

	if (*a != NULL)
	{
		temp = *a;
		*a = (*a)->next;
		temp->next = *b;
		*b = temp;
	}
}

/* decale une position vers le haut tous les elements de la pile a. Le premier element devient le dernier*/
void rotate(t_stack **head)
{
	t_stack	*first;
	t_stack *last;
	
	first = *head;//fixe
	last = *head;
	if (*head == NULL || (*head)->next == NULL)
		return;
	while (last->next != NULL)
	{
		last = last->next;

	}
	last->next = first;//pointeur first sur le dernier elememt // circulaire liste
	*head = first->next; // debut de liste au 2nd element
	first->next = NULL;

}


/* decale une position vers le bas tous les elements de la pile a. Le dernier element devient le premier*/
void reverse_rotate(t_stack **head)
{
	t_stack	*first;
	t_stack *last;

	first = *head; 
	last = *head;
	if (*head == NULL || (*head)->next == NULL)
		return;
	while (last->next->next != NULL)
	{
		last = last->next;
	}
	last->next->next = first; //transforme en liste circulaire
	*head = last->next; //debut de la liste au dernier noeud	
	last->next = NULL;//casse la chaine
}