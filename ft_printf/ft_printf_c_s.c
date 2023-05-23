/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:25:54 by ehouot            #+#    #+#             */
/*   Updated: 2023/05/11 14:34:39 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_printf_c_s(char tag, va_list ptr, int i)
{
	int	tmp;

	if (tag == 'c')
	{
		ft_putchar_fd(va_arg(ptr, int), 1);
		i++;
	}
	if (tag == 's')
	{
		tmp = ft_putstr_fd(va_arg(ptr, char *), 1);
		i = tmp + i;
	}
	return (i);
}
