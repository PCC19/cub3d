/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:46:02 by user42            #+#    #+#             */
/*   Updated: 2021/02/15 18:21:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_tex(t_vars *v, int i, int strip_w, double strip_h)
{
	double	offset_x;
	double	offset_y;
	double	dist_from_top;
	int		y;
	int		wall_top_pixel;
	int		wall_bottom_pixel;
	int		idx;
	uint	color;

	strip_w++;
	wall_top_pixel = (v->window_height / 2) - (strip_h) / 2;
	if (wall_top_pixel < 0)
		wall_top_pixel = 0;
	wall_bottom_pixel = (v->window_height / 2) + (strip_h) / 2;
	if (wall_bottom_pixel > v->window_height)
		wall_bottom_pixel = v->window_height;
	
	idx = v->rays[i].tex_idx;

	// calcula offset x
	if (v->rays[i].hit_v)
		offset_x = (int)v->rays[i].wallhit_y % v->tile_size;
	else
		offset_x = (int)v->rays[i].wallhit_x % v->tile_size;
	// loop para cada coluna do strip
		// loop para cada y
		y = wall_top_pixel;
		while (y < wall_bottom_pixel)
		{
			// calcula offset y
			dist_from_top = y + (strip_h / 2) -  (v->window_height / 2);
			offset_y = dist_from_top * (v->tex[idx].h) / strip_h;
			// plot pixel de acordo com offset
			color = (uint)(v->tex[idx].p + (int)floor(offset_y * v->tex[idx].s_line + offset_x));
			g_pixel_put_img(v->t, offset_x, offset_y, color);
			y++;
		}
}
