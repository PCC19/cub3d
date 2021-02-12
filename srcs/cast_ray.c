/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 17:52:54 by user42            #+#    #+#             */
/*   Updated: 2021/02/12 01:21:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_ray_booleans(t_vars *v, int i, float angle)
{
	if (angle > 0 && angle < M_PI)
	{
		v->rays[i].is_dn = 1;
		v->rays[i].is_up = 0;
	}
	else
	{
		v->rays[i].is_dn = 0;
		v->rays[i].is_up = 1;
	}
	if (angle < M_PI / 2 || angle > 3 * M_PI / 2)
	{
		v->rays[i].is_ri = 1;
		v->rays[i].is_le = 0;
	}
	else
	{
		v->rays[i].is_ri = 0;
		v->rays[i].is_le = 1;
	}
//	printf("set_ray_boolean: %d %d %d %d\n",v->rays[0].is_dn, v->rays[0].is_up, v->rays[0].is_ri, v->rays[0].is_le);
}


void	cast_ray(t_vars *v, int i, float angle)
{
	int xstep;
	int	ystep;
	int xi;
	int	yi;
	int next_xi;
	int	next_yi;
	int	found_horizontal_hit;
	int	wallhit_x;
	int	wallhit_y;

	wallhit_x = 0;
	wallhit_y = 0;
	found_horizontal_hit = 0;

	// Set ray booleans
	set_ray_booleans(v, i, angle);
	
	v->rays[i].angle = angle; // editar
	
	// HORIZONTAL INTERCEPT
	yi = (v->player.y / v->tile_size) * v->tile_size;
		printf("calc: %d\n", (v->player.y / v->tile_size));
		printf("tile_size %d\n",v->tile_size);
	if (v->rays[i].is_dn)
		yi += v->tile_size;
	xi = v->player.x + (v->player.y - yi) / tan(u_norm_angle(2*M_PI - angle));
	printf("px: %d  pi: %d\n",v->player.x, v->player.y);
	printf("xi: %d  yi: %d\n",xi,yi);

//		g_pixel_put_img(v->t, xi, yi, RED);

	ystep = v->tile_size;
	if (v->rays[i].is_up)
		ystep *= -1;
	xstep = ystep / tan(angle);
	if (v->rays[i].is_le && xstep > 0)
		xstep *= -1;
	if (v->rays[i].is_ri && xstep < 0)
		xstep *= -1;
	// LOOP PARA CALC DISTANCIA	
	next_xi = xi;
	next_yi = yi;
	if (v->rays[i].is_up)
		next_yi--;
	while(u_is_inside(v, next_xi, next_yi))
	{
//		g_pixel_put_img(v->t, next_xi+1, next_yi+1, RED);
		if (u_wall_hit(v, next_xi, next_yi))
		{
			found_horizontal_hit = 1;
			wallhit_x = next_xi;
			wallhit_y = next_yi;
			// plot linha
			t_pto p0;
			t_pto p1;
			p0.x = v->player.x;
			p0.y = v->player.y;
			p1.x = wallhit_x;
			p1.y = wallhit_y;
			printf(" cr: %f\n",angle * 180 / M_PI);
			g_plot_line_img(v, p0, p1, GREEN);
		
			
			break;
		}
		else
		{
			next_xi += xstep;
			next_yi += ystep;
		}
	}
}
