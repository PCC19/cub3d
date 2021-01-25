/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_plot_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:06:26 by user42            #+#    #+#             */
/*   Updated: 2021/01/25 00:11:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	g_plot_line(t_vars *vars, t_pto p0, t_pto p1, unsigned int cor)
{
	t_var_line v;

	v.dx = ABS(p1.x - p0.x);
	v.sx = p0.x < p1.x ? 1 : -1;
	v.dy = -ABS(p1.y - p0.y);
	v.sy = p0.y < p1.y ? 1 : -1;
	v.err = v.dx + v.dy;
	while (1)
	{
		mlx_pixel_put(vars->mlx, vars->win, p0.x, p0.y, cor);
		if (p0.x == p1.x && p0.y == p1.y)
			break ;
		v.e2 = 2 * v.err;
		if (v.e2 >= v.dy)
		{
			v.err += v.dy;
			p0.x += v.sx;
		}
		if (v.e2 <= v.dx)
		{
			v.err += v.dx;
			p0.y += v.sy;
		}
	}
}
