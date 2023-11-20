/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:41:40 by psalame           #+#    #+#             */
/*   Updated: 2023/11/01 12:48:22 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*first;
	t_list	*next;

	if (lst == NULL)
		return ;
	first = *lst;
	while (first != NULL)
	{
		next = first->next;
		ft_lstdelone(first, del);
		first = next;
	}
	*lst = NULL;
}
