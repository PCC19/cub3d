/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:46:02 by user42            #+#    #+#             */
/*   Updated: 2021/02/18 00:33:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_tex(t_vars *v, int i, int strip_w, double strip_h)
{
	v->e.ymin = (v->window_height / 2) - (strip_h / 2);
	v->e.ymax = (v->window_height / 2) + (strip_h / 2);
	v->e.idx = v->rays[i].tex_idx;
	if (v->rays[i].hit_v)
		v->e.offset_x = (int)v->rays[i].wallhit_y % v->tile_size;
	else
		v->e.offset_x = (int)v->rays[i].wallhit_x % v->tile_size;
	v->e.k = 0;
	while (v->e.k < strip_w)
	{
		v->e.y = v->e.ymin;
		while (v->e.y < v->e.ymax)
		{
			v->e.offset_y = floor(((v->e.y - v->e.ymin) /
							(v->e.ymax - v->e.ymin)) * (v->tex[v->e.idx].h));
			v->e.color = *(uint*)(v->tex[v->e.idx].p +
						(int)((v->e.offset_y * v->tex[v->e.idx].s_line / 4)
						+ v->e.offset_x) * 4);
			g_pixel_put_img(v->t, i * strip_w + v->e.k, v->e.y, v->e.color);
			v->e.y++;
		}
		v->e.k++;
	}
}
