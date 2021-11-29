/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:18:15 by egiacomi          #+#    #+#             */
/*   Updated: 2021/11/29 20:14:54 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int param, siginfo_t *info, void *context)
{
	static int	i;
	static char	c;
	pid_t		client_pid;

	(void)context;
	client_pid = 0;
	if (!client_pid)
		client_pid = info->si_pid;
	if (param == SIGUSR1)
		c |= 128 >> i;
	if (++i == 8)
	{
		ft_printf("%c", c);
		if (c == '\0')
		{
			ft_printf("\n\n\tMessage Received 😊\n\n");
			kill(client_pid, SIGUSR2);
		}
		i = 0;
		c = 0;
	}
	kill(client_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sigastruct;

	(void)argc;
	(void)argv;
	pid = getpid();
	ft_printf("\nPid : %d\n\n", pid);
	sigastruct.sa_sigaction = sig_handler;
	sigemptyset(&sigastruct.sa_mask);
	sigastruct.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sigastruct, NULL) == -1)
	{
		ft_printf("Sigaction error.\n");
		exit(1);
	}
	if (sigaction(SIGUSR2, &sigastruct, NULL) == -1)
	{
		ft_printf("Sigaction error.\n");
		exit(1);
	}
	while (1)
		;
	return (0);
}
