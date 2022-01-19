/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:54:23 by jbrown            #+#    #+#             */
/*   Updated: 2022/01/19 14:55:03 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	strnum(char const *s, char c)
{
	int	i;

	i = 1;
	while (*s)
	{
		if (*s == c)
			i++;
		s++;
	}
	return (i);
}

char	*fillstr(const char *s1, int start, int end, char *s2)
{
	int	i;

	s2 = malloc((end - start + 1) * sizeof(*s2));
	if (!s2)
		return (s2);
	i = 0;
	while (start < end)
		s2[i++] = s1[start++];
	s2[i] = '\0';
	return (s2);
}

void	freemem(char **s, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		mem;
	char	**ss;

	ss = malloc(sizeof(*ss) * (strnum(s, c) + 1));
	i = -1;
	j = 0;
	mem = 0;
	while (s[++i])
	{
		if (s[i] == c || s[i + 1] == '\0')
		{
			ss[j] = fillstr(s, mem, i, ss[j]);
			if (!ss[j])
			{
				freemem(ss, j);
				return (NULL);
			}
			j++;
			mem = i + 1;
		}
	}
	ss[j] = NULL;
	return (ss);
}
