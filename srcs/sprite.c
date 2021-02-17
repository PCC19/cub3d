/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:07:36 by user42            #+#    #+#             */
/*   Updated: 2021/02/17 16:11:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		printf("sprite[%d] x: %f\t y: %f\t dist: %f angle: %f\t dif: %f\n",i,v->sprites[i].x, v->sprites[i].y, v->sprites[i].dist, v->sprites[i].angle, v->sprites[i].angle_dif);
	printf("fov/2 :%f\n",v->fov / 2);	
	if (v->sprites[i].angle_dif < v->fov / 2)
	{
		v->sprites[i].height = (v->tile_size * dist_proj_plane / 
								v->sprites[i].dist);
	
		v->sprites[i].width = (v->sprites[i].height * v->tex[4].w / v->tex[4].h);
	
		xi = tan(v->sprites[i].angle - v->player.angle) * dist_proj_plane +
				(v->window_width / 2);
	
		//printf("sprite[%d] x: %f\t y: %f\t dist: %f angle: %f\t dif: %f\n",i,v->sprites[i].x, v->sprites[i].y, v->sprites[i].dist, v->sprites[i].angle, v_>sprites[i].angle_dif);
		//draw_sprite(v, i, xi);
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

			// draw sprite

