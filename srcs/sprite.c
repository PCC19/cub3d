/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:07:36 by user42            #+#    #+#             */
/*   Updated: 2021/02/19 01:07:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sprites(t_vars *v, int i, int x0)
{
	v->s.in.x = x0 - v->sprites[i].width / 2;
	v->s.in.y = (v->window_height / 2) - (v->sprites[i].height / 2);
	v->s.c.x = 0;
	while (v->s.c.x < v->sprites[i].width)
	{
		v->s.c.y = 0;
		v->s.t.x = v->s.c.x * v->tex[4].w / v->sprites[i].width;
		v->s.ray_sprite = (v->s.in.x + v->s.c.x) / 1;
		while (v->s.c.y < v->sprites[i].height)
		{
			v->s.t.y = v->s.c.y * v->tex[4].h / v->sprites[i].height;
			if (u_is_inside(v, (v->s.in.x + v->s.c.x),
				(v->s.in.y + v->s.c.y)) &&
				v->sprites[i].dist < v->rays[(int)(v->s.ray_sprite)].dist)
			{
				v->s.cor = *(uint*)(v->tex[4].p +
							(int)((v->s.t.y * v->tex[4].w) + v->s.t.x) * 4);
				if (v->s.cor != 0)
					g_pixel_put_img(v->t, v->s.in.x + v->s.c.x,
									v->s.in.y + v->s.c.y, v->s.cor);
			}
			v->s.c.y++;
		}
		v->s.c.x++;
	}
}

void	calculate_sprites(t_vars *v, int i)
{
	int		xi;
	double	dist_proj_plane;

	dist_proj_plane = (v->window_height / 2) / tan(v->fov / 2);
	xi = 0;
	v->sprites[i].angle = atan2((v->sprites[i].y - v->player.y),
								(v->sprites[i].x - v->player.x));
	v->sprites[i].angle_dif = (v->player.angle - v->sprites[i].angle);
	if (v->sprites[i].angle_dif < -1 * M_PI)
		v->sprites[i].angle_dif += 2 * M_PI;
	if (v->sprites[i].angle_dif > M_PI)
		v->sprites[i].angle_dif -= 2 * M_PI;
	v->sprites[i].angle_dif = fabs(v->sprites[i].angle_dif);
	v->sprites[i].dist *= (cos(v->sprites[i].angle_dif));
	if (v->sprites[i].angle_dif < v->fov / 2)
	{
		v->sprites[i].height = (v->tile_size * dist_proj_plane /
								v->sprites[i].dist);
		v->sprites[i].width = (v->sprites[i].height * v->tex[4].w /
								v->tex[4].h);
		xi = tan(v->sprites[i].angle - v->player.angle) * dist_proj_plane +
				(v->window_width / 2);
		draw_sprites(v, i, xi);
	}
}

void	calc_dist_sprites(t_vars *v)
{
	int i;

	i = 0;
	while (i < v->n_sprites)
	{
		v->sprites[i].dist = dist(v->player.x, v->player.y,
								v->sprites[i].x, v->sprites[i].y);
		i++;
	}
}

void	sort_sprites(t_vars *v)
{
	t_spr	aux;
	int		i;
	int		j;

	i = 0;
	while (i < v->n_sprites - 1)
	{
		j = i + 1;
		while (j < v->n_sprites)
		{
			if (v->sprites[i].dist < v->sprites[j].dist)
			{
				aux = v->sprites[i];
				v->sprites[i] = v->sprites[j];
				v->sprites[j] = aux;
			}
			j++;
		}
		i++;
	}
}

void	put_sprites(t_vars *v)
{
	int i;

	i = 0;
	calc_dist_sprites(v);
	sort_sprites(v);
	while (i < v->n_sprites)
	{
		calculate_sprites(v, i);
		i++;
	}
}
