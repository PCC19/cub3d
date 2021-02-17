/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_init_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 23:07:51 by user42            #+#    #+#             */
/*   Updated: 2021/02/17 17:20:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	p_init_vars(t_vars *vars)
{
	vars->fov = 60 * M_PI / 180;
//	vars->num_rays = 10;
//	vars->strip_width = (vars->window_width / vars->num_rays);
	vars->strip_width = 1;
	vars->num_rays = vars->window_width / vars->strip_width;
	vars->sf = 0.3;
}
