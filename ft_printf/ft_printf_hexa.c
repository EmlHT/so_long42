/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 06:00:02 by ehouot            #+#    #+#             */
/*   Updated: 2023/05/11 14:34:32 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_puthexa(char tag, unsigned int tmp)
{
	if (tmp >= 16)
	{
		ft_puthexa(tag, tmp / 16);
		ft_puthexa(tag, tmp % 16);
	}
	else
	{
		if (tmp <= 9)
			ft_putchar_fd((tmp + '0'), 1);
		else
		{
			if (tag == 'x')
				ft_putchar_fd((tmp - 10 + 'a'), 1);
			if (tag == 'X')
				ft_putchar_fd((tmp - 10 + 'A'), 1);
		}
	}
}

static int	ft_lenhexa(unsigned int tmp)
{
	int	cpt;

	cpt = 0;
	while (tmp != 0)
	{
		tmp = tmp / 16;
		cpt++;
	}
	return (cpt);
}

int	ft_printf_hexa(char tag, va_list ptr, int i)
{
	int	tmp;

	tmp = va_arg(ptr, int);
	if (tmp == 0)
	{
		write(1, "0", 1);
		return (i = i + 1);
	}
	ft_puthexa(tag, tmp);
	i = i + ft_lenhexa(tmp);
	return (i);
}
