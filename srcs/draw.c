/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 00:16:16 by user42            #+#    #+#             */
/*   Updated: 2021/02/14 18:20:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw(t_vars *v)
{
	update(v);
	// RENDER MAP
	u_clear_screen(v, 0, 0, v->window_height, v->window_width);
	render_floor_ceiling(v);
	render3d(v);
	u_clear_screen(v, 0, 0, v->window_height * v->sf, v->window_width * v->sf);
	render_map(v);
	cast_all_rays(v);
	render_player(v);
	mlx_put_image_to_window(v->mlx, v->win, v->t.id, 0, 0);

}

