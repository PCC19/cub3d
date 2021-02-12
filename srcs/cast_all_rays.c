/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 23:28:27 by user42            #+#    #+#             */
/*   Updated: 2021/02/12 01:12:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	u_init_rays(t_vars *vars)
{
	int i;

	i = 0;
	while (i < MAX_RAYS)
	{
		vars->rays[i] = (t_ray) {0};
		i++;
	}
}


void	cast_all_rays(t_vars *vars)
{
	int		column_id;
	float	ray_angle;
	int		i;

	// zera rays
	//u_init_rays(vars);	
	column_id = 0;
//	printf("player angle: %f  fov: %f\n",vars->player.angle, vars->fov);
	ray_angle = 0;
	ray_angle = vars->player.angle - (vars->fov / 2);
//	printf("ray_angle: %f\n",ray_angle);
	i = 0;
	//while (i < vars->num_rays)
	while (i < 1)
	{
		// ray cast
			printf("ca1: %f\n", ray_angle*180/M_PI);
		render_ray(vars, ray_angle, BLUE);
		// cast_ray
			printf("ca2: %f\n", ray_angle*180/M_PI);
		cast_ray(vars, i, ray_angle);
		ray_angle += vars->fov / vars->num_rays;
		column_id++;
		i++;
	}

}
