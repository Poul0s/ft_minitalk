/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:24:28 by psalame           #+#    #+#             */
/*   Updated: 2023/11/20 20:05:31 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"

short	g_received;

void	send_byte(pid_t pid, char c)
{
	unsigned short	i;
	int				nb_try;

	i = 0;
	nb_try = 0;
	while (i <= 7 && g_received != -1)
	{
		nb_try++;
		if (g_received == 1)
		{
			g_received = 0;
			if (((c >> i) & 1) == 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			i++;
			nb_try = 0;
		}
		else if (nb_try == 10000)
			g_received = -1;
		usleep(100);
	}
}

void	send_message(pid_t pid, char *str)
{
	size_t	i;
	int		nb_try;

	i = 0;
	nb_try = 0;
	while (str[i] && g_received != -1)
	{
		send_byte(pid, str[i]);
		i++;
	}
	if (g_received != -1)
		send_byte(pid, '\0');
	while (g_received == 0 && nb_try != 100000)
	{
		usleep(10);
		nb_try++;
	}
	if (g_received == 1)
		ft_printf("Successfuly sent message !\n");
	else
		ft_printf("Error while sending message. (no server response)\n");
}

void	handle_success_code(int signal)
{
	if (signal == SIGUSR1)
		g_received = 1;
	else
	{
		g_received = -1;
		ft_printf("Error while sending message. (server response error)\n");
		exit(EXIT_FAILURE);
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
	g_received = 1;
	signal(SIGUSR1, &handle_success_code);
	signal(SIGUSR2, &handle_success_code);
	send_message(serverpid, av[2]);
	return (0);
}
