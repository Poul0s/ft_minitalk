/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:50:56 by psalame           #+#    #+#             */
/*   Updated: 2023/11/01 11:55:23 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*last_occ;
	char	chr;

	i = 0;
	last_occ = NULL;
	chr = (char) c;
	while (s[i] != 0)
	{
		if (s[i] == chr)
			last_occ = (char *)s + i;
		i++;
	}
	if (chr == 0)
		last_occ = (char *)s + i;
	return (last_occ);
}
