/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_init_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 00:54:14 by user42            #+#    #+#             */
/*   Updated: 2021/02/10 17:07:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	p_init_player_angle(t_vars *vars)
{
	int i;
	int j;

	i = 0;
	while (i < vars->map_num_rows)
	{
		j = 0;
		while (j < vars->map_num_cols)
		{
			if (vars->map[i][j] == 'E')
				vars->player.angle = 0;
			if (vars->map[i][j] == 'N')
				vars->player.angle = 3 * M_PI / 2;
			if (vars->map[i][j] == 'W')
				vars->player.angle = M_PI;
			if (vars->map[i][j] == 'S')
				vars->player.angle = M_PI / 2;
			j++;
		}
		i++;
	}
}

void	p_init_player_pos(t_vars *vars)
{
	int i;
	int j;
	int xx;
	int yy;

	i = 0;
	while (i < vars->map_num_rows)
	{
		j = 0;
		while (j < vars->map_num_cols)
		{
			if (ft_is_in(vars->map[i][j], "NSEW"))
			{
				xx = j;
				yy = i;
			}
			j++;
		}
		i++;
	}
	printf("xx: %d  yy: %d\n",xx,yy);

	vars->player.x = (xx + 1) * vars->tile_size - (vars->tile_size / 2);
	vars->player.y = (yy + 1) * vars->tile_size - (vars->tile_size / 2);
}

void	p_init_player(t_vars *vars)
{
	p_init_player_pos(vars);
	vars->player.radius = 2;
	vars->player.turn_dir = 0;
	vars->player.walk_dir = 0;
	p_init_player_angle(vars);
	vars->player.move_speed = 2;
	vars->player.rotation_speed = 2 * M_PI / 40;
}
