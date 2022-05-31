/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:30:00 by amanasse          #+#    #+#             */
/*   Updated: 2022/05/25 14:14:56 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include "libft/libft.h"

// void ft_putchar(char c)
// {
// 	write (1, &c, 1);
// }


// int	count(int nb)
// {
// 	int	n;

// 	n = 0;
// 	if (nb == 0)
// 		return (1);
// 	if (nb == -2147483648)
// 		return (11);
// 	if (nb > -2147483648 && nb < 0)
// 	{
// 		nb = -nb;
// 		n++;
// 	}
// 	while (nb > 9)
// 	{
// 		nb = nb / 10;
// 		n++;
// 	}
// 	if (nb > 0 && nb < 10)
// 		n++;
// 	return (n);
// }

// int	count_hexa(long long nb)
// {
// 	long long	n;
// 	int i;

// 	n = nb;
// 	i = 0;
// 	if (n == 0)
// 		return (1);
// 	if (n < 0)
// 	{
// 		n  = n * -1;
// 		i++;
// 	}
// 	while (n)
// 	{
// 		n = n / 16;
// 		i++;
// 	}
// 	return (i);
// }
// int	ft_putnbr_d_i(int n)
// {
// 	int i;
// 	int	ok;

// 	ok = 0;
// 	i = count(n);
// 	if (n < 0)
// 	{
// 		n *= -1;
// 		ft_putchar('-');
// 	}
// 	if (n == -2147483648)
// 	{
// 		ok = 1;
// 		write(1, "2147483648", 10);
// 	}
// 	else if (n < 10)
// 	{
// 		ft_putchar(n + 48);
// 		ok = 1;
// 	}
// 	else
// 		ft_putnbr_d_i(n / 10);
// 	if (ok == 0)
// 		ft_putchar((n % 10) + 48);
// 	return (i);
// }

// int	ft_putnbr_u(unsigned int n)
// {
// 	int i;
// 	int	ok;

// 	ok = 0;
// 	i = count(n);
// 	if (n < 10)
// 	{
// 		ft_putchar(n + 48);
// 		ok = 1;
// 	}
// 	else
// 		ft_putnbr_u(n / 10);
// 	if (ok == 0)
// 		ft_putchar((n % 10) + 48);
// 	return (i);
// }


// int	ft_putnbr_base(long long nb, char *base)
// {
// 	if (nb >= ft_strlen(base))
// 	{
// 		ft_putnbr_base(nb / ft_strlen(base), base);
// 		ft_putnbr_base(nb % ft_strlen(base), base);
// 	}
// 	else 
// 		write (1, &base[nb], 1);
// }

// int	ft_putnbr_base_x_X(unsigned int nb, char *base)
// {
// 	if (nb >= ft_strlen(base))
// 	{
// 		ft_putnbr_base(nb / ft_strlen(base), base);
// 		ft_putnbr_base(nb % ft_strlen(base), base);
// 	}
// 	else 
// 		write (1, &base[nb], 1);
// }


size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

// int    ft_string(char *str)

// {
// 	write (1, str, ft_strlen(str));
// 	return (ft_strlen(str));
// }

// int ft_char(int c)
// {
// 	write (1, &c, 1);
// 	return (1);
// }


int ft_printf(const char *str, ...)
{
    int		i;
	int count;
	long long tmp;
    va_list ap;
    va_start(ap, str);

	count = 0;
	i = 0;
    while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 's')
				count += ft_string(va_arg(ap, char*));
			if (str[i + 1] == 'c')
				count += ft_char(va_arg(ap, int));
			if (str[i + 1] == 'd' || str[i + 1] == 'i')
				count += ft_putnbr_d_i(va_arg(ap, int));
			if (str[i + 1] == 'u')
				count += ft_putnbr_u(va_arg(ap, unsigned int));
			if (str[i + 1] == 'p')
			{
				tmp = (long long)va_arg(ap, void *);
				write (1, "0x", 2);
				count += 2;
				count += count_hexa(tmp);
				ft_putnbr_base(tmp, "0123456789abcdef");
			}
			if (str[i + 1] == 'x')
			{
				tmp = va_arg(ap, int);
				count += count_hexa(tmp);
				ft_putnbr_base_x_X(tmp, "0123456789abcdef");
			}
			if (str[i + 1] == 'X')
			{
				tmp = va_arg(ap, int);
				count += count_hexa(tmp);
				ft_putnbr_base_x_X(tmp, "0123456789ABCDEF");			
			}
			if (str[i + 1] == '%')
			{
				write (1, "%", 1);
				count++;
			}	
			i += 2;
		}
		if (str[i] == '\0')
			break ;
		write(1, &str[i], 1);
		count ++;
		i++;
	}
	va_end(ap);
	return (count);
}



int main()
{
	char c = 'a';
	char	*string = "HOLA";
	char c = 'a';
	char *ptrc = &c;
	int j = -122355421;
	unsigned int	i = -50;
	printf("nb de lettres = [%d]\n", ft_printf("[%p]", ptrc));
	printf("nb de lettres = [%d]\n",printf("[%p]", ptrc));
    // printf("coucou%s", string);

    return (0);
}