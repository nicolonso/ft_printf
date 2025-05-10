/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:30:32 by nalfonso          #+#    #+#             */
/*   Updated: 2025/05/10 17:15:57 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int ft_format(va_list args, char *format, size_t *count)
{
	if (args == 'c')
		return (ft_putchar_pf(args, count));
	else if (args == 's')
		return (ft_putstrpf(args, count));
	else if (args == 'p')
		return (ft_putnbrhexa(args,count));
	else if (args == 'd')
		return (ft_putnbrbase(args,count));
	else if (args == 'i')
		return (ft_putnbrbase(args,count));
	else if (args == 'u')
		return (ft_putnbrbase(args,count));
	else if (args == 'x')
		return (ft_putnbrhexa(args,count));
	else if (args == 'X')
		return (ft_putnbrhexa(args,count));
	else if (args == '%')
		return (ft_putcharpf('%'));
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
			ft_format(args, (char *)format, &count);
		}
		else
			ft_putchar_pf(format, count);
	}
	return (count);
}
