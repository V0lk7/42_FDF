/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:40:03 by jduval            #+#    #+#             */
/*   Updated: 2022/11/24 10:44:53 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

int		ft_printf(const char *format, ...);
int		ft_putchar_printf(char c, int fd);
int		ft_putstr_printf(char *s, int fd);
int		ft_nbrlen(long unsigned int nbr, int base);
int		ft_prep(long int nbr, int fd, int len, int base);
int		ft_print_p(long unsigned nbr, int fd, int len);
int		ft_putnbr_hex(unsigned int nbr, char c, int fd, int len);
#endif
