/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:55:54 by jbaringo          #+#    #+#             */
/*   Updated: 2020/01/16 13:27:50 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	cont_hex(unsigned int n, t_variables **var)
{
	if (!(n == 0 && (*var)->p == 1 && (*var)->precision == 0))
		(*var)->cont++;
	while (n > 16)
	{
		n /= 16;
		(*var)->cont++;
	}
	if ((*var)->length != 0 && (*var)->length > (*var)->cont)
		(*var)->j += (*var)->length;
	else if ((*var)->p == 1 && (*var)->precision > (*var)->cont)
		(*var)->j += (*var)->precision;
	else
		(*var)->j += (*var)->cont;
	(*var)->width += (*var)->length - (*var)->cont;
	if ((*var)->p == 1 && (*var)->precision > (*var)->cont)
		(*var)->width -= (*var)->precision - (*var)->cont;
}

void	print_hex(unsigned int n, t_variables **var)
{
	if (n >= 16)
		print_hex(n / 16, var);
	if ((*var)->str[(*var)->i] == 'X')
	{
		if (n % 16 > 9)
			ft_putchar_fd((HEX[n % 16] - 32), 1);
		else
			ft_putchar_fd((HEX[n % 16]), 1);
	}
	else
		ft_putchar_fd(HEX[n % 16], 1);
}

void	ft_menos_hex(int n, t_variables **var)
{
	while (((*var)->precision - (*var)->cont) > 0)
	{
		ft_putchar_fd('0', 1);
		(*var)->precision--;
	}
	print_hex(n, var);
	while ((*var)->width > 0)
	{
		ft_putchar_fd(' ', 1);
		(*var)->width--;
	}
}

void	ft_digit_cero_hex(int n, t_variables **var)
{
	while ((*var)->width > 0)
	{
		if ((*var)->cero == 1)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		(*var)->width--;
	}
	while (((*var)->precision - (*var)->cont) > 0)
	{
		ft_putchar_fd('0', 1);
		(*var)->precision--;
	}
	print_hex(n, var);
}

void	ifhexadecimal(int n, t_variables **var)
{
	cont_hex(n, var);
	if (!(n == 0 && (*var)->p == 1 && (*var)->precision == 0))
	{
		if ((*var)->menos == 1)
			ft_menos_hex(n, var);
		else if ((*var)->digit == 1 || (*var)->p == 1 || (*var)->cero == 1)
			ft_digit_cero_hex(n, var);
		else
			print_hex(n, var);
	}
	else
	{
		while ((*var)->width > 0)
		{
			ft_putchar_fd(' ', 1);
			(*var)->width--;
		}
	}
	(*var)->i++;
}
