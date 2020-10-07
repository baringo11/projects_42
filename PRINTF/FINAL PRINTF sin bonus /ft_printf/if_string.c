/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:57:12 by jbaringo          #+#    #+#             */
/*   Updated: 2020/01/17 09:52:09 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_putstrn(char *s, int n)
{
	size_t i;

	if (s != NULL)
	{
		i = 0;
		while (s[i] && i < (size_t)n)
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}

void		ft_menos_str(char *str, t_variables **var)
{
	if ((*var)->p == 1)
		ft_putstrn(str, (*var)->precision);
	else
		ft_putstr_fd(str, 1);
	while ((*var)->width > 0)
	{
		ft_putchar_fd(' ', 1);
		(*var)->width--;
	}
}

void		ft_cero_str(char *str, t_variables **var)
{
	if ((*var)->p == 1)
		ft_putstrn(str, (*var)->precision);
	while ((*var)->width > 0)
	{
		ft_putchar_fd('0', 1);
		(*var)->width--;
	}
	if ((*var)->p == 0)
		ft_putstr_fd(str, 1);
}

void		cont_str(char *str, t_variables **var)
{
	while (str[(*var)->cont] != '\0')
		(*var)->cont++;
	if ((*var)->p == 1 && (*var)->precision < (*var)->cont)
		(*var)->cont = (*var)->precision;
	if ((*var)->length > (*var)->cont)
		(*var)->j += (*var)->length;
	else
		(*var)->j += (*var)->cont;
}

void		ifstring(char *str, t_variables **var)
{
	if (!str)
		str = "(null)";
	if ((*var)->p == 1 && (*var)->precision < (int)ft_strlen(str))
		(*var)->width = (*var)->length - (*var)->precision;
	else
		(*var)->width = (*var)->length - ft_strlen(str);
	if ((*var)->menos == 1)
		ft_menos_str(str, var);
	else if ((*var)->cero == 1)
		ft_cero_str(str, var);
	else
	{
		while ((*var)->width > 0)
		{
			ft_putchar_fd(' ', 1);
			(*var)->width--;
		}
		if ((*var)->p == 1)
			ft_putstrn(str, (*var)->precision);
		else
			ft_putstr_fd(str, 1);
	}
	cont_str(str, var);
	(*var)->i++;
}
