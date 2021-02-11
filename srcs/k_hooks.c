/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_hooks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 22:23:35 by user42            #+#    #+#             */
/*   Updated: 2021/02/10 23:49:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	right(t_vars *vars)
{
	vars->player.turn_dir = 1;
	vars->player.angle += vars->player.rotation_speed;
	vars->player.angle = u_norm_angle(vars->player.angle);
	printf("rot_speed: %f\n", vars->player.rotation_speed);
	printf("angle: %f\n", vars->player.angle);
}

void	left(t_vars *vars)
{
	vars->player.turn_dir = -1;
	vars->player.angle -= vars->player.rotation_speed;
	vars->player.angle = u_norm_angle(vars->player.angle);
	printf("rot_speed: %f\n", vars->player.rotation_speed);
	printf("angle: %f\n", vars->player.angle);
}

void	up(t_vars *vars)
{
	int nx;
	int ny;
	int ts;

	ts = vars->tile_size;
	vars->player.walk_dir = 1;
	nx = vars->player.x + vars->player.move_speed * cos(vars->player.angle);
	ny = vars->player.y + vars->player.move_speed * sin(vars->player.angle);
	printf("X: %d   Y: %d\n", vars->player.x, vars->player.y);
	printf("nx: %d   ny: %d\n", nx, ny);
	printf("nx/tile_size: %d  ny/tile_size: %d\n", nx / ts, ny / ts);
	nx = vars->player.x + vars->player.move_speed * cos(vars->player.angle);
	ny = vars->player.y + vars->player.move_speed * sin(vars->player.angle);
	if(!u_wall_hit(vars, nx, ny))
	{
		vars->player.x = nx;
		vars->player.y = ny;
	}
}

void	down(t_vars *vars)
{
	int nx;
	int ny;
	int ts;

	ts = vars->tile_size;
	vars->player.walk_dir = -1;
	nx = vars->player.x - vars->player.move_speed * cos(vars->player.angle);
	ny = vars->player.y - vars->player.move_speed * sin(vars->player.angle);
	printf("X: %d   Y: %d\n", vars->player.x, vars->player.y);
	printf("nx: %d   ny: %d\n", nx, ny);
	printf("nx/tile_size: %d  ny/tile_size: %d\n", nx / ts, ny / ts);
	if(!u_wall_hit(vars, nx, ny))
	{
		vars->player.x = nx;
		vars->player.y = ny;
	}
}

int		key_hook(int keycode, t_vars *vars)
{
	printf("keycode: %d\n", keycode);
	if (keycode == RIGHT)
		right(vars);
	if (keycode == LEFT)
		left(vars);
	if (keycode == UP)
		up(vars);
	if (keycode == DN)
		down(vars);
	update(vars);
	return (0);
}
