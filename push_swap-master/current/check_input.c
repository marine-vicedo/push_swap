#include "push_swap.h"

int	check_integers(char *s)
{
	int i;
	i = 1;

	while (s[i] && s[i] != '\0')
	{
		if (ft_isdigit(s[i]) == 1)
		{
			//printf("%c ", s[i]);
			i++;
		}
		else
			return (0);

	}
	return (1);
}

int	ft_is_sorted(t_stack *a)
{
	while (a != NULL && a->next != NULL)
	{
		if (a->value < a->next->value)
		{
			a = a->next;
		}
		else
			return 0;
	}
	return 1;
}