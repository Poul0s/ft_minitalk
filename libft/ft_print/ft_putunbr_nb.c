/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:16:48 by psalame           #+#    #+#             */
/*   Updated: 2023/11/07 22:15:42 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_nb(unsigned int nb)
{
	char			c;
	short			len;

	len = 0;
	if (nb >= 10)
		len += ft_putunbr_nb(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
	return (len + 1);
}
