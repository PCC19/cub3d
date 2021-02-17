/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:06:47 by user42            #+#    #+#             */
/*   Updated: 2021/02/17 16:11:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include "cub3d.h"
#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/errno.h>

int loop (t_vars *vars)
{
	//vars->player.x++;
	//vars->player.x--;

	draw(vars);
	return (0);
}

void sai(int codigo)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(error[codigo], 1);
	exit(codigo);
}

int main(int argc, char **argv)
{
	t_vars vars;
	

	// INICIALIZACAO DE TUDO
	p_init_cfg(&vars);
		p_print_cfg(&vars); // APAGAR !!
	// PARSE ARGUMENTOS
	p_parse_argumentos(argc, argv);

	// Inicializa lib e window
	vars.mlx = mlx_init();
		printf("w: %d  h: %d\n",vars.window_width, vars.window_height);
	
	
	// LEITURA DO ARQUIVO E PARSE DOS INPUTS
	printf("argc: %d argv: %s\n",argc,argv[1]);
	printf("file: %s\n",argv[1]);
	p_parse_arquivo(&vars, argv[1]);
		p_print_cfg(&vars); // APAGAR !!
	check_resolution(&vars);
	
	calculate_tile_size(&vars);
	//vars.tile_size = vars.window_width / (vars.map_num_cols);
	//vars.window_height = vars.map_num_rows * vars.tile_size;
		printf("tile size: %d\n",vars.tile_size);
		printf("w: %d  h: %d\n",vars.window_width, vars.window_height);

	// codigo para inicializar player
	p_init_player(&vars);
		printf("Angulo: %f\n",vars.player.angle);
		printf("x: %d   y: %d\n",vars.player.x, vars.player.y);
	// init
	p_init_vars(&vars);
	
	//init sprites
	init_array_sprites(&vars);
	p_parse_array_sprites(&vars);
	put_sprites(&vars);
//	sai(1);
	
	// SETUP (vai virar funcao)
	vars.win = mlx_new_window(vars.mlx,vars.window_width,vars.window_height,"Hello World !");
		printf("w: %d  h: %d\n",vars.window_width, vars.window_height);
	// init img
	g_image_init (&vars);
/*	
	// pixel img
	g_pixel_put_img(vars.t, 499, 175, GREEN);
	// line img
	t_pto p0,p1;
	p0.x = 10;
	p0.y = 10;
	p1.x = 100;
	p1.y = 30;
	g_plot_line_img(&vars, p0, p1, BLUE);
	// rect_img
	// Draw a rectangle
	vars.r1.pto_sup_esq.x = 200;
	vars.r1.pto_sup_esq.y = 30;
	vars.r1.largura = 50;
	vars.r1.altura = 30;
	vars.r1.cor = RED;
	vars.r1.borda = 10;
	vars.r1.cor_borda = WHITE;
	g_plot_rect_img(&vars, vars.r1);
	// render
	mlx_put_image_to_window(vars.mlx, vars.win, vars.t.id, 0, 0);
*/

	int z = cor(255,255,255);
	printf("z: %#8x\n", z);
	printf("ceiling\tr: %d\tg: %d\tb: %d\n",vars.cfg.ceiling.r, vars.cfg.ceiling.g, vars.cfg.ceiling.b);
	
	vars.sprite.img = mlx_xpm_file_to_image(vars.mlx, "/media/sf_cub3d/textures/doom.xpm",&vars.sprite.width, &vars.sprite.height);
	// Carrega texturas
	p_load_textures(&vars);
	
	
	// DRAW()	
	draw(&vars);


 // SHOWCASE DAS TEXTURAS ==========================
	int xx = 0;
	int yy = 0;
	uint cc = 0;
	for (int jj = 0; jj < 5;jj++)
	{
		for (xx = 0; xx < 64; xx++)
		{
			for (yy = 0; yy < 64; yy++)
			{
				cc = *(uint*)(vars.tex[jj].p + (yy * 64 + xx)*4);
				g_pixel_put_img(vars.t, xx + jj * 100,yy, cc);
			}
		}
		mlx_put_image_to_window(vars.mlx, vars.win, vars.t.id, 0, 0);
	}
 // END SHOWCASE DAS TEXTURAS ==========================


	// SAVE BMP
	if (argc == 3)
		save_bmp_file(&vars);

	mlx_key_hook(vars.win, key_hook, &vars);
	//mlx_loop_hook(vars.mlx, loop, &vars);
	mlx_loop(vars.mlx);
	u_free_map(&vars);


