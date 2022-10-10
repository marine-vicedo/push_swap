/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:42:21 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/10 16:43:26 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *stash, char *buffer)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	i = 0;
	len = ft_strlen(stash) + ft_strlen(buffer);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (stash && stash[i] != '\0')
	{
		str[i] = stash[i];
		i++;
	}
	j = 0;
	while (buffer && buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[i] = '\0';
	free (stash);
	return (str);
}

char	*read_instructions(int fd)
{
	static char	*str;
	int			i_read;
	char		*buf;

	i_read = 1;
	buf = NULL;
	if (fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buf = malloc(sizeof(char) * (2));
	if (!buf)
		return (NULL);
	while (i_read > 0)
	{
		i_read = read(fd, buf, 1);
		if (i_read < 0)
			return (NULL);
		buf[i_read] = '\0';
		str = ft_strjoin(str, buf);
	}
	free (buf);
	return (str);
}
