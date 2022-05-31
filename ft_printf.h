/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:26:23 by amanasse          #+#    #+#             */
/*   Updated: 2022/05/31 12:24:16 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"


size_t	ft_strlen(const char *s);
int		ft_string(char *str);
int		ft_char(int c);
int		ft_putnbr_base_x_X(unsigned int nb, char *base);
int		ft_putnbr_base(long long nb, char *base);
int		ft_putnbr_u(unsigned int n);
int		ft_putnbr_d_i(int n);
int		count_hexa(long long nb);
int		count(int nb);
void	ft_putchar(char c);

#endif