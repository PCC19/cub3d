/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:06:47 by user42            #+#    #+#             */
/*   Updated: 2021/01/20 22:34:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include "cub3d.h"
#include <stdio.h>
#include <math.h>


int main()
{
	//void *mlx_ptr;
	//void *win_ptr;
	struct t_mw_ptr mw_ptr;
	t_input_rect ip;

	// Inicializa pontos para teste da linha
	t_pto p0;
	t_pto p1;
	// fim dos pontos

	mw_ptr.mlx_ptr = mlx_init();
	mw_ptr.win_ptr = mlx_new_window(mw_ptr.mlx_ptr,500,500,"Hello World !");
	mlx_pixel_put(mw_ptr.mlx_ptr, mw_ptr.win_ptr,250,250,0xFFFFFF);
	
	// Draw a line
	p0.x = 100;
	p0.y = 100;
	p1.x = 200;
	p1.y = 300;
	g_plot_line(mw_ptr, p0, p1, GREEN);
	// Draw a rectangle
	ip.pto_sup_esq.x = 150;
	ip.pto_sup_esq.y = 150;
	ip.largura = 50;
	ip.altura = 30;
	ip.cor = RED;
	ip.borda = 10;
	ip.cor_borda = WHITE;

	g_plot_rect(mw_ptr, ip);


	// Draw filled circle

	printf("a: %d   b;  %d\n",funcao_a(5),funcao_b(5));
	printf("a: %d   b;  %d\n",funcao_a(5),funcao_b(5));
	mlx_loop(mw_ptr.mlx_ptr);
}

