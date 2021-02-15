/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:20:25 by user42            #+#    #+#             */
/*   Updated: 2021/02/15 17:26:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_if_sprite(t_vars *v, int i)
{
	int x;
	int y;
	
	x = floor(v->rays[i].wallhit_x / v->tile_size);
	y = floor(v->rays[i].wallhit_y / v->tile_size);

	if (ft_is_in(v->map[x][y], "2"))
		v->rays[i].is_sprite = 1;
}
