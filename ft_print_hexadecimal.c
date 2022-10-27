/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:45:41 by sopopa            #+#    #+#             */
/*   Updated: 2022/10/27 21:05:24 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int ft_print_hexadecimal(unsigned long long ptr, const char format)
{
	int print_lenght;

	print_lenght = 0;
	if (ptr == 0)
		write (1, "0", 1);
	else
	{
		ft_check_format(ptr, format);
		print_lenght += ft_print_len(ptr);
	}
	return (print_lenght);
}

void ft_check_format(unsigned long ptr, const char format)
{   
	if (ptr >= 16)
	{	
		ft_check_format(ptr / 16, format);
		ft_check_format(ptr % 16, format);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd((ptr + '0'), 1);
		else
		{
			if (format == 'x')
			ft_putchar_fd((ptr - 10 + 'a'), 1);
		    if (format == 'X')
			ft_putchar_fd((ptr - 10 + 'A'), 1);
		}
	}
}
