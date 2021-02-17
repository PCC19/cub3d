/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_init_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 18:47:04 by user42            #+#    #+#             */
/*   Updated: 2021/02/17 23:09:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	p_init_cfg(t_vars *v)
{
	v->cfg.res.x = -1;
	v->cfg.res.y = -1;
	v->cfg.ceiling.r = -1;
	v->cfg.ceiling.g = -1;
	v->cfg.ceiling.b = -1;
	v->cfg.floor.r = -1;
	v->cfg.floor.g = -1;
	v->cfg.floor.b = -1;
	v->cfg.tex_file[0] = 0;
	v->cfg.tex_file[1] = 0;
	v->cfg.tex_file[2] = 0;
	v->cfg.tex_file[3] = 0;
	v->cfg.tex_file[4] = 0;
	v->cfg.all_set = 0;
	v->line_count = 0;
	v->line_cfg = 0;
	v->window_width = 500;
	v->window_height = 500;
}

void	p_print_cfg(t_vars *v)
{
	printf("======================\n");
	printf("res.x: %d\t\tres.y %d\n", v->cfg.res.x, v->cfg.res.y);
	printf("ceiling r: %d\t\t g; %d\t\t b: %d\n",
			v->cfg.ceiling.r, v->cfg.ceiling.g, v->cfg.ceiling.b);
	printf("floor r: %d\t\t g; %d\t\t b: %d\n",
			v->cfg.floor.r, v->cfg.floor.g, v->cfg.floor.b);
	printf("no_tex: %s\n", v->cfg.tex_file[0]);
	printf("so_tex: %s\n", v->cfg.tex_file[1]);
	printf("ea_tex: %s\n", v->cfg.tex_file[2]);
	printf("we_tex: %s\n", v->cfg.tex_file[3]);
	printf("sprite_tex: %s\n", v->cfg.tex_file[4]);
	printf("all_set: %d\n", v->cfg.all_set);
	printf("line_count: %d\n", v->line_count);
	printf("line_cfg: %d\n", v->line_cfg);
	printf("======================\n");
}
