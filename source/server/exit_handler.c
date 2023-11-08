/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:22:52 by psalame           #+#    #+#             */
/*   Updated: 2023/11/08 19:37:43 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_server.h"

static void	handle_signal(int signal, siginfo_t *info, void *oldaction)
{
	(void) info;
	(void) oldaction;
	ft_printf("Receiving signal %d", signal);
	if (g_msg_data != NULL)
	{
		if (g_msg_data->str != NULL)
			free(g_msg_data->str);
		free(g_msg_data);
	}
	kill(getpid(), SIGKILL);
}

void	init_exit(void)
{
	struct sigaction	action;
	sigset_t			mask;
	int					i;
	int					kill_signals[8];

	kill_signals[0] = SIGABRT;
	kill_signals[1] = SIGHUP;
	kill_signals[2] = SIGINT;
	kill_signals[3] = SIGKILL;
	kill_signals[4] = SIGQUIT;
	kill_signals[5] = SIGSTOP;
	kill_signals[6] = SIGTSTP;
	kill_signals[7] = SIGTERM;
	sigemptyset(&mask);
	sigaddset(&mask, SIGUSR1);
	sigaddset(&mask, SIGUSR2);
	action.sa_mask = mask;
	action.sa_sigaction = &handle_signal;
	i = 0;
	while (i < 8)
	{
		sigaction(kill_signals[i], &action, NULL);
		i++;
	}
}
