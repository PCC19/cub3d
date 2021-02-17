/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 23:28:27 by user42            #+#    #+#             */
/*   Updated: 2021/02/17 23:46:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	u_init_rays(t_vars *vars)
{
	int i;

	i = 0;
	while (i < MAX_RAYS)
	{
		vars->rays[i].angle = 0;
		vars->rays[i].dist = 0;
		vars->rays[i].wallhit_x = 0;
		vars->rays[i].wallhit_y = 0;
		vars->rays[i].is_dn = 0;
		vars->rays[i].is_up = 0;
		vars->rays[i].is_ri = 0;
		vars->rays[i].is_le = 0;
		vars->rays[i].hit_v = 0;
		vars->rays[i].is_sprite = 0;
		i++;
	}
}

void	cast_all_rays(t_vars *vars)
{
	int		column_id;
	double	ray_angle;
	int		i;

	u_init_rays(vars);
	column_id = 0;
	ray_angle = 0;
	ray_angle = u_norm_angle(vars->player.angle - (vars->fov / 2));
	i = 0;
	while (i < vars->num_rays)
	{
		cast_ray(vars, i, ray_angle);
		ray_angle += vars->fov / (double)vars->num_rays;
		ray_angle = u_norm_angle(ray_angle);
		column_id++;
		i++;
	}
}
