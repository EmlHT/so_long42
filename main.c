/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:28:21 by ehouot            #+#    #+#             */
/*   Updated: 2023/05/30 19:23:01 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

int	main(int argc, char **argv)
{
	t_vars	var;
	t_path	path;

	if (argc != 2)
		exit(ft_printf("Wrong number of arguments\n"));
	var.map = parsing(argc, argv, &path);
	var.mlx_ptr = mlx_init();
	var.win_ptr = mlx_new_window(var.mlx_ptr, ft_strlen(*var.map) * 64,
			path.nb_line * 64, "The Escapist 42");
	initialize_map(&var);
	mlx_key_hook(var.win_ptr, key_hook, (void *)&var);
	mlx_loop_hook(var.mlx_ptr, &is_door_open, &var);
	mlx_hook(var.win_ptr, 17, 0, &ft_escape, &var);
	mlx_loop(var.mlx_ptr);
	return (0);
}
