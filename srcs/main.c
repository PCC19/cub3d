/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:06:47 by user42            #+#    #+#             */
/*   Updated: 2021/01/21 23:03:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include "cub3d.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int key_hook (int keycode, t_vars *vars)
{
	printf("Hello Baby !!\n");
//	printf("p %p\n",mw->mlx_ptr);
	printf("keycode: %d\n",keycode);
	if (keycode == RIGHT)
	{
		vars->r1.pto_sup_esq.x ++;
		g_plot_rect(vars, vars->r1);

	}

	return 0;
}

int main()
{
	//void *mlx_ptr;
	//void *win_ptr;
	//struct t_mw_ptr mw_ptr;
	//t_input_rect ip;
	t_vars vars;


	// Inicializa pontos para teste da linha
	t_pto p0;
	t_pto p1;
	// fim dos pontos

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx,500,500,"Hello World !");
	mlx_pixel_put(vars.mlx, vars.win,250,250,0xFFFFFF);
	
	// Draw a line
	p0.x = 100;
	p0.y = 100;
	p1.x = 200;
	p1.y = 300;
	g_plot_line(&vars, p0, p1, GREEN);
	// Draw a rectangle
	vars.r1.pto_sup_esq.x = 150;
	vars.r1.pto_sup_esq.y = 150;
	vars.r1.largura = 50;
	vars.r1.altura = 30;
	vars.r1.cor = RED;
	vars.r1.borda = 10;
	vars.r1.cor_borda = WHITE;
	g_plot_rect(&vars, vars.r1);

	printf("a: %d   b;  %d\n",funcao_a(5),funcao_b(5));
	printf("a: %d   b;  %d\n",funcao_a(5),funcao_b(5));

	mlx_key_hook(vars.win, key_hook, &vars);

	mlx_loop(vars.mlx);
}

