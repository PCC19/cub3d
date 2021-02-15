/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_plot_rect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:15:16 by user42            #+#    #+#             */
/*   Updated: 2021/02/15 16:48:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	g_plot_rect_aux(t_vars *vars, t_input_re ip, unsigned int color)
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
		g_plot_line(vars, ini, fin, color);
		ini.y++;
		fin.y++;
		i++;
	}
}

void	g_plot_rect(t_vars *vars, t_input_re ip)
{
	t_input_re a;

	a = ip;
	if (ip.borda > 0)
	{
		g_plot_rect_aux(vars, ip, ip.cor_borda);
		a.pto_sup_esq.x += ip.borda;
		a.pto_sup_esq.y += ip.borda;
		a.altura = a.altura - (2 * ip.borda);
		a.largura = a.largura - (2 * ip.borda);
	}
	g_plot_rect_aux(vars, a, ip.cor);
}
