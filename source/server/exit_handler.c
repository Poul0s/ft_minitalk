/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:22:52 by psalame           #+#    #+#             */
/*   Updated: 2023/11/13 22:21:45 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_server.h"

extern t_message	*g_msg_data;

static void	handle_signal(int signal, siginfo_t *info, void *oldaction)
{
	(void) signal;
	(void) info;
	(void) oldaction;
	if (g_msg_data != NULL)
	{
		if (g_msg_data->str != NULL)
			free(g_msg_data->str);
		free(g_msg_data);
	}
	exit(EXIT_SUCCESS);
}

void	init_exit(void)
{
	struct sigaction	action;
	sigset_t			mask;
	int					i;
	int					kill_signals[6];

	kill_signals[0] = SIGABRT;
	kill_signals[1] = SIGHUP;
	kill_signals[2] = SIGINT;
	kill_signals[3] = SIGQUIT;
	kill_signals[4] = SIGTSTP;
	kill_signals[5] = SIGTERM;
	sigemptyset(&mask);
	sigaddset(&mask, SIGUSR1);
	sigaddset(&mask, SIGUSR2);
	action.sa_mask = mask;
	action.sa_sigaction = &handle_signal;
	action.sa_flags = SA_SIGINFO;
	i = 0;
	while (i < 6)
	{
		sigaction(kill_signals[i], &action, NULL);
		i++;
	}
}
