/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:07:36 by user42            #+#    #+#             */
/*   Updated: 2021/02/17 17:32:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	draw_sprites(t_vars *v, int i, int x0)
{
	t_pto			tex;
	t_pto			in;
	t_pto			c;
	uint			color;
	int				ray_sprite;

	in.x = x0 - v->sprites[i].width / 2;
	in.y = (v->window_height / 2) - (v->sprites[i].height / 2);
	c.x = 0;
	while (c.x < v->sprites[i].width)
	{
		c.y = 0;
		tex.x = c.x * v->tex[4].w / v->sprites[i].width;
		ray_sprite = (in.x + c.x) / 1;
		while (c.y < v->sprites[i].height)
		{
			tex.y = c.y * v->tex[4].h / v->sprites[i].height;
			if (u_is_inside(v, (in.x + c.x), (in.y + c.y)) &&
			v->sprites[i].dist < v->rays[(int)(ray_sprite)].dist)
			{
				color = RED;
				//color = *(uint*)(v->tex[4].p + (int)((tex.y * v->tex[4].w) + tex.x) * 4);
				g_pixel_put_img(v->t, in.x + c.x, in.y + c.y, color);
				//(color = get_texture_color(v->tex[sprites], tex.x, tex.y)) ?
				//my_mlx_pixel_put(v->data, in.x + c.x, in.y + c.y, color) : 0;
			}
			c.y++;
		}
		c.x++;
	}
}

void	calculate_sprites(t_vars *v, int i)
{
		//printf("sprite[%d] x: %f\t y: %f\t dist: %f\n",i,v->sprites[i].x, v->sprites[i].y, v->sprites[i].dist);
	
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
	
		v->sprites[i].width = (v->sprites[i].height * v->tex[4].w / v->tex[4].h);
	
		xi = tan(v->sprites[i].angle - v->player.angle) * dist_proj_plane +
				(v->window_width / 2);
	
		printf("sprite[%d] x: %f\t y: %f\t dist: %f angle: %f\t dif: %f\n",i,v->sprites[i].x, v->sprites[i].y, v->sprites[i].dist, deg(v->sprites[i].angle), deg(v->sprites[i].angle_dif));
		printf("x: %d\t\t y: %d\n",v->player.x, v->player.y);
		printf("fov/2 :%f\t player: %f\n",deg(v->fov / 2), deg(v->player.angle));			printf("----------\n");
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
					//printf("sprite[%d] x: %f\t y: %f\t dist: %f\n",i,v->sprites[i].x, v->sprites[i].y, v->sprites[i].dist);
					//printf("aux[%d] x: %f\t y: %f\t dist: %f\n",i,aux.x, aux.y, aux.dist);
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
