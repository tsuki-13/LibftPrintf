/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fdd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:41:13 by mabar             #+#    #+#             */
/*   Updated: 2025/12/08 15:23:03 by mabar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fdd(int n, int fd, int *count)
{
	char	a;

	if (n == -2147483648)
	{
		*count += write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		*count += write(fd, "-", 1);
		n = n * -1;
	}
	if (n > 9)
		ft_putnbr_fdd(n / 10, fd, count);
	a = (n % 10) + '0';
	*count += write(fd, &a, 1);
	return ;
}
