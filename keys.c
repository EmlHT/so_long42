/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:26:01 by ehouot            #+#    #+#             */
/*   Updated: 2023/05/23 11:57:53 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_escape(t_vars *var)
{
	(void)var;
	// mlx_destroy_image(var->mlx_ptr, var->floor);
	// mlx_destroy_image(var->mlx_ptr, var->wall);
	// mlx_destroy_image(var->mlx_ptr, var->red_key);
	// mlx_destroy_image(var->mlx_ptr, var->door_closed);
	// mlx_destroy_image(var->mlx_ptr, var->door_open);
	// mlx_destroy_image(var->mlx_ptr, var->forward_one);
	// mlx_destroy_image(var->mlx_ptr, var->forward_two);
	// mlx_destroy_image(var->mlx_ptr, var->backward_one);
	// mlx_destroy_image(var->mlx_ptr, var->backward_two);
	// mlx_destroy_image(var->mlx_ptr, var->left_one);
	// mlx_destroy_image(var->mlx_ptr, var->left_two);
	// mlx_destroy_image(var->mlx_ptr, var->right_one);
	// mlx_destroy_image(var->mlx_ptr, var->right_two);
	mlx_destroy_window(var->mlx_ptr, var->win_ptr);
	exit(0);
	return (0);
}

void	ft_backward(t_vars *var)
{
	static int	move;

	if (move == 0)
	{
		var->backward_one = mlx_xpm_file_to_image(var->mlx_ptr, "./img/backward_one.xpm", &(var)->width, &(var)->height);
		move = 1;
	}
	if (move == 1)
	{
		var->backward_two = mlx_xpm_file_to_image(var->mlx_ptr, "./img/backward_two.xpm", &(var)->width, &(var)->height);
		move = 0;
	}
}

void	ft_left(t_vars *var)
{
	static int	move;

	if (move == 0)
	{
		var->left_one = mlx_xpm_file_to_image(var->mlx_ptr, "./img/left_one.xpm", &(var)->width, &(var)->height);
		move = 1;
	}
	if (move == 1)
	{
		var->left_two = mlx_xpm_file_to_image(var->mlx_ptr, "./img/left_two.xpm", &(var)->width, &(var)->height);
		move = 0;
	}
}

void	ft_forward(t_vars *var)
{
	static int	move;

	if (move == 0)
	{
		var->forward_one = mlx_xpm_file_to_image(var->mlx_ptr, "./img/forward_one.xpm", &(var)->width, &(var)->height);
		move = 1;
	}
	if (move == 1)
	{
		var->forward_one = mlx_xpm_file_to_image(var->mlx_ptr, "./img/forward_two.xpm", &(var)->width, &(var)->height);
		move = 0;
	}
}

void	ft_right(t_vars *var)
{
	static int	move;

	if (move == 0)
	{
		var->right_one = mlx_xpm_file_to_image(var->mlx_ptr, "./img/right_one.xpm", &(var)->width, &(var)->height);
		move = 1;
	}
	if (move == 1)
	{
		var->right_two = mlx_xpm_file_to_image(var->mlx_ptr, "./img/right_two.xpm", &(var)->width, &(var)->height);
		move = 0;
	}
}
