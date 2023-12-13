/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:09:24 by abakhcha          #+#    #+#             */
/*   Updated: 2023/12/09 18:25:25 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int n, char format)
{
	int		count;
	char	c;

	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n *= -1;
	}
	if (n > 15)
		count += ft_puthexa((n / 16), format);
	if ((n % 16) >= 10 && (n % 16) <= 15)
	{
		if (format == 'x')
			c = (n % 16) - 10 + 'a';
		else
			c = (n % 16) - 10 + 'A';
	}
	else
		c = (n % 16) + '0';
	count += ft_putchar(c);
	return (count);
}
