/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:03:48 by psalame           #+#    #+#             */
/*   Updated: 2023/11/08 11:25:49 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_server.h"

t_message	*g_msg_data;

static void	increase_message_size(void)
{
	size_t	oldsize;
	size_t	newsize;

	oldsize = g_msg_data->size_coef * BUFFER_SIZE;
	g_msg_data->size_coef = g_msg_data->size_coef + 1;
	newsize = g_msg_data->size_coef * BUFFER_SIZE;
	g_msg_data->str = ft_realloc(g_msg_data->str, oldsize, newsize);
}

static void	add_message_char(char c)
{
	if (g_msg_data->i >= g_msg_data->size_coef * BUFFER_SIZE)
		increase_message_size();
	ft_printf("{Receiving char}\n");
	if (g_msg_data->str == NULL)
	{
		ft_printf("Error while receiving message.\n");
		g_msg_data->size_coef = 0;
		g_msg_data->i = 0;
		return (NULL);
	}
	g_msg_data->str[g_msg_data->i++] = c;
	if (c == 0)
	{
		ft_printf("%s\n", g_msg_data->str);
		free(g_msg_data->str);
		g_msg_data->str = NULL;
		g_msg_data->size_coef = 0;
		g_msg_data->i = 0;
	}
}

static void	handle_signal(int signal)
{
	static char	c;
	static int	i;

	if (signal == SIGUSR1)
		c = c & ~(1 << i);
	else if (signal == SIGUSR2)
		c = c | (1 << i);
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
	}
}

int	main(void)
{
	g_msg_data = malloc(sizeof(g_msg_data));
	if (g_msg_data == NULL)
	{
		ft_printf("Error while starting up server.");
		return (1);
	}
	g_msg_data->str = NULL;
	g_msg_data->size_coef = 0;
	g_msg_data->i = 0;
	ft_printf("Server PID : %d\n", getpid());
	signal(SIGUSR1, &handle_signal);
	signal(SIGUSR2, &handle_signal);
	while (1)
	{
		usleep(1);
	}
	return (0);
}
