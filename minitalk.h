/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:22:52 by egiacomi          #+#    #+#             */
/*   Updated: 2021/11/29 19:06:50 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <sys/signal.h>
# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

int		client(int pid, char *str);
void	sig_handler(int param, siginfo_t *info, void *context);

#endif