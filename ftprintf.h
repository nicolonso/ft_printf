/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:42:09 by nalfonso          #+#    #+#             */
/*   Updated: 2025/05/10 18:50:13 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRNF_H
# define LIBPRNF_H

#include <stdarg.h>
#include <unistd.h>

//GLOBAL VARIABLES
#define CHEXADECIMAL = "0123456789ABCDEF"
#define HEXADECIMAL = "0123456789abcdef"

int	ft_printf(const char *, ...);

//HELPER FUNCTIONS
int ft_putcharpf(char c);
int ft_putstrpf(char *str);
int ft_putnbrpf(int nb, int count);



#endif