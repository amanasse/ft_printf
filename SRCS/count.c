/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:15:00 by amanasse          #+#    #+#             */
/*   Updated: 2022/05/31 12:15:30 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include "libft/libft.h"

int	count(int nb)
{
	int	n;

	n = 0;
	if (nb == 0)
		return (1);
	if (nb == -2147483648)
		return (11);
	if (nb > -2147483648 && nb < 0)
	{
		nb = -nb;
		n++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		n++;
	}
	if (nb > 0 && nb < 10)
		n++;
	return (n);
}