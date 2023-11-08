/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:53:43 by psalame           #+#    #+#             */
/*   Updated: 2023/11/08 11:19:26 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk_server.h>

void	*ft_realloc(void *ptr, size_t oldsize, size_t newsize)
{
	void	*newptr;

	if (ptr == NULL && oldsize != 0)
		return (NULL);
	if (ptr == NULL)
		return (malloc(newsize));
	newptr = malloc(newptr);
	if (newsize < oldsize)
		oldsize = newsize;
	if (newptr != NULL)
		ft_memmove(newptr, ptr, oldsize);
	free(ptr);
	return (newptr);
}