/*
	// Inicializa pontos para teste da linha
	t_pto p0;
	t_pto p1;
	// fim dos pontos

	// Draw pixel
	mlx_pixel_put(vars.mlx, vars.win,250,250,0xFFFFFF);
	// Draw a line
	p0.x = 100;
	p0.y = 100;
	p1.x = 200;
	p1.y = 300;
	g_plot_line(&vars, p0, p1, GREEN);
	// Draw a rectangle
	vars.r1.pto_sup_esq.x = 200;
	vars.r1.pto_sup_esq.y = 400;
	vars.r1.largura = 50;
	vars.r1.altura = 30;
	vars.r1.cor = RED;
	vars.r1.borda = 10;
	vars.r1.cor_borda = WHITE;
	g_plot_rect(&vars, vars.r1);
	// Print image
	vars.sprite.img = mlx_xpm_file_to_image(vars.mlx, "/media/sf_cub3d/textures/pillar.xpm",&vars.sprite.width, &vars.sprite.height);
	//a->img = mlx_xpm_file_to_image(vars.mlx, "/media/sf_cub3d/textures/pillar.xpm",&vars.sprite->a.width, &vars.sprite->a.height);
	//a->img = mlx_xpm_file_to_image(vars.mlx, "/media/sf_cub3d/textures/pillar.xpm",&vars.sprite->a.width, &vars.sprite->a.height);
	if (vars.sprite.img)
		mlx_put_image_to_window(vars.mlx, vars.win, vars.sprite.img, 100, 300);
	else
		printf("erro na leitura do arquivo");
//	printf("h: %d   w: %d\n",vars.sprite->a.height,vars.sprite->a.width);
	// Draw inside a->img
	int a,b,c;
	a = 0; b = 0; c = 0;
	char *p;
	p = mlx_get_data_addr(vars.sprite.img, &a, &bprintf("i: %d\ta: %d\tb: %d\t c:%d\n",i,a,b,c);

	printf("ptr: %p  bits per pixel: %d, size_line: %d endian: %d\n",p,a,b,c);
	for (int i  = 0;i<64*8; i++)
		*(p + 4*i) = 0x0F;
		*((unsigned int*)p+i) = (unsigned int) GREEN;
	mlx_put_image_to_window(vars.mlx, vars.win, vars.sprite.img, 200, 0);
	// get_screen_size
	mlx_get_screen_size(vars.mlx, &a, &b);
	printf("a: %d   b;  %d\n",a,b);
	// teste funcao get_color_value	
	unsigned int z= 0;
	z = mlx_get_color_value(vars.mlx, RED);
	printf("z: %#x  cor: %#x\n",z,RED);
	
	// Draw a rectangle
	vars.r2.pto_sup_esq.x = 200;
	vars.r2.pto_sup_esq.y = 400;
	vars.r2.largura = 100;
	vars.r2.altura = 50;
	vars.r2.cor = (unsigned int)RED;
	vars.r2.borda = 0;
	vars.r2.cor_borda = WHITE;
	g_plot_rect(&vars, vars.r2);

	// sequencia de imagens quadradas
	int i = 0;
	void *aa, *ap;
	aa = mlx_new_image(vars.mlx, 100, 100);
	ap = mlx_get_data_addr(aa, &a, &b, &c);
		for (i=0; i<10000; i++)
			*((int*)ap+i) = (unsigned int) BLUE;
	void *bb, *bp;
	int LADO = 400;
	bb = mlx_new_image(vars.mlx, LADO, LADO);
	bp = mlx_get_data_addr(bb, &a, &b, &c);
		for (i=0; i<LADO*LADO; i++)
			*((unsigned int*)bp+i) = (unsigned int) (250*i/(LADO*LADO) << 24  | 120 << 16);
		
	int x = 0;
	int y = 0;
	for (i = 0; i < 5; i++)
	{
//		mlx_put_image_to_window(vars.mlx, vars.win, aa, x + (100*i), y);;
	}
	x = 0;
	for (i = 0; i < 0; i++)
	{
		mlx_put_image_to_window(vars.mlx, vars.win, bb, x + (100*i), y);;
	}
	printf("teste: %d\n", 1 << 3);


	if (vars.sprite.img)
		mlx_put_image_to_window(vars.mlx, vars.win, vars.sprite.img, 200, 400);
	else
		printf("erro na leitura do arquivo");

	printf("a: %d   b;  %d\n",funcao_a(5),funcao_b(5));
	printf("a: %d   b;  %d\n",funcao_a(5),funcao_b(5));

	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
*/
}

