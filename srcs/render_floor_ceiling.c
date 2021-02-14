/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_floor_ceiling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:12:31 by user42            #+#    #+#             */
/*   Updated: 2021/02/14 17:39:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_floor_ceiling(t_vars *v)
{
	
	t_input_rect	r;

	r.pto_sup_esq.x = 0;
	r.pto_sup_esq.y = 0;
	r.altura = v->window_height / 2;
	r.largura = v->window_width;
	r.cor =cor(v->cfg.ceiling.r, v->cfg.ceiling.g ,v->cfg.ceiling.b);
	r.borda = 0;
	r.cor_borda = GREY;
	g_plot_rect_img(v, r);
	r.pto_sup_esq.x = 0;
	r.pto_sup_esq.y = v->window_height / 2;
	r.altura = v->window_height / 2;
	r.largura = v->window_width;
	r.cor =cor(v->cfg.floor.r, v->cfg.floor.g ,v->cfg.floor.b);
	r.borda = 0;
	r.cor_borda = GREY;
	g_plot_rect_img(v, r);
}
