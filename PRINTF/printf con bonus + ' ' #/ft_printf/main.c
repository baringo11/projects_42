/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 08:54:23 by jbaringo          #+#    #+#             */
/*   Updated: 2020/01/22 15:31:02 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "set_init.c"
#include "ft_printf.c"
#include "find_percent.c"
#include "check_flag.c"
#include "check_length_precision.c"
#include "if_int.c"
#include "if_int_2.c"
#include "if_string.c"
#include "if_char.c"
#include "if_hexadecimal.c"
#include "if_unsigned.c"
#include "if_percent.c"
#include "if_pointer.c"
#include "print_ptr.c"

#include "ft_strlen.c"
#include "ft_putchar_fd.c"
#include "ft_putnbr_fd.c"
#include "ft_putstr_fd.c"
#include "ft_strchr.c"
#include "ft_isdigit.c"

int		main(void)
{
 	int a;
/*	void *pt = &a;
	
	ft_printf("%02.9p\n", 1234564545);
	a = printf("%2.9p\n", 1234564545); */

	ft_printf("%50.40d\n", 34);
	a = printf("%50.40d\n", 34);
	printf("a: %d\n", a);
}
