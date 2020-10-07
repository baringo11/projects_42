/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:34:23 by jbaringo          #+#    #+#             */
/*   Updated: 2020/01/16 13:49:23 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	check_flag(const char *s, t_variables **var)
{
	if (s[(*var)->i] == '0' || s[(*var)->i] == '-' ||
			s[(*var)->i] == '+' || ft_isdigit(s[(*var)->i]) ||
									s[(*var)->i] == '*')
		check_length(s, var);
	if (s[(*var)->i] == '.')
		check_precision(s, var);
	if (s[(*var)->i] == 'd' || s[(*var)->i] == 'i')
		ifint(va_arg((*var)->ap, int), var);
	else if (s[(*var)->i] == 's')
		ifstring(va_arg((*var)->ap, char*), var);
	else if (s[(*var)->i] == 'c')
		ifchar(va_arg((*var)->ap, int), var);
	else if (s[(*var)->i] == 'x' || s[(*var)->i] == 'X')
		ifhexadecimal(va_arg((*var)->ap, int), var);
	else if (s[(*var)->i] == 'u')
		ifunsint(va_arg((*var)->ap, int), var);
	else if (s[(*var)->i] == '%')
		ifpercent(var);
	else if (s[(*var)->i] == 'p')
		ifpointer(((t_ptr)(va_arg((*var)->ap, void*))), var);
	return ;
}
