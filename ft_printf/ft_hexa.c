/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 20:01:44 by emohamed          #+#    #+#             */
/*   Updated: 2023/01/02 02:39:41 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_hexa(unsigned long n, char*b)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_hexa(n / 16, b);
		count += ft_hexa(n % 16, b);
	}
	else
		count += ft_putchar(b[n]);
	return (count);
}
