/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:59:07 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/11/11 18:06:14 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>

# include "./libft/libft.h"

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0,
}	t_bool;

typedef struct s_box
{
	char	buffer;
	short	bit_index;
}	t_box;

void	ft_putnbr_fd(int n, int fd);
t_bool	is_numberstr(char *str);
int		ft_atoi(char *str);

#endif