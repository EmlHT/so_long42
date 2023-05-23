/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:57:33 by ehouot            #+#    #+#             */
/*   Updated: 2023/05/11 14:34:08 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_dispatch(char tag, va_list ptr, int *tmp)
{
	if (tag == 'c' || tag == 's')
		return (ft_printf_c_s(tag, ptr, *tmp));
	if (tag == 'i' || tag == 'd')
		return (ft_printf_d_i(ptr, *tmp));
	if (tag == 'x' || tag == 'X')
		return (ft_printf_hexa(tag, ptr, *tmp));
	if (tag == 'u')
		return (ft_printf_u(ptr, *tmp));
	if (tag == 'p')
		return (ft_printf_p(ptr, *tmp));
	if (tag == '%')
		return (ft_printf_percent(*tmp));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		tmp;
	int		cpt;
	va_list	ptr;

	va_start(ptr, str);
	tmp = 0;
	cpt = 0;
	while (str[cpt])
	{
		if (str[cpt] == '%')
		{
			tmp = ft_dispatch(str[cpt + 1], ptr, &tmp);
			cpt = cpt + 2;
		}
		if (str[cpt] && str[cpt] != '%')
		{
			ft_putchar_fd(str[cpt], 1);
			cpt++;
			tmp++;
		}
	}
	va_end(ptr);
	return (tmp);
}
