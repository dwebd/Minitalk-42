/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimirzoe <dimirzoe@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 01:44:43 by dimirzoe          #+#    #+#             */
/*   Updated: 2024/04/21 04:19:12 by dimirzoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sighandle(int signal)
{
	static int	bit;
	static int	current_char;

	if (signal == SIGUSR1)
		current_char = current_char | (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar(current_char);
		bit = 0;
		current_char = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	act;
	pid_t				pid;

	act.sa_handler = &ft_sighandle;
	act.sa_flags = SA_SIGINFO;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr("Error: wrong format");
		return (1);
	}
	ft_putstr("Process ID: ");
	pid = getpid();
	ft_putnbr(pid);
	write(1,"\n", 1);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);

	while (1)
	{
		pause ();
	}
	return (0);
}
