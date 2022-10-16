/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:06:41 by sopopa            #+#    #+#             */
/*   Updated: 2022/10/15 15:28:26 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int ft_print_char(int c)
{
    write(1, &c, 2);
    return (1);
}

int check_format(const char format, va_list argp)
{
    int print_lenght;

    print_lenght = 0;
    if (format == 'c')
        print_lenght += ft_print_char(va_arg(argp, int));
    return (print_lenght)
}

int     ft_printf(const char *str, ...)
{
    int	i;
    int	print_lenght;
    va_list	argp;

    i = 0;
    print_lenght = 0;
    va_start(argp, str);
    while (str[i])
    {
        if (str[i] == '%')
        {
            print_lenght += check_format(argp, str[i + 1]);
            i++;
        }
        else
        {
            print_lenght += ft_print_char(str[i]);
            i++;
        }
    }
    va_end(argp);
    return (print_lenght);
}



int main (void)
{
    ft_printf("ciao");
    printf("ciao\n");
}