/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:11:42 by jbaringo          #+#    #+#             */
/*   Updated: 2020/01/16 13:39:24 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	find_percent(char *s, t_variables **var)
{
	while (s[(*var)->i] != '\0')
	{
		if (s[(*var)->i] == '%')
		{
			(*var)->i++;
			check_flag(s, var);
			set_to_cero(var);
		}
		else
		{
			ft_putchar_fd(s[(*var)->i], 1);
			(*var)->i++;
			(*var)->j++;
		}
	}
}
