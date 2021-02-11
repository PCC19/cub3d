/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 17:52:54 by user42            #+#    #+#             */
/*   Updated: 2021/02/11 18:43:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_ray_booleans(t_vars *vars, int i, float angle)
{
	if (angle > 0 && angle < M_PI)
	{
		vars->rays[i].is_dn = 1;
		vars->rays[i].is_up = 0;
	}
	//if (angle > M_PI && angle < 2 * M_PI)
	else
	{
		vars->rays[i].is_dn = 0;
		vars->rays[i].is_up = 1;
	}
	if (angle < M_PI / 2 || angle > 3 * M_PI / 2)
	{
		vars->rays[i].is_ri = 1;
		vars->rays[i].is_le = 0;
	}
	if (angle > M_PI / 2 && angle < 3 * M_PI / 2)
	{
		vars->rays[i].is_ri = 0;
		vars->rays[i].is_le = 1;
	}
	printf("set_ray_boolean: %d %d %d %d\n",vars->rays[0].is_dn, vars->rays[0].is_up, vars->rays[0].is_ri, vars->rays[0].is_le);
}


void	cast_ray(t_vars *vars, int i, float angle)
{
	int xstep;
	int	ystep;
	int x_i;
	int	y_i;

	// Set ray booleans
	set_ray_booleans(vars, i, angle);
	
	vars->rays[i].angle = angle; // editar
	
	// HORIZONTAL INTERCEPT
	y_i = floor(vars->player.y / vars->tile_size) * vars->tile_size;
	if (vars->rays[i].is_dn)
		y_i += vars->tile_size;
	x_i = vars->player.x + (vars->player.y - y_i) / tan(vars->player.angle);

	ystep = vars->tile_size;
	if (vars->rays[i].is_up)
		ystep *= -1;
	xstep = ystep / tan(angle);
	if (vars->rays[i].is_le && xstep > 0)
		xstep *= -1;
	if (vars->rays[i].is_ri && xstep < 0)
		xstep *= -1;
}

