/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_init_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 00:54:14 by user42            #+#    #+#             */
/*   Updated: 2021/02/17 23:18:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	p_init_player_angle(t_vars *v)
{
	int i;
	int j;

	i = 0;
	while (i < v->map_num_rows)
	{
		j = 0;
		while (j < v->map_num_cols)
		{
			if (v->map[i][j] == 'E')
				v->player.angle = 0;
			if (v->map[i][j] == 'N')
				v->player.angle = 3 * M_PI / 2;
			if (v->map[i][j] == 'W')
				v->player.angle = M_PI;
			if (v->map[i][j] == 'S')
				v->player.angle = M_PI / 2;
			j++;
		}
		i++;
	}
}

void	p_init_player_pos(t_vars *v)
{
	int i;
	int j;
	int xx;
	int yy;

	i = 0;
	while (i < v->map_num_rows)
	{
		j = 0;
		while (j < v->map_num_cols)
		{
			if (ft_is_in(v->map[i][j], "NSEW"))
			{
				xx = j;
				yy = i;
			}
			j++;
		}
		i++;
	}
	v->player.x = (xx + 1) * v->tile_size - (v->tile_size / 2);
	v->player.y = (yy + 1) * v->tile_size - (v->tile_size / 2);
}

void	p_init_player(t_vars *v)
{
	p_init_player_pos(v);
	v->player.radius = 2;
	v->player.turn_dir = 0;
	v->player.walk_dir = 0;
	p_init_player_angle(v);
	v->player.move_speed = 10;
	v->player.rotation_speed = 10 * M_PI / 360;
}
