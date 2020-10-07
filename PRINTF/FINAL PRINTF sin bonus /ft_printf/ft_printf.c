/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:13:50 by jbaringo          #+#    #+#             */
/*   Updated: 2020/01/17 11:24:41 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *s, ...)
{
	t_variables	*var;

	var = set_init((char*)s);
	va_start(var->ap, s);
	find_percent((char*)s, &var);
	va_end(var->ap);
	free(var);
	return (var->j);
}
