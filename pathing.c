/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:27:32 by ehouot            #+#    #+#             */
/*   Updated: 2023/05/20 16:07:00 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_correct_path(char **cpy)
{
	int	i;
	int	j;

	i = -1;
	while (cpy[++i])
	{
		j = -1;
		while (cpy[i][++j])
		{
			if (cpy[i][j] == 'L')
				check_pathing(cpy);
			if (cpy[i][j] == 'E' || cpy[i][j] == 'C')
				exit(ft_printf("Path error\n"));
		}
	}
}

void	check_path_finish(char **cpy)
{
	int	i;
	int	j;

	i = -1;
	while (cpy[++i])
	{
		j = -1;
		while (cpy[i][++j])
		{
			if (cpy[i][j] == 'L')
				check_pathing(cpy);
		}
	}
}

void	check_pathing(char **map)
{
	t_path	p;

	p.i = -1;
	p.cpy = map;
	while (p.cpy[++p.i])
	{
		p.j = -1;
		while (p.cpy[p.i][++p.j])
		{
			if (p.cpy[p.i][p.j] == 'P' || p.cpy[p.i][p.j] == 'L')
			{
				p.cpy[p.i][p.j] = 'X';
				if (p.cpy[p.i + 1][p.j] != '1' && p.cpy[p.i + 1][p.j] != 'X')
					p.cpy[p.i + 1][p.j] = 'L';
				if (p.cpy[p.i - 1][p.j] != '1' && p.cpy[p.i - 1][p.j] != 'X')
					p.cpy[p.i - 1][p.j] = 'L';
				if (p.cpy[p.i][p.j + 1] != '1' && p.cpy[p.i][p.j + 1] != 'X')
					p.cpy[p.i][p.j + 1] = 'L';
				if (p.cpy[p.i][p.j - 1] != '1' && p.cpy[p.i][p.j - 1] != 'X')
					p.cpy[p.i][p.j - 1] = 'L';
			}
		}
	}
	check_path_finish(p.cpy);
	check_correct_path(p.cpy);
}
