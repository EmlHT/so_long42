/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 07:48:15 by ehouot            #+#    #+#             */
/*   Updated: 2023/05/11 14:34:30 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_puthexa(size_t tmp)
{
	if (tmp >= 16)
	{
		ft_puthexa(tmp / 16);
		ft_puthexa(tmp % 16);
	}
	else
	{
		if (tmp <= 9)
			ft_putchar_fd((tmp + '0'), 1);
		else
			ft_putchar_fd((tmp - 10 + 'a'), 1);
	}
}

static int	ft_lenhexa(size_t tmp)
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

int	ft_printf_p(va_list ptr, unsigned long long i)
{
	unsigned long	tmp;

	tmp = va_arg(ptr, unsigned long);
	write(1, "0x", 2);
	i = i + 2;
	if (tmp == 0)
	{
		write(1, "0", 1);
		i = i + 1;
	}
	else
	{
		ft_puthexa(tmp);
		i = i + ft_lenhexa(tmp);
	}
	return (i);
}
