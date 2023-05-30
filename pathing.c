/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:27:32 by ehouot            #+#    #+#             */
/*   Updated: 2023/05/30 20:49:52 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_correct_path(t_path *p)
{
	int	i;
	int	j;

	i = -1;
	while (p->cpy[++i])
	{
		j = -1;
		while (p->cpy[i][++j])
		{
			if (p->cpy[i][j] == 'L')
				check_pathing(p);
			if (p->cpy[i][j] == 'E' || p->cpy[i][j] == 'C')
			{
				free_map(p->cpy);
				exit(ft_printf("Path error\n"));
			}
		}
	}
}

void	check_path_finish(t_path *p)
{
	int	i;
	int	j;

	i = -1;
	while (p->cpy[++i])
	{
		j = -1;
		while (p->cpy[i][++j])
		{
			if (p->cpy[i][j] == 'L')
				check_pathing(p);
		}
	}
}

void	replace(t_path *p)
{
	if (p->cpy[p->i][p->j] == 'P' || p->cpy[p->i][p->j] == 'L')
	{
		p->cpy[p->i][p->j] = 'X';
		if (p->cpy[p->i + 1][p->j] != '1' && p->cpy[p->i + 1][p->j] != 'X')
			p->cpy[p->i + 1][p->j] = 'L';
		if (p->cpy[p->i - 1][p->j] != '1' && p->cpy[p->i - 1][p->j] != 'X')
			p->cpy[p->i - 1][p->j] = 'L';
		if (p->cpy[p->i][p->j + 1] != '1' && p->cpy[p->i][p->j + 1] != 'X')
			p->cpy[p->i][p->j + 1] = 'L';
		if (p->cpy[p->i][p->j - 1] != '1' && p->cpy[p->i][p->j - 1] != 'X')
			p->cpy[p->i][p->j - 1] = 'L';
	}
}

void	check_pathing(t_path *p)
{
	p->i = -1;
	while (p->cpy[++p->i])
	{
		p->j = -1;
		while (p->cpy[p->i][++p->j])
			replace(p);
	}
	check_path_finish(p);
	check_correct_path(p);
}
