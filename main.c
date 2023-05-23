/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:28:21 by ehouot            #+#    #+#             */
/*   Updated: 2023/05/23 11:45:42 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars	var;

	if (argc != 2)
		exit(ft_printf("Wrong number of arguments\n"));
	var.map = parsing(argc, argv);
	var.mlx_ptr = mlx_init();
	var.win_ptr = mlx_new_window(var.mlx_ptr, 1920, 1080, "The Escapist 42");
	mlx_key_hook(var.win_ptr, key_hook, (void *)&var);
	mlx_hook(var.win_ptr, 17, 0, &ft_escape, &var);
	mlx_loop(var.mlx_ptr);
	return (0);
}
