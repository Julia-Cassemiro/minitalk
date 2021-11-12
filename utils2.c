/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:20:27 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/11/11 17:23:16 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

t_bool	is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

t_bool	is_numberstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	if (i == ft_strlen(str))
		return (FALSE);
	while (str[i])
	{
		if (!is_numeric(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	number;
	char			c;

	number = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		number = n * -1;
	}
	else
		number = n;
	if (number >= 10)
	{
		ft_putnbr_fd(number / 10, fd);
	}
	c = number % 10 + '0';
	write(1, &c, 1);
}
