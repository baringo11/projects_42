/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_length_precision.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 10:23:40 by jbaringo          #+#    #+#             */
/*   Updated: 2020/01/17 11:24:19 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	check_length_2(t_variables **var)
{
	int n;

	(*var)->digit = 1;
	n = va_arg((*var)->ap, int);
	if (n < 0)
	{
		n = n * -1;
		(*var)->menos = 1;
	}
	(*var)->length = n;
}

void	check_precision_2(t_variables **var)
{
	int n;

	n = va_arg((*var)->ap, int);
	if (n < 0)
	{
		n = n * -1;
		(*var)->p = 0;
		(*var)->menos = 1;
	}
	else
		(*var)->precision = n;
	(*var)->i++;
}

void	check_length(const char *s, t_variables **var)
{
	char	*num;

	if (s[(*var)->i] == '+' && (*var)->i++)
		(*var)->mas = 1;
	if (ft_isdigit(s[(*var)->i]))
		(*var)->digit = 1;
	while (s[(*var)->i] == '0' && (*var)->i++)
		(*var)->cero = 1;
	if (s[(*var)->i] == '+' && (*var)->i++)
		(*var)->mas = 1;
	if (s[(*var)->i] == '-' && (*var)->i++)
	{
		(*var)->cero = 0;
		(*var)->menos = 1;
	}
	if (s[(*var)->i] == '*' && (*var)->i++)
		check_length_2(var);
	while (ft_isdigit(s[(*var)->i]))
	{
		num = ft_strchr("0123456789", s[(*var)->i]);
		(*var)->length += (num[0] - 48);
		if (ft_isdigit(s[((*var)->i) + 1]))
			(*var)->length *= 10;
		(*var)->i++;
	}
}

void	check_precision(const char *s, t_variables **var)
{
	char	*num;

	(*var)->cero = 0;
	(*var)->p = 1;
	(*var)->i++;
	if (s[(*var)->i] == '*')
		check_precision_2(var);
	while (ft_isdigit(s[(*var)->i]))
	{
		num = ft_strchr("0123456789", s[(*var)->i]);
		(*var)->precision += (num[0] - 48);
		if (ft_isdigit(s[((*var)->i) + 1]))
			(*var)->precision *= 10;
		(*var)->i++;
	}
}
