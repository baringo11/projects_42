/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 11:32:03 by jbaringo          #+#    #+#             */
/*   Updated: 2020/01/16 13:10:52 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_menos_percent(t_variables **var)
{
	ft_putchar_fd('%', 1);
	while ((*var)->width > 0)
	{
		ft_putchar_fd(' ', 1);
		(*var)->width--;
	}
}

void	ft_cero_percent(t_variables **var)
{
	while ((*var)->width > 0)
	{
		ft_putchar_fd('0', 1);
		(*var)->width--;
	}
	ft_putchar_fd('%', 1);
}

void	ifpercent(t_variables **var)
{
	(*var)->width = (*var)->length - 1;
	if ((*var)->menos == 1)
		ft_menos_percent(var);
	else if ((*var)->cero == 1)
		ft_cero_percent(var);
	else
	{
		while ((*var)->width > 0)
		{
			ft_putchar_fd(' ', 1);
			(*var)->width--;
		}
		ft_putchar_fd('%', 1);
	}
	if ((*var)->length != 0)
		(*var)->j += (*var)->length;
	else
		(*var)->j++;
	(*var)->i++;
}
