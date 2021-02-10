/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:37:26 by user42            #+#    #+#             */
/*   Updated: 2021/02/10 16:30:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_player(t_vars *vars)
{
	t_input_rect	r;
	t_pto p0;
	t_pto p1;

	r.pto_sup_esq.x = vars->player.x - vars->player.radius;
	r.pto_sup_esq.y = vars->player.y - vars->player.radius;
	r.altura = vars->player.radius * 2 + 1;
	r.largura = vars->player.radius * 2 + 1;
	r.cor = RED;
	r.borda = 0;
	r.cor_borda = GREY;
	g_plot_rect_img(vars, r);
	p0.x = vars->player.x;
	p0.y = vars->player.y;
	p1.x = p0.x + 30 * cos(vars->player.angle);
	p1.y = p0.y + 30 * sin(vars->player.angle);
	g_plot_line_img(vars, p0, p1, RED);

}