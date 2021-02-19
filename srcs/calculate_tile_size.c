/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_tile_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 23:12:59 by user42            #+#    #+#             */
/*   Updated: 2021/02/19 00:23:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_tile_size(t_vars *v)
{
	v->player.x++;
	v->player.x--;
	v->tile_size = 50;
/*
	int a;
	int b;
	a = v->window_width / v->map_num_cols;
	b = v->window_height / v->map_num_rows;
	if (a < b)
	{
		v->tile_size = a;
		v->window_height = v->map_num_rows * v->tile_size;
	}
	else
	{
		v->tile_size = b;
		v->window_width = v->map_num_cols * v->tile_size;
	}
*/
}
