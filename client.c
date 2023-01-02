/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:01:55 by emohamed          #+#    #+#             */
/*   Updated: 2023/01/02 20:10:27 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	convert(int nb, char *bit)
{
	int	i;

	i = 0;
	if (nb == 0 || nb == 1)
	{
		while (i < 7)
		{
			bit[i] = bit[i + 1];
			i++;
		}
		bit[7] = nb + '0';
	}
	else
	{	
		convert(nb / 2, bit);
		convert(nb % 2, bit);
	}
}

void	sended_str( char *pid, int nb)
{
	int		i;
	char	*bit;

	i = 0;
	bit = ft_strdup("00000000");
	convert(nb, bit);
	while (i < 8)
	{
		if (bit[i] == '1')
			kill(ft_atoi(pid), SIGUSR2);
		if (bit[i] == '0')
			kill(ft_atoi(pid), SIGUSR1);
	i++;
		usleep(100);
	}
	free(bit);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (kill(ft_atoi(av[1]), 0) == -1)
	{
		ft_printf("%s OPPPS!! WRONG PID, TRY AGAIN 😐:/ %s\n", RED, END);
		return (0);
	}
	if (ac >= 3)
	{
		while (av[2][i])
		{
			sended_str(av[1], (unsigned char)av[2][i]);
			i++;
		}
		ft_printf("%s MESSAGE SENT SUCCESSFULLY ✔ 😎:) %s\n", GREEN, END);
	}
	else
	{
		ft_printf("%s MESSAGE CANT BE SENT 🤒%s\n", RED, END);
		ft_printf("%sBAD SYNTAX:---> ./client <server_pid> + <text to send>%s\n",
			YELLOW, END);
	}
	return (0);
}
