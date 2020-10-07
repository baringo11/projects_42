/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:13:50 by jbaringo          #+#    #+#             */
/*   Updated: 2020/01/21 15:32:25 by jbaringo         ###   ########.fr       */
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
	//printf("final j: %d\n", var->j);
	free(var);
	return (var->j);
}
