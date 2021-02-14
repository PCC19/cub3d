/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 00:16:16 by user42            #+#    #+#             */
/*   Updated: 2021/02/14 17:01:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw(t_vars *vars)
{
	update(vars);
	// RENDER MAP
	u_clear_screen(vars, 0, 0, vars->window_height, vars->window_width);
	render_map(vars);
	render_player(vars);
	cast_all_rays(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->t.id, 0, 0);

}

