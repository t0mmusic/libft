/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:55:33 by jbrown            #+#    #+#             */
/*   Updated: 2022/01/28 09:54:05 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Counts the digits in the input number.*/

static int	nbrcount(size_t n, int radix)
{
	int	count;

	count = 0;
	while (n)
	{
		n /= radix;
		count++;
	}
	return (count);
}

/*	Assigns the string by taking the modulus of
	10 of the input number and adding it to the string
	starting from the end, then dividing the number
	by 10.*/

static char	*ft_nbrtoa(size_t n, int radix)
{
	int		digits;
	char	*s;

	if (!n)
		return (ft_strdup("0"));
	digits = nbrcount(n, radix);
	s = malloc(sizeof(*s) * (digits + 1));
	if (!s)
		return (NULL);
	s[digits] = '\0';
	while (--digits > -1)
	{
		if ((n % radix) > 9)
			s[digits] = (n % radix) + 87;
		else
			s[digits] = (n % radix) + '0';
		n /= radix;
	}
	return (s);
}

/*	Handles negative numbers by joining a 
	'-' symbol to the returned number string.*/

char	*ft_itoa(int n)
{
	char			*t1;
	char			*t2;
	long long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr = -nbr;
		t1 = ft_nbrtoa(nbr, 10);
		if (!t1)
			return (NULL);
		t2 = t1;
		t1 = ft_strjoin("-", t1);
		free (t2);
		return (t1);
	}
	return (ft_nbrtoa(nbr, 10));
}
