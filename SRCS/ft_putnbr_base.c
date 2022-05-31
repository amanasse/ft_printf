/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:05:13 by amanasse          #+#    #+#             */
/*   Updated: 2022/05/31 19:26:22 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(long long nb, char *base)
{
	if (nb >= (long long)ft_strlen(base))
	{
		ft_putnbr_base(nb / (long long)ft_strlen(base), base);
		ft_putnbr_base(nb % (long long)ft_strlen(base), base);
	}
	else
		write (1, &base[nb], 1);
}
