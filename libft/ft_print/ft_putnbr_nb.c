/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:09:46 by psalame           #+#    #+#             */
/*   Updated: 2023/11/07 22:15:22 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_nb(int nb)
{
	unsigned int	newnb;
	char			c;
	short			len;

	len = 0;
	if (nb < 0)
	{
		newnb = -(nb + 1) + 1;
		write(1, "-", 1);
		len++;
	}
	else
		newnb = nb;
	if (newnb >= 10)
		len += ft_putnbr_nb(newnb / 10);
	c = newnb % 10 + '0';
	write(1, &c, 1);
	len++;
	return (len);
}
