/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_array_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:45:22 by user42            #+#    #+#             */
/*   Updated: 2021/02/17 14:50:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_array_sprites(t_vars *v)
{
	int i;

	v->n_sprites = 0;
	i = 0;
	while (i < 100)
	{
		v->sprites[i].x = 0;
		v->sprites[i].y = 0;
		v->sprites[i].dist = 0;
		v->sprites[i].angle = 0;
		v->sprites[i].visible = 0;
		v->sprites[i].texture = 0;
		i++;
	}
}
