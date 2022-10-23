/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 02:35:56 by sopopa            #+#    #+#             */
/*   Updated: 2022/10/23 07:12:03 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int ft_print_str(char *str)
{
     int i;

     i = 0;
     if (str == NULL)
          write(1, "(null)", 6);
     while(str[i])
     {
        write(1, &str[i], 1);
        i++;
     }
     return (i);    
}