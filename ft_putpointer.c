/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:46:33 by abakhcha          #+#    #+#             */
/*   Updated: 2023/12/10 15:40:59 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(unsigned long n)
{
	char	c;
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (n > 15)
		count += ft_putpointer(n / 16);
	if ((n % 16) >= 10 && (n % 16) <= 15)
		c = (n % 16) - 10 + 'a';
	else
		c = (n % 16) + '0';
	count += ft_putchar(c);
	return (count);
}
