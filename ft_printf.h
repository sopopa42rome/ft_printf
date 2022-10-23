/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:02:18 by sopopa            #+#    #+#             */
/*   Updated: 2022/10/23 09:45:19 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int ft_print_char(int c);
int ft_print_str( char *str);
int check_format(va_list argp, const char format);
int ft_printf(const char *str, ...);
int ft_print_pointaddress(unsigned long long ptr);
void ft_print_hex(unsigned long ptr);
int ft_print_len(unsigned long ptr);

#endif