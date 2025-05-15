/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 22:28:52 by nalfonso          #+#    #+#             */
/*   Updated: 2025/05/13 22:53:15 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

# define CHEXADECIMAL "0123456789ABCDEF"
# define HEXADECIMAL "0123456789abcdef"

typedef unsigned long long	t_number;

int	ft_printf(const char *format, ...);

#endif