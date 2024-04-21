/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimirzoe <dimirzoe@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 01:44:50 by dimirzoe          #+#    #+#             */
/*   Updated: 2024/04/21 06:09:17 by dimirzoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void ft_confirm_massage(int signal)
{
	 if (signal)
        ft_putstr("massage recieved\n");
    else
         ft_putstr("massage not recieved\n");
}

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
		usleep(350);
		bit_counter++;
		if (kill_return == -1)
		{
			ft_putstr("wrong pid");
			exit(1);
		}
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
	struct sigaction	act1;

	i = 0;
	act1.sa_handler = &ft_confirm_massage;
	act1.sa_flags = 0;
	sigaction(SIGUSR1, &act1, NULL);
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
		ft_putstr("Error: enter three arguments only");
	return (1);

}
