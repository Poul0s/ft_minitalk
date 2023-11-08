/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:02:38 by psalame           #+#    #+#             */
/*   Updated: 2023/11/08 19:39:17 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_SERVER_H
# define MINITALK_SERVER_H
# include <unistd.h>
# include <signal.h>
# include "libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_message
{
	char		*str;
	size_t		size_coef;
	size_t		i;
}			t_message;

t_message	*g_msg_data;

void	*ft_realloc(void *ptr, size_t oldsize, size_t newsize);
void	init_exit(void);

#endif