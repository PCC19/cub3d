/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_init_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 18:47:04 by user42            #+#    #+#             */
/*   Updated: 2021/02/15 16:01:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void p_init_cfg(t_vars *vars)
{
	vars->cfg.res.x = -1;
	vars->cfg.res.y = -1;
	vars->cfg.ceiling.r = -1;
	vars->cfg.ceiling.g = -1;
	vars->cfg.ceiling.b = -1;
	vars->cfg.floor.r = -1;
	vars->cfg.floor.g = -1;
	vars->cfg.floor.b = -1;
	vars->cfg.tex_file[0] = 0;
	vars->cfg.tex_file[1] = 0;
	vars->cfg.tex_file[2] = 0;
	vars->cfg.tex_file[3] = 0;
	vars->cfg.tex_file[4] = 0;
	vars->cfg.all_set = 0;
	vars->line_count = 0;
	vars->line_cfg = 0;
	vars->window_width = 500;
	vars->window_height = 500;
}

void p_print_cfg(t_vars *vars) // APAGAR ESTA FUNCAO !!!
{
	printf("======================\n");
	printf("res.x: %d\t\tres.y %d\n",vars->cfg.res.x, vars->cfg.res.y);
	printf("ceiling r: %d\t\t g; %d\t\t b: %d\n",vars->cfg.ceiling.r, vars->cfg.ceiling.g, vars->cfg.ceiling.b);	
	printf("floor r: %d\t\t g; %d\t\t b: %d\n",vars->cfg.floor.r, vars->cfg.floor.g, vars->cfg.floor.b);	
	printf("no_tex: %s\n",vars->cfg.tex_file[0]);
	printf("so_tex: %s\n",vars->cfg.tex_file[1]);
	printf("ea_tex: %s\n",vars->cfg.tex_file[2]);
	printf("we_tex: %s\n",vars->cfg.tex_file[3]);
	printf("sprite_tex: %s\n",vars->cfg.tex_file[4]);
	printf("all_set: %d\n",vars->cfg.all_set);
	printf("line_count: %d\n",vars->line_count);
	printf("line_cfg: %d\n",vars->line_cfg);
	printf("======================\n");
}

