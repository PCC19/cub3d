/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_dist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 00:47:15 by user42            #+#    #+#             */
/*   Updated: 2021/02/13 18:49:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_vertical_dist(t_vars *v, int i, float a)
{
	float aa;
	printf("==================== VERTICAL  ====================\n");

			printf("av: %f\n", a*180/M_PI);
	aa = 2 * M_PI - a;
	v->av.wallhit_x = 0;
	v->av.wallhit_y = 0;
	v->av.found_hit = 0;
	set_ray_booleans(v, i, a);
	v->rays[i].angle = a; // editar
	v->av.xi = (v->player.x / v->tile_size) * v->tile_size;
	if (v->rays[i].is_ri)
		v->av.xi += v->tile_size;
	v->av.yi = v->player.y + (v->player.x - v->av.xi) * tan(u_norm_angle(aa));
	v->av.xstep = v->tile_size;
	if (v->rays[i].is_le)
		v->av.xstep *= -1;
	v->av.ystep = v->av.xstep * tan(a);
	if (v->rays[i].is_up && v->av.ystep > 0)
		v->av.ystep *= -1;
	if (v->rays[i].is_dn && v->av.ystep < 0)
		v->av.ystep *= -1;
}

void	vertical_dist(t_vars *v, int i)
{
	//t_pto p0;
	//t_pto p1;

	v->av.next_xi = v->av.xi;
	v->av.next_yi = v->av.yi;
	if (v->rays[i].is_le)
		v->av.next_xi--;
	else
		v->av.next_xi++;
	printf("player x: %d  player y: %d\n",v->player.x, v->player.y);
	while (u_is_inside(v, v->av.next_xi, v->av.next_yi))
	{
	g_pixel_put_img(v->t, v->av.next_xi+2, v->av.next_yi+2, RED);
	mlx_put_image_to_window(v->mlx, v->win, v->t.id, 0, 0);
		if (u_wall_hit(v, v->av.next_xi, v->av.next_yi))
		{
			v->av.found_hit = 1;
			v->av.wallhit_x = v->av.next_xi;
			v->av.wallhit_y = v->av.next_yi;
			//p0.x = v->player.x;
			//p0.y = v->player.y;
			//p1.x = v->av.wallhit_x;
			//p1.y = v->av.wallhit_y;
			//g_plot_line_img(v, p0, p1, BLACK);
			printf("vhit\n");
			printf("vxi: %d  vyi: %d\n",v->av.next_xi, v->av.next_yi);
			break ;
		}
		else
		{
			v->av.next_xi += v->av.xstep;
			v->av.next_yi += v->av.ystep;
		}
	}
}
