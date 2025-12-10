/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabar <mabar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:41:12 by mabar             #+#    #+#             */
/*   Updated: 2025/12/10 13:35:18 by mabar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handlepointer(void *ptr, int *count)
{
	if (!ptr)
		*count += write(1, "(nil)", 5);
	else
	{
		*count += write(1, "0x", 2);
		ft_putnbr_hexa_p((unsigned long)(ptr), count);
	}
}

static void	handlearguments(char c, va_list args, int *count)
{
	if (c == '%')
		*count += write(1, "%", 1);
	else if (c == 'c')
		*count += write(1, &(char){va_arg(args, int)}, 1);
	else if (c == 's')
		ft_putstr_fdd(va_arg(args, char *), 1, count);
	else if (c == 'd' || c == 'i')
		ft_putnbr_fdd(va_arg(args, int), 1, count);
	else if (c == 'x')
		ft_putnbr_hexa((va_arg(args, unsigned int)), 'x', count);
	else if (c == 'X')
		ft_putnbr_hexa((va_arg(args, unsigned int)), 'X', count);
	else if (c == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), count);
	else if (c == 'p')
		handlepointer(va_arg(args, void *), count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	a;
	int		count;

	a = 0;
	count = 0;
	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (format[a])
	{
		if (format[a] == '%')
		{
			if (format[a + 1] == '\0')
			{
				count--;
				break;
			}
			handlearguments(format[a + 1], args, &count);
			a++;
		}
		else
			count += write(1, &format[a], 1);
		a++;
	}
	va_end(args);
	return (count);
}
