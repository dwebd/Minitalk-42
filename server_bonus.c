/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimirzoe <dimirzoe@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 04:20:38 by dimirzoe          #+#    #+#             */
/*   Updated: 2024/04/21 06:06:40 by dimirzoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

void	ft_handle(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static int	current_char;

	(void)context;
	(void)info;
	if (sig == SIGUSR1)
		current_char = current_char | (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar(current_char);
		// if(current_char == '\0')
				kill(info -> si_pid, SIGUSR1);
		bit = 0;
		current_char = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	act;
	pid_t				pid;

	act.sa_sigaction = ft_handle;
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
}
