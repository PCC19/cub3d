/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 00:25:07 by user42            #+#    #+#             */
/*   Updated: 2021/02/09 00:32:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_resolution(t_vars *vars)
{
	mlx_get_screen_size(vars->mlx, &vars->window_width, &vars->window_height);
	if (vars->cfg.res.x <= vars->window_width)
		vars->window_width = vars->cfg.res.x;
	if (vars->cfg.res.y < vars->window_height)
		vars->window_height = vars->cfg.res.y;
}
