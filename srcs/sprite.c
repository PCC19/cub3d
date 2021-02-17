/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:07:36 by user42            #+#    #+#             */
/*   Updated: 2021/02/17 15:45:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_sprites(t_vars *v, int i)
{
		printf("sprite[%d] x: %f\t y: %f\t dist: %f\n",i,v->sprites[i].x, v->sprites[i].y, v->sprites[i].dist);
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

		// calculate sprites
			// draw sprite

