/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:24:28 by psalame           #+#    #+#             */
/*   Updated: 2023/11/08 22:17:46 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"

int	g_end_program;

void	send_byte(pid_t pid, char c)
{
	unsigned short	i;

	i = 0;
	while (i <= 7 && !g_end_program)
	{
		if (((c >> i) & 1) == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i++;
		usleep(100);
	}
}

void	send_message(pid_t pid, char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && !g_end_program)
	{
		send_byte(pid, str[i]);
		i++;
	}
	send_byte(pid, '\0');
}

void	handle_success_code(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf("Successfuly sent message !\n");
		exit(0);
	}
	else
	{
		g_end_program = 1;
		ft_printf("Error while sending message. (server response error)\n");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	pid_t	serverpid;

	if (ac != 3)
	{
		ft_printf("Bad arguments number.\n");
		return (1);
	}
	serverpid = ft_atoi(av[1]);
	if (serverpid <= 0)
	{
		ft_printf("Bad pid (%d).\n", serverpid);
		return (1);
	}
	g_end_program = 0;
	signal(SIGUSR1, &handle_success_code);
	signal(SIGUSR2, &handle_success_code);
	send_message(serverpid, av[2]);
	sleep(30);
	if (g_end_program == 0)
	{
		ft_printf("Error while sending message. (no server response)\n");
		return (1);
	}
	return (0);
}
