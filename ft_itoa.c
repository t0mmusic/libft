/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:55:33 by jbrown            #+#    #+#             */
/*   Updated: 2022/01/19 16:58:40 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	modsize(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	otherdigits(int n, int factor)
{
	int	mod;

	mod = 1;
	while (factor)
	{
		mod *= 10;
		factor--;
	}
	return (n % mod);
}

int	firstdigit(int n, int i)
{
	while (i)
	{
		n /= 10;
		i--;
	}
	return (n);
}

char	*fillarr(char *arr, int neg, int digits, int n)
{
	int	i;

	i = 0;
	if (neg)
	{
		arr[i] = '-';
		n = -n;
		i++;
	}
	while (digits)
	{
		arr[i] = firstdigit(n, digits - 1) + 48;
		n = otherdigits(n, digits - 1);
		digits--;
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_itoa(int n)
{
	int		neg;
	int		digits;
	char	*arr;

	digits = modsize(n);
	neg = 0;
	if (n < 0)
		neg = 1;
	arr = malloc(sizeof(*arr) * (neg + digits + 1));
	if (!arr)
		return (NULL);
	arr = fillarr(arr, neg, digits, n);
	return (arr);
}
