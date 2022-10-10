#include "checker.h"

static size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*dest;

	i = 0;
	len = ft_strlen((char *)s);
	dest = (char *)malloc ((len + 1) * sizeof(char));
	if (dest == 0)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
			i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}