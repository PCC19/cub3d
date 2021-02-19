/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_dist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 00:46:01 by user42            #+#    #+#             */
/*   Updated: 2021/02/19 01:19:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_ray_booleans(t_vars *v, int i, double angle)
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
}

void	init_horizontal_dist(t_vars *v, int i, double a)
{
	double aa;

	aa = u_norm_angle(2 * M_PI - a);
	v->ah.wallhit_x = 0;
	v->ah.wallhit_y = 0;
	v->ah.found_hit = 0;
	set_ray_booleans(v, i, a);
	v->rays[i].angle = a;
	v->ah.yi = floor(v->player.y / v->tile_size) * v->tile_size;
	if (v->rays[i].is_dn)
		v->ah.yi += v->tile_size;
	v->ah.xi = v->player.x + (v->player.y - v->ah.yi) / tan(aa);
	v->ah.ystep = v->tile_size;
	if (v->rays[i].is_up)
		v->ah.ystep *= -1;
	v->ah.xstep = v->tile_size / tan(aa);
	if (v->rays[i].is_le && v->ah.xstep > 0)
		v->ah.xstep *= -1;
	if (v->rays[i].is_ri && v->ah.xstep < 0)
		v->ah.xstep *= -1;
}

void	pp(t_vars *v, int x, int y, int color)
{
	t_input_re	r;

	r.pto_sup_esq.x = x;
	r.pto_sup_esq.y = y;
	r.altura = 3;
	r.largura = 3;
	r.cor = color;
	r.borda = 0;
	r.cor_borda = GREY;
	g_plot_rect_img(v, r);
}

void	horizontal_dist(t_vars *v, int i)
{
	double ajy;

	ajy = 0;
	if (v->rays[i].is_dn)
		ajy++;
	if (v->rays[i].is_up)
		ajy--;
	v->ah.next_xi = v->ah.xi;
	v->ah.next_yi = v->ah.yi;
	while (1)
	{
		if (u_wall_hit(v, v->ah.next_xi, v->ah.next_yi + ajy))
		{
			v->ah.found_hit = 1;
			v->ah.wallhit_x = v->ah.next_xi;
			v->ah.wallhit_y = v->ah.next_yi;
			break ;
		}
		else
		{
			v->ah.next_xi += v->ah.xstep;
			v->ah.next_yi += v->ah.ystep;
		}
	}
}
