#include <stdio.h>
int	ft_isdigit(int c)
{	
	if (c >= '0' && c <= '9')
	{
		printf("je suis la\n");
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	resultat;	

	i = 0;
	sign = 1;
	resultat = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			resultat = resultat * 10 + (str[i] - 48);
		}
		else
		{
			printf("Error atoi");
			return 0;
		}
		i++;
	}
	return (resultat * sign);
}

int	main(void)
{
	char str[15] = "0";
	printf("%d\n",ft_atoi(str));
}