/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:54:23 by jbrown            #+#    #+#             */
/*   Updated: 2022/01/28 15:53:25 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	finds the beginning and end points of a string using delimiter. */

static int	findstring(int *first, int last, char c, char *s)
{
	while (s[*first] == c)
		(*first)++;
	last = *first;
	while (s[last] && s[last] != c)
		last++;
	return (last);
}

/*	returns a count of the total number of strings to be made. */

static int	numofstrings(char *s, char c)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (s[i])
	{
		if ((s[i + 1] == c || !(s[i + 1])) && s[i] != c)
			r++;
		i++;
	}
	return (r);
}

/*	fills a single array using a beginning and end.
	Note: consider using substring instead. */

static char	*fillstring(char *s1, int first, int last)
{
	int		i;
	char	*s2;

	s2 = malloc(sizeof(*s2) * ((last - first) + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while ((first + i) < last && s1[first + i])
	{
		s2[i] = s1[first + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

/*	free strings in case of memory allocation faliure to prevent
	memory leaks. */

static void	freestrings(char **s, int len)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

/*	creates an array of arrays by splitting a single 
	array using delimitor 'c'. */

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
	while (s[first] && i < numofstrings((char *) s, c))
	{
		last = findstring(&first, last, c, (char *) s);
		strs[i] = fillstring((char *) s, first, last);
		if (!strs[i])
		{
			freestrings(strs, i);
			return (NULL);
		}
		first = last;
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
