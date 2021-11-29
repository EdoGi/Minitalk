/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:11:55 by egiacomi          #+#    #+#             */
/*   Updated: 2021/11/29 17:09:35 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
			usleep(400);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argc;
	pid = ft_atoi(argv[1]);
	ft_printf("%d\n", pid);
	client(pid, argv[2]);
	return (0);
}
