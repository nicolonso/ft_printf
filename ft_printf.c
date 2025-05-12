/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:30:32 by nalfonso          #+#    #+#             */
/*   Updated: 2025/05/12 22:05:54 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int ft_putcharpf(char c)
{
	return(write (1, &c, 1));
}
int ft_putstrpf(char *str)
{
	int count;

	count = 0;
	if (!str)
		str = "(null)";
	count += ft_putcharpf(*str++);
	return (count);
}

static int ft_putbases(number nbr,int len, char *base)
{
	int count;

	count = 0;
	if (nbr >= (unsigned long)len)
	{
		count += ft_putbases(nbr / len, len ,base);
		count += ft_putbases(nbr % len, len ,base);
	}
	else
		count += ft_putcharpf((char *)nbr + *base);
	return (count);
}
static int ft_baseten(long nbr)
{
	int count;

	count = 0;
	if (nbr < 0)
	{
		count += ft_putcharpf('-');
		nbr = -nbr;
	}
	count += ft_putbases(nbr, 10, HEXADECIMAL);
	return (count);
}

int ft_format(va_list args, char *format, size_t *count)
{
	if (*format == 'c')
		return (ft_putcharpf(va_arg(args, char)));
	else if (*format == 's')
		return (ft_putstrpf(va_arg(args, char *)));
	else if (*format == 'p')
	{
		if (!format)
		{
			format = "(nil)";
			ft_putcharpf(*format++);
		}
		ft_putstrpf("0x");
		return (ft_putbases(va_arg(args,void *) , 16, HEXADECIMAL));
	}
	else if (*format == 'd')
		return (ft_baseten(va_arg(args, int)));
	else if (*format == 'i')
		return (ft_baseten(va_arg(args, int)));
	else if (*format == 'u')
		return (ft_baseten(va_arg(args, unsigned int)));
	else if (*format == 'x')
		return (ft_putbases(va_arg(args,unsigned int) , 16, HEXADECIMAL));
	else if (*format == 'X')
		return (ft_putbases(va_arg(args,unsigned int) , 16, CHEXADECIMAL));
	else if (*format == '%')
		return (ft_putcharpf('%'));
	return (0);
}

int ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	count;

	count = 0;
	va_start (args, format);
	while (*format)
	{
		if(*format == '%')
		{
			format++;
			count += ft_format(args, (char *)format, &count);
		}
		else
			count += ft_putchar_pf(format, count);
		format++;
	}
	va_end(args);
	return (count);
}

int main()
{
	ft_printf("Hello baby");
	return (0);
}