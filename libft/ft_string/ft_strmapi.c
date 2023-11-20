/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:28:33 by psalame           #+#    #+#             */
/*   Updated: 2023/11/07 22:17:10 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*res;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen((char *) s);
	res = malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (res);
	i = 0;
	while (i < len)
	{
		res[i] = (*f)(i, ((char *)s)[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}
