/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 23:39:09 by user42            #+#    #+#             */
/*   Updated: 2021/02/13 16:48:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
void	render_ray1(t_vars *vars, double angle, int color)
{
	t_pto	p0;
	t_pto	p1;
	int		len_ray;

	len_ray = 60;
	p0.x = vars->player.x;
	p0.y = vars->player.y;
	p1.x = p0.x + len_ray * cos(angle);
	p1.y = p0.y + len_ray * sin(angle);
	if (u_is_inside(vars, p1.x, p1.y))
		g_plot_line_img(vars, p0, p1, color);
}
*/
void	render_ray(t_vars *vars, int x, int y, int color)
{
	t_pto	p0;
	t_pto	p1;
	int		len_ray;

	len_ray = 60;
	p0.x = vars->player.x;
	p0.y = vars->player.y;
	p1.x = x;
	p1.y = y;
	if (u_is_inside(vars, p1.x, p1.y))
		g_plot_line_img(vars, p0, p1, color);
}
