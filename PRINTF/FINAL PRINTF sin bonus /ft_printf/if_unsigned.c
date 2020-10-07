/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:26:34 by jbaringo          #+#    #+#             */
/*   Updated: 2020/01/17 10:09:04 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	cont_unsig(unsigned int n, t_variables **var)
{
	if (!(n == 0 && (*var)->p == 1 && (*var)->precision == 0))
		(*var)->cont++;
	while (n >= 10)
	{
		n /= 10;
		(*var)->cont++;
	}
	if ((*var)->length != 0 && (*var)->length > (*var)->cont)
		(*var)->j += (*var)->length;
	else if ((*var)->p == 1 && (*var)->precision > (*var)->cont)
		(*var)->j += (*var)->precision;
	else
		(*var)->j += (*var)->cont;
	(*var)->width = (*var)->length - (*var)->cont;
	if ((*var)->p == 1 && (*var)->precision > (*var)->cont)
		(*var)->width -= (*var)->precision - (*var)->cont;
}

void	print_unsig(unsigned int n, t_variables **var)
{
	if (n >= 10)
		print_unsig(n / 10, var);
	ft_putchar_fd((n % 10 + 48), 1);
}

void	ft_menos_unsig(int n, t_variables **var)
{
	while (((*var)->precision - (*var)->cont) > 0)
	{
		ft_putchar_fd('0', 1);
		(*var)->precision--;
	}
	print_unsig(n, var);
	while ((*var)->width > 0)
	{
		ft_putchar_fd(' ', 1);
		(*var)->width--;
	}
}

void	ft_digit_cero_unsig(int n, t_variables **var)
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
	print_unsig(n, var);
}

void	ifunsint(int n, t_variables **var)
{
	cont_unsig(n, var);
	if (!(n == 0 && (*var)->p == 1 && (*var)->precision == 0))
	{
		if ((*var)->menos == 1)
			ft_menos_unsig(n, var);
		else if ((*var)->digit == 1 || (*var)->p == 1 || (*var)->cero == 1)
			ft_digit_cero_unsig(n, var);
		else
			print_unsig(n, var);
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
