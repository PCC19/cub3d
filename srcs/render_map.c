/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 00:24:44 by user42            #+#    #+#             */
/*   Updated: 2021/02/08 00:51:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_map(t_vars *vars)
{
	int				i;
	int				j;
	t_input_rect	r;

	i = 0;
	while (i < vars->map_num_rows)
	{
		j = 0;
		while (j < vars->map_num_cols)
		{
			r.pto_sup_esq.x = j * vars->tile_size;
			r.pto_sup_esq.y = i * vars->tile_size;
			if (vars->map[i][j] == '1')
				r.cor = BLACK;
			else
				r.cor = WHITE;
			r.largura = vars->tile_size;
			r.altura = vars->tile_size;
			r.borda = 1;
			r.cor_borda = WHITE;
			g_plot_rect(vars, r);
			j++;
		}
		i++;
	}
}
