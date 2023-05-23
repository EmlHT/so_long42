/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:58:42 by ehouot            #+#    #+#             */
/*   Updated: 2023/05/23 12:04:05 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(int fd)
{
	char	*gnl;
	int		nb_line;

	nb_line = 0;
	gnl = get_next_line(fd);
	while (gnl)
	{
		free(gnl);
		gnl = get_next_line(fd);
		nb_line++;
	}
	return (nb_line);
}
