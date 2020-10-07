#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

int ft_cont_num(long n, int base_len)
{
	int i = 1;
	while (n >= base_len || n <= -base_len)
	{
		n /= base_len;
		i++;
	}
	return (i);
}

void ft_print_num(long n, int base_len, char *base)
{
	if (n >= base_len)
		ft_print_num(n / base_len, base_len, base);
	write(1, &base[n % base_len], 1);
}

int ft_printf(char *format, ...)
{
	char *base, *s;
	long num;
	int i = 0, j = 0, base_len = 0, ct = 0, neg = 0, zero = 0, space = 0, width = 0, precision = 0, p = 0;
	va_list ap;

	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ct = 0, neg = 0, zero = 0, space = 0, width = 0, precision = 0, p = 0;
			while (format[i] >= '0' && format[i] <= '9')
			{
				width = width * 10 + (format[i] - 48);
				i++;
			}
			if (format[i] == '.')
			{
				i++;
				p = 1;
				while (format[i] >= '0' && format[i] <= '9')
				{
					precision = precision * 10 + (format[i] - 48);
					i++;
				}
			}
			if (format[i] == 's')
			{
				s = va_arg(ap, char *);
				if (!s)
					s = "(null)";
				ct = ft_strlen(s);
			}
			else if (format[i] == 'x')
			{
				num = va_arg(ap, unsigned int);
				base = "0123456789abcdef";
				base_len = 16;
				ct = ft_cont_num(num, base_len);
			}
			else if (format[i] == 'd')
			{
				num = va_arg(ap, int);
				base = "0123456789";
				base_len = 10;
				ct = ft_cont_num(num, base_len);
				if (num < 0)
				{
					num = -num;
					neg = 1;
				}
			}
			if (p && precision > ct && format[i] != 's')
				zero = precision - ct;
			if (p && precision < ct && format[i] == 's')
				ct = precision;
			if (p && !precision && (format[i] == 's' || !num))
				ct = 0;
			space = width - ct - neg - zero;
			while (space-- > 0)
			{
				write(1, " ", 1);
				j++;
			}
			if (neg == 1)
			{
				write(1, "-", 1);
				j++;
			}
			while (zero-- > 0)
			{
				write(1, "0", 1);
				j++;
			}
			if (format[i] == 's')
				write(1, s, ct);
			else if (ct)
				ft_print_num(num, base_len, base);
			j += ct;
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
			j++;
		}
	}
	printf("final j: %d\n", j);
	va_end(ap);
	return (j);
}

int main()
{
	ft_printf("%d\n", 745845);
	int a = printf("%d\n", 745845);
	printf("a: %d\n", a);
}
