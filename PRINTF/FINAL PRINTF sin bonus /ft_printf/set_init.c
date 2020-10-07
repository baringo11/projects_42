/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:21:16 by jbaringo          #+#    #+#             */
/*   Updated: 2020/01/16 13:16:59 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_variables		*set_init(char *s)
{
	t_variables	*var;

	if (!(var = malloc(sizeof(var))))
		return (NULL);
	var->str = s;
	var->i = 0;
	var->j = 0;
	var->cont = 0;
	var->cero = 0;
	var->length = 0;
	var->menos = 0;
	var->mas = 0;
	var->precision = 0;
	var->p = 0;
	var->digit = 0;
	var->width = 0;
	var->ptr = 0;
	return (var);
}

void			set_to_cero(t_variables **var)
{
	(*var)->cont = 0;
	(*var)->cero = 0;
	(*var)->length = 0;
	(*var)->menos = 0;
	(*var)->mas = 0;
	(*var)->precision = 0;
	(*var)->p = 0;
	(*var)->digit = 0;
	(*var)->width = 0;
	(*var)->ptr = 0;
}
