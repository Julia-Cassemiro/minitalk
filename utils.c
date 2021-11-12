/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:58:21 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/11/11 18:06:55 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

t_bool	is_space(char c)
{
	if (c == ' ')
		return (TRUE);
	return (FALSE);
}

t_bool	is_whitespace(char c)
{
	if (c >= 9 && c <= 13)
		return (TRUE);
	return (is_space(c));
}

int	ft_atoi(char *str)
{
	unsigned int	result;
	size_t			i;
	int				is_negative;

	i = 0;
	result = 0;
	is_negative = 1;
	while (str[i] && is_whitespace(str[i]))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			is_negative *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return ((int)result * is_negative);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
