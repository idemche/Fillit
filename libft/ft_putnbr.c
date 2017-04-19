/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araichyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:54:19 by araichyn          #+#    #+#             */
/*   Updated: 2016/11/25 17:51:19 by araichyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	num;
	int				darr[10];
	int				i;

	if (n == 0)
		ft_putchar('0');
	else
	{
		num = (n < 0) ? -n : n;
		if (n < 0)
			ft_putchar('-');
		i = 0;
		while (num)
		{
			darr[i++] = num % 10;
			num /= 10;
		}
		while (--i >= 0)
			ft_putchar(darr[i] + '0');
	}
}
