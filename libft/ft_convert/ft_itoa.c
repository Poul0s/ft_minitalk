/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:32:32 by psalame           #+#    #+#             */
/*   Updated: 2023/11/07 22:16:02 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	size_t			len;
	unsigned int	un;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		un = -n;
		len++;
	}
	else
		un = n;
	while (un > 0)
	{
		len++;
		un = un / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*res;
	size_t			len;
	unsigned int	un;
	size_t			i;

	len = ft_intlen(n);
	res = malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = len;
	res[i--] = 0;
	if (n < 0)
	{
		un = -n;
		res[0] = '-';
	}
	else
		un = n;
	while (un > 9)
	{
		res[i--] = '0' + un % 10;
		un /= 10;
	}
	res[i--] = '0' + un % 10;
	return (res);
}
