/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 18:00:16 by user42            #+#    #+#             */
/*   Updated: 2021/02/14 19:42:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render3d(t_vars *v)
{
	int				i;
	double			ray_dist;
	double			dist_proj_plane;
	double			strip_height;
	t_input_rect	r;

	i = 0;
	dist_proj_plane = (v->window_height / 2) / tan(v->fov / 2);
	while (i < v->num_rays)
	{
		ray_dist = v->rays[i].dist * cos(v->rays[i].angle - v->player.angle);
		strip_height = (v->tile_size / ray_dist) * dist_proj_plane;
		if (strip_height >= v->window_height)
			strip_height = v->window_height;
			printf("------------------------------------\n");
			printf("i: %d\n", i);
			printf("w: %d  h: %d\n",v->window_width, v->window_height);
			printf("dist_proj_plane: %f\n",dist_proj_plane);
			printf("ray_dist: %f\n", ray_dist);
			printf("strip_height %f\n", strip_height);
			printf("x1: %d\ty1: %d\tx2: %d\ty2: %d\n",r.pto_sup_esq.x, r.pto_sup_esq.y,r.pto_sup_esq.x + v->strip_width, (int) (r.pto_sup_esq.y + strip_height));
		r.pto_sup_esq.x = i * v->strip_width;
		r.pto_sup_esq.y = (v->window_height / 2) - (strip_height / 2);
		r.altura = (int) strip_height;
		r.largura = v->strip_width;
		r.cor = WHITE;
		r.borda = 0;
		r.cor_borda = WHITE;
		int flag = 0;
		if (r.pto_sup_esq.x >= v->window_width || r.pto_sup_esq.x <= 0)
			flag = 1;
		if (r.pto_sup_esq.y >= v->window_height || r.pto_sup_esq.y <= 0 )
			flag = 1;
		if ((r.pto_sup_esq.x + v->strip_width) >= v->window_width || r.pto_sup_esq.x <= 0)
			flag = 1;
		if ((r.pto_sup_esq.y + strip_height) >= v->window_height || r.pto_sup_esq.y <= 0 )
			flag = 1;
		if (flag)
		{
			printf("x1: %d y1: %d x2: %d y2: %d\n",r.pto_sup_esq.x, r.pto_sup_esq.y,r.pto_sup_esq.x + v->strip_width, (int) (r.pto_sup_esq.y + strip_height));
			//sai(1);
		}
		g_plot_rect_img(v, r);
		//i += v->strip_width;
		i++;
	}
}
