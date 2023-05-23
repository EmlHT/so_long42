/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 02:48:40 by ehouot            #+#    #+#             */
/*   Updated: 2023/05/11 14:34:20 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_print(unsigned int n, int i, char *mod, int fd)
{	
	while ((n / 10) > 0)
	{
		i++;
		mod[i] = (n % 10) + 48;
		n = n / 10;
	}
	mod[i + 1] = n + 48;
	while (i + 1 > 0)
	{
		write (fd, &mod[i + 1], 1);
		i--;
	}
}

static void	ft_putuninbr_fd(unsigned int n, int fd)
{
	int		i;
	char	mod[13];

	i = 0;
	ft_print(n, i, mod, fd);
}

int	ft_printf_u(va_list ptr, unsigned int i)
{
	unsigned int	tmp;

	tmp = va_arg(ptr, int);
	if (tmp < 0)
		tmp = 4294967295 + (tmp + 1);
	ft_putuninbr_fd(tmp, 1);
	if (tmp == 0)
		i = i + 1;
	while (tmp > 0)
	{
		tmp = tmp / 10;
		i++;
	}
	return (i);
}
