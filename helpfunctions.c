/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpfunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:43:58 by nalfonso          #+#    #+#             */
/*   Updated: 2025/05/10 18:49:43 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ftprintf.h"

int ft_putcharpf(char c)
{
	return (write (1, &c, 1));
}

int ft_putstrpf(char *str)
{
	int	count;

	if (!str)
		str = "(null)";
	count = 0;
	while (str[count])
		count += ft_putcharpf(&str[count]);
	return (count);
}

int ft_putnbrpf(int nb, int count)
{
	long nbr;
	
	nbr = nb;
	if (nbr < 0)
	{
		count += ft_putcharpf('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		count += ft_putnbrpf(nbr / 10, count);
		count += ft_putnbrpf(nbr % 10, count);
	}
	else
		count += ft_putcharpf(nbr + 48);
	return (count);
}

unsigned int ft_putunbrpf(unsigned nb, unsigned int counter)
{
	if (nb >= 10)
	{
		count +=  ft_putunbrpf(nb / 10, count);
		count +=  ft_putunbrpf(nb % 10, count);
	}
	else
		count += ft_putcharpf(nbr + 48);
	return (count);
}
		
