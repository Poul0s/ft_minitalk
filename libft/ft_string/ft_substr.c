/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:51:37 by psalame           #+#    #+#             */
/*   Updated: 2023/11/07 22:17:16 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_empty_str(void)
{
	char	*str;

	str = malloc(sizeof(char));
	if (str != NULL)
		str[0] = 0;
	return (str);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	real_len;
	char	*sub;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen((char *)s))
		return (ft_empty_str());
	real_len = ft_strlen((char *)s + start);
	if (len < real_len)
		real_len = len;
	sub = malloc((real_len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (((char *)s)[start + i] && i < real_len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}
