/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 21:36:08 by user42            #+#    #+#             */
/*   Updated: 2021/02/18 01:01:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_right(t_vars *vars)
{
	vars->player.turn_dir = 1;
	vars->player.angle += vars->player.rotation_speed;
	vars->player.angle = u_norm_angle(vars->player.angle);
}

void	turn_left(t_vars *vars)
{
	vars->player.turn_dir = -1;
	vars->player.angle -= vars->player.rotation_speed;
	vars->player.angle = u_norm_angle(vars->player.angle);
}

void	up(t_vars *vars)
{
	int nx;
	int ny;
	int ts;
	int s;

	s = vars->player.move_speed;
	ts = vars->tile_size;
	vars->player.walk_dir = 1;
	nx = vars->player.x + floor(s * cos(u_norm_angle(vars->player.angle)));
	ny = vars->player.y + floor(s * sin(u_norm_angle(vars->player.angle)));
	if (!u_wall_hit(vars, nx, ny))
	{
		vars->player.x = nx;
		vars->player.y = ny;
	}
}

void	down(t_vars *vars)
{
	int		nx;
	int		ny;
	int		ts;
	int		s;

	s = vars->player.move_speed;
	ts = vars->tile_size;
	vars->player.walk_dir = -1;
	nx = vars->player.x - floor(s * cos(u_norm_angle(vars->player.angle)));
	ny = vars->player.y - floor(s * sin(u_norm_angle(vars->player.angle)));
	if (!u_wall_hit(vars, nx, ny))
	{
		vars->player.x = nx;
		vars->player.y = ny;
	}
}
