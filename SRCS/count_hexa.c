/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:14:16 by amanasse          #+#    #+#             */
/*   Updated: 2022/05/31 12:14:30 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include "libft/libft.h"

int	count_hexa(long long nb)
{
	long long	n;
	int i;

	n = nb;
	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n  = n * -1;
		i++;
	}
	while (n)
	{
		n = n / 16;
		i++;
	}
	return (i);
}