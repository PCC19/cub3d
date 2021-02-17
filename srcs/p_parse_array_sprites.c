/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_array_sprites.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:47:38 by user42            #+#    #+#             */
/*   Updated: 2021/02/17 14:57:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	p_parse_array_sprites(t_vars *v)
{
	int xmap;
	int	ymap;

	xmap = 0;
	while (xmap < v->map_num_cols)
	{
		ymap = 0;
		while (ymap < v->map_num_rows)
		{
			if (ft_is_in(v->map[xmap][ymap],"2"))
			{
				v->sprites[v->n_sprites].x = xmap * v->tile_size + 0.5;
				v->sprites[v->n_sprites].y = ymap * v->tile_size + 0.5;
				printf("xs: %f\tb ys: %f\n",v->sprites[v->n_sprites].x, v->sprites[v->n_sprites].y);
				v->n_sprites++;
			}
			ymap++;
		}
		xmap++;
	}
}
