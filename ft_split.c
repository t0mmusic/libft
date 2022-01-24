/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:54:23 by jbrown            #+#    #+#             */
/*   Updated: 2022/01/24 12:59:39 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	findstring(int first, int last, char c, char *s)
{
	last = first;
	while (s[last] && s[last] != c)
		last++;
	return (last);
}

int	numofstrings(char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		if ((s[j + 1] == c || !(s[j + 1])) && s[j] != c)
			i++;
		j++;
	}
	return (i);
}

char	*fillstring(char *s1, char *s2, int first, int last)
{
	int	i;

	s2 = malloc(sizeof(s2) * ((last - first) + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while ((first + i) < last)
	{
		s2[i] = s1[first + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

void	freestrings(char **s, int len)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		free(s[i]);
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	int		first;
	int		last;
	int		i;
	char	**strs;

	strs = malloc(sizeof(*strs) * (numofstrings((char *) s, c) + 1));
	if (!strs)
		return (strs);
	first = 0;
	i = 0;
	while (s[first])
	{
		while (s[first] == c)
			first++;
		if (s[first])
		{
			last = findstring(first, last, c, (char *) s);
			strs[i] = fillstring((char *) s, strs[i], first, last);
			if (strs[i] == NULL)
			{
				freestrings(strs, i);
				return (NULL);
			}
			first = last;
		}
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
