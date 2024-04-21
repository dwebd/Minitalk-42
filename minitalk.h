/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimirzoe <dimirzoe@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:12:10 by ajordan-          #+#    #+#             */
/*   Updated: 2024/04/21 04:48:21 by dimirzoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <signal.h>
# include <limits.h>

void	ft_putnbr(int n);
void	ft_putstr(char *s);
void	ft_putchar(char c);
void	ft_sighandle(int sig);
int		ft_isalpha(int c);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_handle(int sig, siginfo_t *info, void *context);

#endif
