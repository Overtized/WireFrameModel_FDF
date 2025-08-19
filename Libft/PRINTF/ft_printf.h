/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 09:08:06 by mchanlia          #+#    #+#             */
/*   Updated: 2025/05/10 09:08:06 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>
# include <fcntl.h>

// basics funct
int		ft_printf(int fd, const char *format, ...);
int		ft_putconverted(const char *format, va_list ap, int fd);
// srces
int		ft_putchar_int(int c, int fd);
int		ft_putnbr_base_ulong(unsigned long n, char *base, int fd);
int		ft_putnbr_base(int n, char *base, int fd);
int		ft_putnbr(int n, int fd);
int		ft_putstr_int( const char *format, int fd);
int		ft_putvp(void *ptr, char *base, int fd);
int		ft_isdigit(int c);
int		ft_putnbr_base_uint(unsigned int n, char *base, int fd);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
#endif