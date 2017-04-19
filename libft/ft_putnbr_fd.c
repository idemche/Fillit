/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araichyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:54:40 by araichyn          #+#    #+#             */
/*   Updated: 2016/11/25 12:34:37 by araichyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;
	int				darr[10];
	int				i;

	if (n == 0)
		ft_putchar_fd('0', fd);
	else
	{
		num = (n < 0) ? -n : n;
		if (n < 0)
			ft_putchar_fd('-', fd);
		i = 0;
		while (num)
		{
			darr[i++] = num % 10;
			num /= 10;
		}
		while (--i >= 0)
			ft_putchar_fd(darr[i] + '0', fd);
	}
}
