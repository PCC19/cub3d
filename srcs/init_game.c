/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 22:56:08 by user42            #+#    #+#             */
/*   Updated: 2021/02/19 22:45:07 by user42           ###   ########.fr       */
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
	check_minimap_size(v);
	init_array_sprites(v);
	p_parse_array_sprites(v);
	g_image_init(v);
	p_load_textures(v);
}
