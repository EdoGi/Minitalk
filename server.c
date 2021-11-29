/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:18:15 by egiacomi          #+#    #+#             */
/*   Updated: 2021/11/29 16:16:36 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int param)
{
	static int	i;
	static char	c;

	if (param == SIGUSR1)
		c |= 128 >> i;
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		if (c == '\0')
		{
			ft_printf("\n");
			ft_printf("\n\tMessage Received\n\n");
		}
		i = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sigastruct;

	(void)argc;
	(void)argv;
	pid = getpid();
	ft_printf("\nPid : %d\n\n", pid);
	sigastruct.sa_handler = sig_handler;
	sigemptyset(&sigastruct.sa_mask);
	sigastruct.sa_flags = 0;
	if (sigaction(SIGUSR1, &sigastruct, NULL) == -1)
	{
		ft_printf("Error.\n");
		exit(1);
	}
	if (sigaction(SIGUSR2, &sigastruct, NULL) == -1)
	{
		ft_printf("Error.\n");
		exit(1);
	}
	while (1)
		;
	return (0);
}
