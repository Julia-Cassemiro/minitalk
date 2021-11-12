/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   server.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/10/12 22:05:14 by jgomes-c		  #+#	#+#			 */
/*   Updated: 2021/11/11 18:29:27 by jgomes-c		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "./includes/minitalk.h"

t_box	g_box;

void	next_bit(void)
{
	g_box.bit_index++;
	if (g_box.bit_index >= 8)
	{
		g_box.bit_index = 0;
		write(1, &g_box.buffer, 1);
		g_box.buffer = 0;
	}
}

void	listen_0(int signal)
{
	(void)signal;
	g_box.buffer <<= 1;
	next_bit();
}

void	listen_1(int signal)
{
	(void)signal;
	g_box.buffer <<= 1;
	g_box.buffer |= 1;
	next_bit();
}

int	main(void)
{
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	g_box.buffer = 0;
	g_box.bit_index = 0;
	signal(SIGUSR1, listen_0);
	signal(SIGUSR2, listen_1);
	while (TRUE)
		pause();
	return (0);
}
