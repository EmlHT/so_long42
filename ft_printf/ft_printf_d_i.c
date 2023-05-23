/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:58:21 by ehouot            #+#    #+#             */
/*   Updated: 2023/05/11 14:34:34 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_printf_d_i(va_list ptr, int i)
{
	int	tmp;

	tmp = va_arg(ptr, int);
	ft_putnbr_fd(tmp, 1);
	if (tmp == -2147483648)
		return (i = i + 11);
	if (tmp == 0)
		i = i + 1;
	if (tmp < 0)
	{
		tmp *= -1;
		i++;
	}
	while (tmp > 0)
	{
		tmp = tmp / 10;
		i++;
	}
	return (i);
}
