#include "checker.h"

void	do_instructions(char *str, t_stack **a, t_stack **b)
{
	if (ft_strcmp(str,"pa") == 0)
		pa(b, a);
	else if (ft_strcmp(str,"pb") == 0)
		pb(a, b);
	else if (ft_strcmp(str,"ra") == 0)
		ra(a);
	else if (ft_strcmp(str,"rb") == 0)
		rb(b);
	else if (ft_strcmp(str,"rr") == 0)
		rotate_both(a, b);
	else if (ft_strcmp(str,"rra") == 0)
		rra(a);
	else if (ft_strcmp(str,"rrb") == 0)
		rrb(b);
	else if (ft_strcmp(str,"rrr") == 0)
		reverse_rotate_both(a, b);
	else if (ft_strcmp(str,"sa") == 0)
		sa(a);
	else if (ft_strcmp(str,"sb") == 0)
		sb(b);
	else if (ft_strcmp(str,"ss") == 0)
		ss(a, b);
	else
		exit_error(a, b);
}

void	sort_stack(char **moves, t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while (moves[i])
	{
		do_instructions(moves[i], a, b);
		i++;
	}
}

char	**tab_instructions(char *str)
{
	char	**tab;

	tab = NULL;
	tab = ft_split(str, '\n');
	return (tab);
}