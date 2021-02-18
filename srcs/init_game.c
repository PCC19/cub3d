/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 22:56:08 by user42            #+#    #+#             */
/*   Updated: 2021/02/18 01:00:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_vars *v, int argc, char **argv)
{
	p_init_cfg(v);
	p_parse_argumentos(argc, argv);
	v->mlx = mlx_init();
	p_parse_arquivo(v, argv[1]);
	check_resolution(v);
	calculate_tile_size(v);
	p_init_player(v);
	p_init_vars(v);
	init_array_sprites(v);
	p_parse_array_sprites(v);
	v->win = mlx_new_window(v->mlx, v->window_width,
								v->window_height, "=== CUB3D by pcunha ===");
	g_image_init(v);
	p_load_textures(v);
}
