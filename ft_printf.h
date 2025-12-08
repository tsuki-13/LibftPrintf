/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabar <mabar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:41:39 by mabar             #+#    #+#             */
/*   Updated: 2025/11/18 16:43:39 by mabar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putnbr_fdd(int n, int fd, int *count);
void	ft_putnbr_hexa_p(unsigned long n, int *count);
void	ft_putnbr_hexa(unsigned int n, char x, int *count);
void	ft_putnbr_u(unsigned int n, int *count);
void	ft_putstr_fdd(char *s, int fd, int *count);
int		ft_printf(const char *format, ...);

#endif
