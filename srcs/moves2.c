/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 21:38:45 by user42            #+#    #+#             */
/*   Updated: 2021/02/19 15:59:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_left(t_vars *vars)
{
	int nx;
	int ny;
	int ts;
	int s;

	s = vars->player.move_speed;
	ts = vars->tile_size;
	vars->player.walk_dir = 1;
	nx = vars->player.x + floor(s * cos(u_norm_angle(
								vars->player.angle - M_PI / 2)));
	ny = vars->player.y + floor(s * sin(u_norm_angle(
								vars->player.angle - M_PI / 2)));
	if (!u_wall_hit(vars, nx, ny) &&
		nx != vars->tile_size && ny != vars->tile_size)
	{
		vars->player.x = nx;
		vars->player.y = ny;
	}
}

void	move_right(t_vars *vars)
{
	int nx;
	int ny;
	int ts;
	int s;

	s = vars->player.move_speed;
	ts = vars->tile_size;
	vars->player.walk_dir = 1;
	nx = vars->player.x + floor(s * cos(u_norm_angle(
								vars->player.angle + M_PI / 2)));
	ny = vars->player.y + floor(s * sin(u_norm_angle(
								vars->player.angle + M_PI / 2)));
	if (!u_wall_hit(vars, nx, ny) &&
		nx != vars->tile_size && ny != vars->tile_size)
	{
		vars->player.x = nx;
		vars->player.y = ny;
	}
}
