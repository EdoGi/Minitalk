/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:11:55 by egiacomi          #+#    #+#             */
/*   Updated: 2021/11/29 20:15:05 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	reception(int param)
{
	if (param == SIGUSR2)
		ft_printf("\nMessage sent\n");
}

int	is_pid(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!(ft_isdigit(arg[i])))
			return (0);
		i++;
	}
	return (1);
}

int	client(int pid, char *str)
{
	int	len;
	int	i;
	int	binstr;

	binstr = 0b10000000;
	i = 0;
	len = ft_strlen(str);
	ft_printf("len is : %d\n", len);
	while (i <= len)
	{
		binstr = 0b10000000;
		while (binstr)
		{
			if ((binstr & str[i]) != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			binstr >>= 1;
			usleep(5000);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3 || !is_pid(argv[1]))
	{
		ft_printf("\nWrong Arguments. Try Again 😡\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	ft_printf("%d\n", pid);
	if (signal(SIGUSR1, reception) == SIG_ERR)
	{
		ft_printf("Error.\n");
		exit(1);
	}
	if (signal(SIGUSR2, reception) == SIG_ERR)
	{
		ft_printf("Error.\n");
		exit(1);
	}
	client(pid, argv[2]);
	while (1)
		;
	return (0);
}
