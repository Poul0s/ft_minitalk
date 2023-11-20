/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:04:33 by psalame           #+#    #+#             */
/*   Updated: 2023/11/07 22:11:50 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H
# include "libft.h"

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_printf(const char *str, ...);
int		ft_putchar_nb(const char c);
int		ft_putstr_nb(const char *str);
int		ft_putptr_nb(void *ptr);
int		ft_putnbr_nb(int nb);
int		ft_putunbr_nb(unsigned int nb);
int		ft_putxnbr_nb(unsigned int nb, short maj);

#endif
