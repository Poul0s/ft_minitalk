/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:37:57 by psalame           #+#    #+#             */
/*   Updated: 2023/11/07 22:15:38 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_nb(const char *str)
{
	size_t	strlen;

	if (str == NULL)
		return (ft_putstr_nb("(null)"));
	strlen = ft_strlen((char *)str);
	write(1, str, strlen);
	return (strlen);
}
