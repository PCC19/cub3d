/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 00:16:16 by user42            #+#    #+#             */
/*   Updated: 2021/02/18 23:05:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		draw(t_vars *v)
{
	u_clear_screen(v, v->window_height, v->window_width);
	render_floor_ceiling(v);
	cast_all_rays(v);
	render3d(v);
	put_sprites(v);
	u_clear_screen(v, v->window_height * v->sf, v->window_width * v->sf);
	render_map(v);
	render_player(v);
	render_all_rays(v);
	if (v->argc == 3)
	{
		save_bmp_file(v);
		free_and_exit(v);
	}
	else
	{
		if (!v->win)
			v->win = mlx_new_window(v->mlx, v->window_width,
								v->window_height, "=== CUB3D by pcunha ===");
		mlx_put_image_to_window(v->mlx, v->win, v->t.id, 0, 0);
	}
	return (0);
}
