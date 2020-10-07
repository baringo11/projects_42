/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:36:10 by jbaringo          #+#    #+#             */
/*   Updated: 2020/01/16 13:16:06 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_precision_ptr(t_variables **var)
{
	(*var)->length -= 2;
	while ((*var)->length > 0)
	{
		ft_putchar_fd(' ', 1);
		(*var)->length--;
		(*var)->j++;
	}
	ft_putstr_fd("0x", 1);
	while ((*var)->precision > 0)
	{
		ft_putchar_fd('0', 1);
		(*var)->precision--;
		(*var)->j++;
	}
	(*var)->i++;
	(*var)->j += 2;
}

void	ifpointer(t_ptr n, t_variables **var)
{
	(*var)->ptr = 1;
	if (n)
	{
		(*var)->cont += 2;
		ifhexadecimal_ptr(n, var);
	}
	else
	{
		if ((*var)->p == 1)
			ft_precision_ptr(var);
		else
			ifstring("0x0", var);
	}
}
