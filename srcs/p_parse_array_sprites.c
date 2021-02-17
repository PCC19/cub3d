/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_array_sprites.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:47:38 by user42            #+#    #+#             */
/*   Updated: 2021/02/17 23:25:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	p_parse_array_sprites(t_vars *v)
{
	int xmap;
	int	ymap;

	xmap = 0;
	while (xmap < v->map_num_cols)
	{
		ymap = 0;
		while (ymap < v->map_num_rows)
		{
			if (ft_is_in(v->map[ymap][xmap], "2"))
			{
				v->sprites[v->n_sprites].x = (xmap + 0.5) * v->tile_size;
				v->sprites[v->n_sprites].y = (ymap + 0.5) * v->tile_size;
				v->n_sprites++;
			}
			ymap++;
		}
		xmap++;
	}
}
