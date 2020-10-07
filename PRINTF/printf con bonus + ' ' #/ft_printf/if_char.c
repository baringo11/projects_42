/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:40:06 by jbaringo          #+#    #+#             */
/*   Updated: 2020/01/16 13:04:56 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ifchar(char c, t_variables **var)
{
	(*var)->width = (*var)->length - 1;
	if ((*var)->menos == 1)
	{
		ft_putchar_fd(c, 1);
		while ((*var)->width > 0)
		{
			ft_putchar_fd(' ', 1);
			(*var)->width--;
		}
	}
	else
	{
		while ((*var)->width > 0)
		{
			ft_putchar_fd(' ', 1);
			(*var)->width--;
		}
		ft_putchar_fd(c, 1);
	}
	(*var)->i++;
	if ((*var)->length != 0)
		(*var)->j += (*var)->length;
	else
		(*var)->j++;
}
