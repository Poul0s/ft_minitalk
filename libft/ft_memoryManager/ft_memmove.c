/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:44:48 by psalame           #+#    #+#             */
/*   Updated: 2023/10/31 13:02:28 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	int		overlap;

	if (dest == NULL && src == NULL && n != 0)
		return (dest);
	overlap = 0;
	i = 0;
	if (src < dest)
		overlap = 1;
	if (src < dest)
		i = n;
	while ((overlap == 1 && i > 0) || (overlap == 0 && i < n))
	{
		if (overlap == 1)
		{
			((unsigned char *)dest)[i - 1] = ((unsigned char *)src)[i - 1];
			i--;
		}
		else
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
