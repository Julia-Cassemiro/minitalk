/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:02:28 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/11/11 18:21:20 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

void	send_char(int pid, char c)
{
	int	bit_index;

	bit_index = 8;
	while (--bit_index >= 0)
	{
		if (c >> bit_index & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(150);
	}
}

void	send_msg(int pid, char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
	{
		send_char(pid, str[count]);
		count++;
	}
	send_char(pid, '\n');
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (0);
	if (!is_numberstr(argv[1]))
		return (0);
	pid = ft_atoi(argv[1]);
	send_msg(pid, argv[2]);
	return (pid);
}
