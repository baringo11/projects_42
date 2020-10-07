/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <jbaringo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:25:06 by jbaringo          #+#    #+#             */
/*   Updated: 2020/02/10 13:43:15 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

size_t	ft_strlen(char *s)
{
	size_t	len;
	len = 0;
	while (s[len])
		len++;
	return (len);
}

int		ft_counter(long long num, int base_len)
{
	int		ct;

	ct = 1;
	while (num >= base_len || num <= -base_len)
	{
		num = num / base_len;
		ct++;
	}
	return (ct);	
}

void	ft_putnum(long long num, int base_len, char *base)
{
	if (num >= base_len)
		ft_putnum(num / base_len, base_len, base);
	write(1, &base[num % base_len], 1);
}

int		ft_printf(char	*fromat, ...)
{
	va_list	ap;
	char	*s, *base;
	long	num;
	int		i = 0, ct = 0, neg = 0, zero = 0, space = 0, width = 0, precision = 0, p = 0, j = 0, base_len = 0;

	va_start(ap, fromat);
	while (fromat[i])
	{
		if (fromat[i] == '%')
		{
			i++;
			ct = 0, neg = 0, zero = 0, space = 0, width = 0, precision = 0, p = 0;
			while (fromat[i] >= '0' && fromat[i] <= '9')
			{
				width = width * 10 + (fromat[i] - 48);
				i++;
			}
			if (fromat[i] == '.')
			{
				i++;
				p = 1;
				while (fromat[i] >= '0' && fromat[i] <= '9')
				{
					precision = precision * 10 + (fromat[i] - 48);
					i++;
				}
			}
			if (fromat[i] == 's')
			{
				s = va_arg(ap, char *);
				if (!s)
					s = "(null)";
				ct = ft_strlen(s);
			}
			else if (fromat[i] == 'x')
			{
				num = va_arg(ap, unsigned int);
				base = "0123456789abcdef";
				base_len = 16;
				ct = ft_counter(num, base_len);
			}
			else if (fromat[i] == 'd')
			{
				num = va_arg(ap, int);
				base = "0123456789";
				base_len = 10;
				ct = ft_counter(num, base_len);
				if (num < 0)
				{
					num = -num;
					neg = 1;
				}
			}
			if (p && precision > ct && fromat[i] != 's')
				zero = precision - ct;
			if (p && precision < ct && fromat[i] == 's')
				ct = precision;
			if (p && !precision && (fromat[i] == 's' || !num))
				ct = 0;
			space = width - zero - ct - neg;
			while (space-- > 0)
			{
				write(1, " ", 1);
				j++;
			}
			if (neg)
			{
				write(1, "-", 1);
				j++;
			}
			while (zero-- > 0)
			{
				write(1, "0", 1);
				j++;
			}
			if (fromat[i] == 's')
				write(1, s, ct);
			else if (ct)
				ft_putnum(num, base_len, base);
			j += ct;
			i++;
		}
		else
		{
			write(1, &fromat[i], 1);
			j++;
			i++;
		}
	}
	printf("final j: %d\n", j);
	va_end(ap);
	return (j);
}

int main()
{
	int		i;
	int		j;


	ft_printf("%.3d\n", 0);
	i = printf("%.3d\n", 0);
	printf("a: %d\n", i);

	/* i = printf("ft: jaja[%30.10s] [%.3s] [%.30s] [%20s] [%30.10d] [%30d %.10d] [%30.10d] [%5.0d] [%30.10x] [%30x] [%.10x] [%30.10x] [%5.0x]\n", "jaime que", "jaime", "jaime", "jaime", 30, 30 , 303030, -303030, 0, 30, 30 , 303030, -303030, 0);
	printf("ft: %d\n", i);
	i = ft_printf("sy: jaja[%30.10s] [%.3s] [%.30s] [%20s] [%30.10d] [%30d %.10d] [%30.10d] [%5.0d] [%30.10x] [%30x] [%.10x] [%30.10x] [%5.0x]\n", "jaime que", "jaime", "jaime", "jaime", 30, 30 , 303030, -303030, 0, 30, 30 , 303030, -303030, 0);
	printf("sy: %d\n", i);
	i = printf("[%6d], [%10.3s]\n", -2147483648, "");
	printf("ft: %d\n", i);
	j = ft_printf("[%6d], [%10.3s]\n", -2147483648, "");
	printf("sy: %d\n", j); */
}
