/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:03:48 by psalame           #+#    #+#             */
/*   Updated: 2023/11/08 19:38:00 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_server.h"

static void	increase_message_size(void)
{
	size_t	oldsize;
	size_t	newsize;

	oldsize = g_msg_data->size_coef * BUFFER_SIZE;
	g_msg_data->size_coef = g_msg_data->size_coef + 1;
	newsize = g_msg_data->size_coef * BUFFER_SIZE;
	g_msg_data->str = ft_realloc(g_msg_data->str, oldsize, newsize);
}

static void	add_message_char(char c, pid_t pid)
{
	if (g_msg_data->i >= g_msg_data->size_coef * BUFFER_SIZE)
		increase_message_size();
	if (g_msg_data->str == NULL)
	{
		ft_printf("Error while receiving message.\n");
		kill(pid, SIGUSR2);
		g_msg_data->size_coef = 0;
		g_msg_data->i = 0;
		return ;
	}
	g_msg_data->str[g_msg_data->i++] = c;
	if (c == 0)
	{
		ft_printf("%s\n", g_msg_data->str);
		free(g_msg_data->str);
		g_msg_data->str = NULL;
		g_msg_data->size_coef = 0;
		g_msg_data->i = 0;
		kill(pid, SIGUSR1);
	}
}

static void	handle_signal(int signal, siginfo_t *info, void *oldaction)
{
	static char	c;
	static int	i;

	(void) oldaction;
	if (signal != SIGUSR1 && signal != SIGUSR2)
		return ;
	if (signal == SIGUSR1)
		c = c & ~(1 << i);
	else if (signal == SIGUSR2)
		c = c | (1 << i);
	i++;
	if (i == 8)
	{
		add_message_char(c, info->si_pid);
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	action;

	action.sa_sigaction = &handle_signal;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	g_msg_data = malloc(sizeof(g_msg_data));
	if (g_msg_data == NULL)
	{
		ft_printf("Error while starting up server.\n");
		return (1);
	}
	init_exit();
	g_msg_data->str = NULL;
	g_msg_data->size_coef = 0;
	g_msg_data->i = 0;
	ft_printf("Server PID : %d\n", getpid());
	while (1)
		usleep(1);
	return (0);
}
