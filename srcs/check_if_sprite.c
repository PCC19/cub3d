/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:20:25 by user42            #+#    #+#             */
/*   Updated: 2021/02/16 19:14:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_if_sprite(t_vars *v, int i)
{
	int x;
	int y;
	int ajx;
	int ajy;
	
	ajx = 0;
	ajy = 0;
	if (v->rays[i].is_dn)
		ajy++;
	if (v->rays[i].is_up)
		ajy--;
	if (v->rays[i].is_ri)
		ajx++;
	if (v->rays[i].is_le)
		ajx--;
	x = (int)floor(v->rays[i].wallhit_x / v->tile_size);
	y = (int)floor(v->rays[i].wallhit_y / v->tile_size);

	if (ft_is_in(v->map[x + ajx][y + ajy], "22"))
		v->rays[i].is_sprite = 1;
}
