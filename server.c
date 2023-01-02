/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:40:11 by emohamed          #+#    #+#             */
/*   Updated: 2023/01/02 02:29:37 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	display_banner(int pid)
{
	ft_printf("\n\t%s███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗██╗\
			%s\n", YELLOW, END);
	ft_printf("\t%s██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝\
			%s \n", YELLOW, END);
	ft_printf("\t%s██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗\
			%s \n", YELLOW, END);
	ft_printf("\t%s██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\
			%s\n", YELLOW, END);
	ft_printf("\t%s╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\
			%s\n", YELLOW, END);
	ft_printf("\t\t%s｡☆✼★━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━★✼☆｡%s\n", YELLOW, END);
	ft_printf("%s\n\t\tPID: %d%s\t\t\t%sBy: emohamed%s\n", GREEN, pid, END,
		YELLOW, END);
	ft_printf("%s\n\t\t\t LETS HAVE A  MINI-TALK %s\n", RED, END);
}

int	math_pow(int i)
{
	int	nb;

	nb = 128;
	while (i < 7)
	{
		nb = nb / 2;
		i++;
	}
	return (nb);
}

static void	signal_handler(int sign, siginfo_t *signalfo, void *oldact)
{
	static int				i;
	static unsigned char	count;
	static int				actpid;

	(void)oldact;
	if (actpid != signalfo->si_pid)
	{
		actpid = signalfo->si_pid;
		i = 7;
		count = 0;
	}
	if (sign == SIGUSR2)
	{
		count = count + math_pow(i);
	}
	i--;
	if (i == -1)
	{
		ft_printf("%c", count);
		i = 7;
		count = 0;
	}
}

int	main(void)
{
	struct sigaction	act;
	int					pid;

	act.sa_sigaction = signal_handler;
	pid = getpid();
	display_banner(pid);
	ft_printf("%s↓  RECEIVED MESSAGES  ↓ %s\n\n", YELLOW, END);
	while (1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
	return (0);
}
