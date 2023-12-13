/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:35:01 by abakhcha          #+#    #+#             */
/*   Updated: 2023/12/11 14:20:58 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list ap, char str)
{
	int	count;

	count = 0;
	if (str == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (str == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (str == 'd' || str == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (str == 'X' || str == 'x')
		count += ft_puthexa(va_arg(ap, unsigned int), str);
	else if (str == 'u')
		count += ft_putunsigned(va_arg(ap, unsigned int));
	else if (str == 'p')
	{
		count += ft_putstr("0x");
		count += ft_putpointer((unsigned long)va_arg(ap, void *));
	}
	else if (str == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		counter;
	int		i;

	i = 0;
	va_start(ap, str);
	counter = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_strchr("cspdiuxX%", str[i + 1]))
				counter += ft_format(ap, str[++i]);
		}
		else
			counter += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (counter);
}
