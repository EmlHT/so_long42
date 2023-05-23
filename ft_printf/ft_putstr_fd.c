/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:25:19 by ehouot            #+#    #+#             */
/*   Updated: 2023/05/11 14:35:03 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return (write(fd, "(null)", 6));
	i = -1;
	while (s[++i])
		ft_putchar_fd(s[i], fd);
	return (i);
}
