/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_door_open.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:42:49 by ehouot            #+#    #+#             */
/*   Updated: 2023/05/30 19:36:32 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_door_open(t_vars *var)
{
	if (var->nb_obj <= 0)
	{
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, \
			var->door_open, var->door_x * 64, var->door_y * 64);
		if ((var->pos_x == var->door_x) && (var->pos_y == var->door_y))
		{
			ft_printf("Bravo !\n");
			exit(0);
		}
	}
	return (0);
}
