/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointaddress.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 02:35:43 by sopopa            #+#    #+#             */
/*   Updated: 2022/10/23 10:35:27 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int ft_print_pointaddress(unsigned long long ptr)
{
	int print_lenght;

	print_lenght = 0;
	write(1, "0x", 2);
	if (ptr == 0)
		write (1, "0", 1);
	else
	{
		ft_print_hex(ptr);
		print_lenght += ft_print_len(ptr);
	}
	return (print_lenght);
}

void ft_print_hex(unsigned long ptr)
{   
	if (ptr >= 16)
	{	
		//printf("%lu\n", ptr);
		ft_print_hex(ptr / 16);
		//printf(" 2: %lu", ptr);
		ft_print_hex(ptr % 16);
		//printf(" 3: %lu", ptr);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd((ptr + '0'), 1);
		else
		{
			ft_putchar_fd((ptr - 10 + 'a'), 1);
		}
	}
}

int ft_print_len(unsigned long ptr)
{
	int len;

	len = 0;
	while (ptr != 0)
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}