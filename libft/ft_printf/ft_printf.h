/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:13:06 by cwick             #+#    #+#             */
/*   Updated: 2023/12/17 13:52:55 by cwick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

/*###printers###*/
//printf
int	ft_printf(const char *input_str, ...);
//formatcheck
int	ft_formatcheck(const char *str, va_list data_type, int i);
//string
int	ft_print_str(char *str);
//char
int	ft_print_char(char c);
//number
int	ft_print_nbr(int nbr);
int	ft_putnbr(int n);
//unsigned number
int	ft_print_u_nbr(unsigned int n);
int	ft_put_u_nbr(unsigned int n);
//pointer
int	ft_print_ptr(unsigned long mem_adress);
int	ft_put_ptr(unsigned long mem_adress);
//Hexadecimal
int	ft_print_hex(unsigned int nbr, int data_type);
int	ft_put_hex(unsigned int nbr, char *chars);

#endif
