/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 18:00:16 by user42            #+#    #+#             */
/*   Updated: 2021/02/16 21:00:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_vars_draw_coluna(t_vars *v, t_aux_render_wall *a, int i)
{
	a->dist_proj_plane = (v->window_height / 2) / tan(v->fov / 2);
	a->idx = v->rays[i].tex_idx;
	a->ray_dist = v->rays[i].dist * cos(v->rays[i].angle - v->player.angle);
	a->proj_strip_height = (v->tile_size / a->ray_dist) * a->dist_proj_plane;
	a->wall_strip_height = (int)a->proj_strip_height;
}

void	calc_y_min_max(t_vars *v, t_aux_render_wall *a)
{
	a->ymin = (v->window_height / 2) - (a->wall_strip_height / 2);
	a->ymax = (v->window_height / 2) + (a->wall_strip_height / 2);
	if (a->ymin < 0)
		a->ymin = 0;
	if (a->ymax > v->window_height)
		a->ymax = v->window_height;
}

void	calc_offset_x(t_vars *v, t_aux_render_wall *a, int i)
{
	if (v->rays[i].hit_v)
		a->offset_x = (int)v->rays[i].wallhit_y % v->tile_size;
	else
		a->offset_x = (int)v->rays[i].wallhit_x % v->tile_size;
	a->offset_x = floor(a->offset_x / v->tile_size * v->tex[a->idx].w);
}

void	g_draw_coluna(t_vars *v, t_aux_render_wall *a, int i, int k)
{
	double	y;
	uint	color;

	y = a->ymin;
	while (y < a->ymax)
	{
		a->dist_from_top = y + (a->wall_strip_height / 2) -
								(v->window_height / 2);
		a->offset_y = floor(a->dist_from_top * ((float)v->tex[a->idx].h /
												a->wall_strip_height));
		color = *(uint*)(v->tex[a->idx].p +
			(int)((a->offset_y * v->tex[a->idx].w) + a->offset_x) * 4);
		g_pixel_put_img(v->t, i * v->strip_width + k, y, color);
		y++;
	}
}

void	render3d(t_vars *v)
{
	int					i;
	int					k;
	t_aux_render_wall	a;

	i = 0;
	while (i < v->num_rays)
	{
		calc_vars_draw_coluna(v, &a, i);
		calc_y_min_max(v, &a);
		calc_offset_x(v, &a, i);
		k = 0;
		while (k < v->strip_width)
		{
			g_draw_coluna(v, &a, i, k);
			k++;
		}
		i++;
	}
}
