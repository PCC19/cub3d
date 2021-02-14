/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_clear_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 16:54:18 by user42            #+#    #+#             */
/*   Updated: 2021/02/14 17:00:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	u_clear_screen(t_vars *v, int x, int y, int altura, int largura)
{
	t_input_rect	r;

	r.pto_sup_esq.x = x;
	r.pto_sup_esq.y = y;
	r.altura = altura - 1;
	r.largura = largura - 1;
	r.cor = BLACK;
	r.borda = 0;
	r.cor_borda = GREY;
	g_plot_rect_img(v, r);
}
