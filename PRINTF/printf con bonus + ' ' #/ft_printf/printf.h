/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:19:02 by jbaringo          #+#    #+#             */
/*   Updated: 2020/01/21 15:07:23 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stddef.h>
# include <fcntl.h>
# include <string.h>
# include <ctype.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

# define HEX "0123456789abcdef"

typedef __UINTPTR_TYPE__	t_ptr;

typedef struct		s_printf
{
	char			*str;
	int				i;
	int				j;
	int				cont;
	va_list			ap;

	int				width;
	int				menos;
	int				mas;
	int				cero;
	int				length;
	int				precision;
	int				p;
	int				digit;
	int				ptr;
	int				espacio;
	int				hastag;
}					t_variables;

int					ft_printf(const char *s, ...);
t_variables			*set_init(char	*s);
void				set_to_cero(t_variables **var);
void				find_percent(char *s, t_variables **var);
void				check_flag(const char *s, t_variables **var);
void				check_length(const char *s, t_variables **var);
void				check_precision(const char *s, t_variables **var);
void				ifint(int n, t_variables **var);
void				ft_menos(int n, t_variables **var);
void				ft_precision_cero(t_variables **var);
void				ifchar(char c, t_variables **var);
void				ifunsint(int n, t_variables **var);
void				ifstring(char *str, t_variables **var);
void				ifhexadecimal(int n, t_variables **var);
void				ifpercent(t_variables **var);
void				ifpointer(t_ptr n, t_variables **var);
void				ifhexadecimal_ptr(unsigned long n, t_variables **var);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr_fd(int n, int fd, t_variables **var);
void				ft_putstr_fd(char *s, int fd);
int					ft_isdigit(int c);
char				*ft_strchr(const char *s, int c);
unsigned long		ft_strlen(const char *s);

#endif
