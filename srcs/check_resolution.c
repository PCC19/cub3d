/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 00:25:07 by user42            #+#    #+#             */
/*   Updated: 2021/02/19 04:23:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_resolution(t_vars *v)
{
	mlx_get_screen_size(v->mlx, &v->window_width, &v->window_height);
	if (v->cfg.res.x <= v->window_width)
		v->window_width = v->cfg.res.x;
	if (v->cfg.res.y < v->window_height)
		v->window_height = v->cfg.res.y;
}
