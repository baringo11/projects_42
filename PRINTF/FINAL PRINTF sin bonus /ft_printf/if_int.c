/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:05:58 by jbaringo          #+#    #+#             */
/*   Updated: 2020/01/17 09:32:18 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		get_num_size(int nb)
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

void			ft_cero(int n, t_variables **var)
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
	while ((*var)->width > 0)
	{
		ft_putchar_fd('0', 1);
		(*var)->width--;
	}
	ft_putnbr_fd(n, 1);
}

void			ft_digit(int n, t_variables **var)
{
	if (n < 0)
		(*var)->width--;
	else if ((*var)->mas == 1)
		(*var)->width--;
	while ((*var)->width > 0)
	{
		ft_putchar_fd(' ', 1);
		(*var)->width--;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = n * -1;
	}
	else if ((*var)->mas == 1)
		ft_putchar_fd('+', 1);
	while (((*var)->precision - get_num_size(n)) > 0)
	{
		ft_putchar_fd('0', 1);
		(*var)->precision--;
	}
	ft_putnbr_fd(n, 1);
}

void			cont_int(int n, t_variables **var)
{
	int num_size;

	num_size = get_num_size(n);
	if (n < 0)
		num_size++;
	(*var)->width = (*var)->length - (get_num_size(n));
	if ((*var)->p == 1 && (*var)->precision > get_num_size(n))
		(*var)->width -= (*var)->precision - get_num_size(n);
	if (n == 0 && (*var)->p == 1 &&
				(*var)->precision == 0 && (*var)->length == 0)
		(*var)->j += 0;
	else if ((*var)->length > num_size && (*var)->length > (*var)->precision)
		(*var)->j += (*var)->length;
	else if ((*var)->p == 1 && (*var)->precision > num_size)
	{
		(*var)->j += (*var)->precision;
		if (n < 0)
			(*var)->j++;
	}
	else
		(*var)->j += num_size;
}

void			ifint(int n, t_variables **var)
{
	cont_int(n, var);
	if (!(n == 0 && (*var)->p == 1 && (*var)->precision == 0))
	{
		if ((*var)->menos == 1)
			ft_menos(n, var);
		else if ((*var)->cero == 1)
			ft_cero(n, var);
		else if ((*var)->digit == 1 || (*var)->mas == 1 || (*var)->p == 1)
			ft_digit(n, var);
		else
			ft_putnbr_fd(n, 1);
	}
	else
		ft_precision_cero(var);
	(*var)->i++;
}
