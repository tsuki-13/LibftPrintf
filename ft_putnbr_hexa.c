/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabar <mabar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:41:13 by mabar             #+#    #+#             */
/*   Updated: 2025/12/08 15:23:04 by mabar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hexa(unsigned int n, char x, int *count)
{
	char	*a;
	char	*b;

	a = "0123456789abcdef";
	b = "0123456789ABCDEF";
	if (n > 15)
		ft_putnbr_hexa(n / 16, x, count);
	if (x == 'x')
		*count += write(1, &(a[n % 16]), 1);
	if (x == 'X')
		*count += write(1, &(b[n % 16]), 1);
	return ;
}
