/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxnbr_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:51:09 by psalame           #+#    #+#             */
/*   Updated: 2023/11/07 22:15:43 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putxnbr_nb(unsigned int nb, short maj)
{
	char	*str;
	int		len;

	if (maj)
		str = ft_ultoa_base(nb, FT_HEXA_BASE_MAJ);
	else
		str = ft_ultoa_base(nb, FT_HEXA_BASE);
	if (str == NULL)
		return (0);
	len = ft_putstr_nb(str);
	free(str);
	return (len);
}
