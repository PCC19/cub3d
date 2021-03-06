/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:06:47 by user42            #+#    #+#             */
/*   Updated: 2021/02/19 22:45:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"
#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/errno.h>

void	sai(int codigo)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(g_error[codigo], 1);
	exit(codigo);
}

int		main(int argc, char **argv)
{
	t_vars vars;

	init_game(&vars, argc, argv);
	vars.argc = argc;
	draw(&vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_expose_hook(vars.win, update_screen, &vars);
	mlx_hook(vars.win, 17, (1l << 17), free_and_exit, &vars);
	mlx_loop(vars.mlx);
}
