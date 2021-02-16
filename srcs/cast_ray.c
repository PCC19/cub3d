/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 17:52:54 by user42            #+#    #+#             */
/*   Updated: 2021/02/16 21:07:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assign_dist(t_vars *v, double h_dist, double v_dist, int i)
{
	//printf("=================================================\n");
	if (h_dist < v_dist)
	{
	//	printf("horizontal hit at x: %d y: %d \n",v->ah.wallhit_x, v->ah.wallhit_y);
		v->rays[i].wallhit_x = v->ah.wallhit_x;
		v->rays[i].wallhit_y = v->ah.wallhit_y;
		v->rays[i].dist = h_dist;
		v->rays[i].hit_v = 0;
	}
	else
	{
	//	printf("vertical hit at x: %d y: %d \n",v->av.wallhit_x, v->av.wallhit_y);
		v->rays[i].wallhit_x = v->av.wallhit_x;
		v->rays[i].wallhit_y = v->av.wallhit_y;
		v->rays[i].dist = v_dist;
		v->rays[i].hit_v = 1;
	}
	//printf("h_dist: %f  v_dist: %f  dist: %f\n",h_dist, v_dist, v->rays[i].dist);
	//printf("angle: %f\n",v->rays[i].angle * 180 / M_PI);
	//printf("hit coord x: %f y: %f\n",v->rays[i].wallhit_x, v->rays[i].wallhit_y);
}

void	cast_ray(t_vars *v, int i, double angle)
{
	int		x1;
	int		y1;
	double	h_dist;
	double	v_dist;

	init_horizontal_dist(v, i, angle);
	horizontal_dist(v, i);
	x1 = v->ah.wallhit_x;
	y1 = v->ah.wallhit_y;
	if (v->ah.found_hit)
		h_dist = dist(v->player.x, v->player.y, x1, y1);
	else
		h_dist = 10000;
	init_vertical_dist(v, i, angle);
	vertical_dist(v, i);
	x1 = v->av.wallhit_x;
	y1 = v->av.wallhit_y;
	if (v->av.found_hit)
		v_dist = dist(v->player.x, v->player.y, x1, y1);
	else
		v_dist = 10000;
	assign_dist(v, h_dist, v_dist, i);
	//check_if_sprite(v, i);
	get_tex_idx(v, i);
}
