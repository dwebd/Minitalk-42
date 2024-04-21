/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimirzoe <dimirzoe@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 01:44:50 by dimirzoe          #+#    #+#             */
/*   Updated: 2024/04/21 06:19:48 by dimirzoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_bits(int pid, char current_char)
{
	int	bit_counter;
	int kill_return;

	bit_counter = 0;
	while (bit_counter < 8)
	{
		if ((current_char & (1 << bit_counter)))
			kill_return = kill(pid, SIGUSR1);
		else
			kill_return = kill(pid, SIGUSR2);
		if (kill_return == -1)
		{
			ft_putstr("wrong pid");
			exit(1);
		}
		usleep(350);
		bit_counter++;

	}
}
static int checker(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	checker(av[1]);
	if (ac == 3)
	{
		if (checker(av[1]) || ft_atoi(av[1]) <= 0 || ft_atoi(av[1]) > INT_MAX)
		{
			ft_putstr("WRONG PID\n");
				exit(1);
		}
		while (av[2][i] != '\0')
		{
			ft_send_bits(ft_atoi(av[1]), av[2][i]);
				i++;
		}
		ft_send_bits(ft_atoi(av[1]), '\n');
	}
	else
	{
		ft_putstr("Error: enter three arguments only");
		return (1);
	}
	return (0);
}
