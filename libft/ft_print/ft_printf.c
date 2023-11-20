/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:16:24 by psalame           #+#    #+#             */
/*   Updated: 2023/11/07 22:17:42 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static size_t	ft_printf_percent(char *str, size_t *i, va_list *ap, size_t len)
{
	*i += 1;
	if (str[*i] == 'c' )
		return (len + ft_putchar_nb(va_arg(*ap, int)));
	if (str[*i] == '%' )
		return (len + ft_putchar_nb('%'));
	else if (str[*i] == 's')
		return (len + ft_putstr_nb(va_arg(*ap, char *)));
	else if (str[*i] == 'p')
		return (len + ft_putptr_nb(va_arg(*ap, void *)));
	else if (str[*i] == 'i' || str[*i] == 'd')
		return (len + ft_putnbr_nb(va_arg(*ap, int)));
	else if (str[*i] == 'u')
		return (len + ft_putunbr_nb(va_arg(*ap, unsigned int)));
	else if (str[*i] == 'x' || str[*i] == 'X')
		return (len + ft_putxnbr_nb(va_arg(*ap, unsigned int), str[*i] == 'X'));
	else
	{
		*i -= 1;
		if (str[*i + 1] == '\0')
			return (-1);
		else
			return (len + ft_putchar_nb('%'));
	}
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	strlen;
	size_t	res_str_len;
	va_list	ap;

	va_start(ap, str);
	i = 0;
	strlen = ft_strlen((char *)str);
	res_str_len = 0;
	while (i < strlen)
	{
		if (str[i] == '%')
			res_str_len = ft_printf_percent((char *)str, &i, &ap, res_str_len);
		else
		{
			res_str_len++;
			ft_putchar_fd(str[i], 1);
		}
		i++;
	}
	va_end(ap);
	return (res_str_len);
}
