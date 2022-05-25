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

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

void    ft_string(char *str, ...)

{
	char	*s;
    va_list ap;
    va_start(ap, str);


	s = va_arg(ap, char*);


	write (1, s, ft_strlen(s));


	va_end(ap);




}




int ft_printf(const char *str, ...)
{
    // char	*s;
	char 	c;
    int		i;

    va_list ap;
    va_start(ap, str);
	
    i = 0;
	// s = va_arg(ap, char*);
	c = va_arg(ap, int);
    
	// c = va_arg(ap, int);
    while (str[i] && str[i] != '%')
		i++;
	write(1, str, i);
    str = str + i;
	if (str[1] == 's')
		ft_string(va_arg(ap, char*));


	
	if (str[1] == 'c')
		write (1, &c, 1);

    
	


       


	va_end(ap);
	return (0);

}



int main()
{
	// char c = 'a';
	char	*string = "HOLA";
    ft_printf("couco%ssu", string);
    printf("\n");
    printf("couco%ssu", string);


    return (0);



}