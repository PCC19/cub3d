/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_minimap_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:40:08 by user42            #+#    #+#             */
/*   Updated: 2021/02/19 22:45:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_minimap_size(t_vars *v)
{
	v->draw_minimap = 1;
	if (v->tile_size * v->map_num_cols * v->sf >= v->window_width)
		v->draw_minimap = 0;
	if (v->tile_size * v->map_num_rows * v->sf >= v->window_height)
		v->draw_minimap = 0;
}
