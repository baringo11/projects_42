/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 12:53:36 by jbaringo          #+#    #+#             */
/*   Updated: 2020/01/21 14:43:46 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr_fd(int n, int fd, t_variables **var)
{
	unsigned int	nbr;

	if ((*var)->espacio == 1 && (*var)->mas == 0 && (*var)->cero == 0 && n >= 0)
	{
		ft_putchar_fd(' ', fd);
		(*var)->espacio = 0;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = (unsigned int)(n * -1);
		(*var)->espacio = 0;
	}
	else
		nbr = (unsigned int)n;
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd, var);
	ft_putchar_fd((char)(nbr % 10 + 48), fd);
}
