/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:12:08 by ehouot            #+#    #+#             */
/*   Updated: 2023/05/30 17:18:17 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		ft_escape(vars);
	if (keycode == 13)
		ft_backward(vars);
	if (keycode == 0)
		ft_left(vars);
	if (keycode == 1)
		ft_forward(vars);
	if (keycode == 2)
		ft_right(vars);
	return (0);
}
