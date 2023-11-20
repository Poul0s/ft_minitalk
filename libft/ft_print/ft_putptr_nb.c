/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:17:39 by psalame           #+#    #+#             */
/*   Updated: 2023/11/07 22:15:30 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr_nb(void *ptr)
{
	char	*res;
	int		len;

	if (ptr == NULL)
		return (ft_putstr_nb("(nil)"));
	res = ft_ultoa_base((long long) ptr, FT_HEXA_BASE);
	if (res == NULL)
		return (ft_putptr_nb("(nil)"));
	len = ft_putstr_nb("0x") + ft_putstr_nb(res);
	free(res);
	return (len);
}
