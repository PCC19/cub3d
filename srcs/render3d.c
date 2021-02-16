/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 18:00:16 by user42            #+#    #+#             */
/*   Updated: 2021/02/16 18:51:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render3d(t_vars *v)
{
	int				i;
	double			ray_dist;
	double			dist_proj_plane;
	double			proj_strip_height;
	int				wall_strip_height;
	float			ymin;
	float			ymax;
	float			offset_x;
	float			offset_y;
	float			y;
	int				idx;
	float			dist_from_top;
	int				k;
	uint			color;

	i = 0;
	dist_proj_plane = (v->window_height / 2) / tan(v->fov / 2);
	while (i < v->num_rays)
	{
		k = 0;
		while (k < v->strip_width)
		{
			idx = v->rays[i].tex_idx;
			ray_dist = v->rays[i].dist * cos(v->rays[i].angle - v->player.angle);
			proj_strip_height = (v->tile_size / ray_dist) * dist_proj_plane;
			wall_strip_height = (int)proj_strip_height;

			ymin = (v->window_height / 2) - (wall_strip_height / 2);
			ymax = (v->window_height / 2) + (wall_strip_height / 2);
			if (ymin < 0)
				ymin = 0;
			if (ymax > v->window_height)
				ymax = v->window_height;
			// calcula offset x
			if (v->rays[i].hit_v)
				offset_x = (int)v->rays[i].wallhit_y % v->tile_size;
			else
				offset_x = (int)v->rays[i].wallhit_x % v->tile_size;
			offset_x = floor(offset_x / v->tile_size * v->tex[idx].w);
			if (k == 0) printf("offset_x %f\n",offset_x);
			y = ymin;
			while (y < ymax)
			{
				dist_from_top = y + (wall_strip_height / 2) - (v->window_height /2 );
				offset_y = floor(dist_from_top *((float)v->tex[idx].h / wall_strip_height));
				//color = *(uint*)(v->tex[idx].p + (int)((offset_y * v->tex[idx].s_line/4) + offset_x)*4);
				color = *(uint*)(v->tex[idx].p + (int)((offset_y * v->tex[idx].w) + offset_x)*4);
				g_pixel_put_img(v->t, i * v->strip_width + k, y, color);
				if (idx == 1)
				{
//					printf("idx: %d\t tex[idx].h: %d\t w: %d\n",idx, v->tex[idx].h, v->tex[idx].w);
//					printf("offset_y %f\ts_line: %d\toffset_x: %f\n",offset_y, v->tex[idx].s_line, offset_x);
				}

				y++;
			}
			k++;
		}
		i++;
	}
}
