/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 00:24:44 by user42            #+#    #+#             */
/*   Updated: 2021/02/15 16:50:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	plot_bloco(t_vars *vars, int i, int j, int color)
{
	t_input_re	r;

	r.pto_sup_esq.x = j * vars->tile_size * vars->sf;
	r.pto_sup_esq.y = i * vars->tile_size * vars->sf;
	r.altura = vars->tile_size * vars->sf;
	r.largura = vars->tile_size * vars->sf;
	r.cor = color;
	r.borda = 1;
	r.cor_borda = GREY;
	g_plot_rect_img(vars, r);
}

void	render_map(t_vars *vars)
{
	int				i;
	int				j;

	i = 0;
	while (i < vars->map_num_rows)
	{
		j = 0;
		while (j < vars->map_num_cols)
		{
			if (vars->map[i][j] == '1')
				plot_bloco(vars, i, j, BLACK);
			if (vars->map[i][j] == ' ')
				plot_bloco(vars, i, j, GREY);
			if (ft_is_in(vars->map[i][j],"02NSEW"))
				plot_bloco(vars, i, j, WHITE);
			j++;
		}
		i++;
	}
//	mlx_put_image_to_window(vars->mlx, vars->win, vars->t.id, 0, 0);
}
