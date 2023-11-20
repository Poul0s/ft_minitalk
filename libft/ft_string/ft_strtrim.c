/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:18:48 by psalame           #+#    #+#             */
/*   Updated: 2023/11/07 22:17:14 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*res;

	if (s1 == NULL)
		return ((char *)s1);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
		i++;
	if (s1[i] == 0)
		return (ft_calloc(1, sizeof(char)));
	start = i;
	i = ft_strlen((char *)s1) - 1;
	while (ft_strchr(set, s1[i]) != NULL)
		i--;
	end = i;
	res = malloc((end - start + 2) * sizeof(char));
	if (res == NULL)
		return (res);
	i = 0;
	while (start <= end)
		res[i++] = s1[start++];
	res[i] = 0;
	return (res);
}
