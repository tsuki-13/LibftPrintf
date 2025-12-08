/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:41:13 by mabar             #+#    #+#             */
/*   Updated: 2025/12/08 15:23:04 by mabar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hexa_p(unsigned long n, int *count)
{
	char	*a;

	a = "0123456789abcdef";
	if (n > 15)
		ft_putnbr_hexa_p(n / 16, count);
	*count += write(1, &(a[n % 16]), 1);
	return ;
}
