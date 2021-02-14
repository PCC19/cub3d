/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 18:00:16 by user42            #+#    #+#             */
/*   Updated: 2021/02/14 19:02:16 by user42           ###   ########.fr       */
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
		r.pto_sup_esq.x = i * v->strip_width;
		r.pto_sup_esq.y = (v->window_height / 2) - (strip_height / 2);
		r.altura = strip_height;
		r.largura = v->strip_width;
		r.cor = WHITE;
		r.borda = 0;
		r.cor_borda = WHITE;
		g_plot_rect_img(v, r);
		i++;
	}
}