/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_int_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:19:51 by jbaringo          #+#    #+#             */
/*   Updated: 2020/01/17 09:17:27 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		get_num_size_(int nb)
{
	unsigned int	size;

	size = 0;
	if (nb < 0)
		nb = nb * -1;
	while (nb >= 10)
	{
		nb /= 10;
		++size;
	}
	if (nb == -2147483648)
		size = 9;
	return (size + 1);
}

void			ft_putnbr_minint(int n, int fd)
{
	unsigned int	nbr;

	if (n < 0)
		nbr = (unsigned int)(n * -1);
	else
		nbr = (unsigned int)n;
	if (nbr >= 10)
		ft_putnbr_minint(nbr / 10, fd);
	ft_putchar_fd((char)(nbr % 10 + 48), fd);
}

void			ft_precision_cero(t_variables **var)
{
	int a;

	a = 0;
	(*var)->width++;
	if ((*var)->mas == 1 && ((*var)->width <= 0 || (*var)->menos == 1))
	{
		(*var)->width--;
		ft_putchar_fd('+', 1);
	}
	else if ((*var)->mas == 1 && (*var)->width > 0)
	{
		a = 1;
		(*var)->width--;
	}
	while ((*var)->width > 0)
	{
		ft_putchar_fd(' ', 1);
		(*var)->width--;
	}
	if (a == 1)
		ft_putchar_fd('+', 1);
}

void			ft_menos(int n, t_variables **var)
{
	if (n < 0)
	{
		(*var)->width--;
		n = n * -1;
		ft_putchar_fd('-', 1);
	}
	else if ((*var)->mas == 1)
	{
		(*var)->width--;
		ft_putchar_fd('+', 1);
	}
	while (((*var)->precision - get_num_size_(n)) > 0)
	{
		ft_putchar_fd('0', 1);
		(*var)->precision--;
	}
	ft_putnbr_minint(n, 1);
	while ((*var)->width > 0)
	{
		ft_putchar_fd(' ', 1);
		(*var)->width--;
	}
}
