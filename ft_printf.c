/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:06:41 by sopopa            #+#    #+#             */
/*   Updated: 2022/10/22 23:26:08 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

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
    else if (format == 's')
        print_lenght += ft_print_str(va_arg(argp, char *));
    // else if (format == 'p')
    //     print_lenght += ft_print_hex_point()
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
    int r;
   

    
    printf("%p\n", &r);
    //ft_printf("%s\n%c", a, 'e');
}