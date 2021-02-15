/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_image_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:38:06 by user42            #+#    #+#             */
/*   Updated: 2021/02/15 16:51:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	g_image_init (t_vars *v)
{
	v->t.id = mlx_new_image(v->mlx, v->window_width, v->window_height);
	v->t.p = mlx_get_data_addr(v->t.id, &v->t.b, &v->t.s_line, &v->t.end);
}

void	g_pixel_put_img(t_tela t, int x, int y, int color)
{
	*((unsigned int*)t.p + (t.s_line / 4 * y + x)) = (unsigned int) color;
}

void	g_plot_line_img(t_vars *vars, t_pto p0, t_pto p1, unsigned int cor)
{
	t_var_line v;

	v.dx = ABS(p1.x - p0.x);
	v.sx = p0.x < p1.x ? 1 : -1;
	v.dy = -ABS(p1.y - p0.y);
	v.sy = p0.y < p1.y ? 1 : -1;
	v.err = v.dx + v.dy;
	while (1)
	{
		g_pixel_put_img(vars->t, p0.x, p0.y, cor);
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

void	g_plot_rect_aux_img(t_vars *vars, t_input_re ip, unsigned int color)
{
	int		i;
	t_pto	ini;
	t_pto	fin;

	ini.x = ip.pto_sup_esq.x;
	ini.y = ip.pto_sup_esq.y;
	fin.x = ini.x + ip.largura;
	fin.y = ini.y;
	i = 0;
	while (i < ip.altura)
	{
		g_plot_line_img(vars, ini, fin, color);
		ini.y++;
		fin.y++;
		i++;
	}
}

void	g_plot_rect_img(t_vars *vars, t_input_re ip)
{
	t_input_re a;

	a = ip;
	if (ip.borda > 0)
	{
		g_plot_rect_aux_img(vars, ip, ip.cor_borda);
		a.pto_sup_esq.x += ip.borda;
		a.pto_sup_esq.y += ip.borda;
		a.altura = a.altura - (2 * ip.borda);
		a.largura = a.largura - (2 * ip.borda);
	}
	g_plot_rect_aux_img(vars, a, ip.cor);
}
