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

int check_format(va_list argp, const char format)
{
    int print_lenght;

    print_lenght = 0;
    if (format == 'c')
        print_lenght += ft_print_char(va_arg(argp, int));
    else //(format == 's');
        print_lenght += ft_print_str(va_arg(argp, char *));
    return (print_lenght);
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
        }
        i++;
    }
    va_end(argp);
    return (print_lenght);
}



int main (void)
{
    char *a = "sorin";
    //printf("%s", a);
    ft_printf("%s\n%c", a, 'e');
}