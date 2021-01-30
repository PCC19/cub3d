/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:06:47 by user42            #+#    #+#             */
/*   Updated: 2021/01/30 18:08:15 by user42           ###   ########.fr       */
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

int key_hook (int keycode, t_vars *vars)
{
	printf("Hello Baby !!\n");
//	printf("p %p\n",mw->mlx_ptr);
	printf("keycode: %d\n",keycode);
	t_input_rect r;

	r = vars->r1;
	r.borda = 0;
	r.cor  = BLACK;
	g_plot_rect(vars, r);

	if (keycode == RIGHT)
	{
		vars->r1.pto_sup_esq.x ++;
		g_plot_rect(vars, vars->r1);
	}
	if (keycode == LEFT)
	{
		vars->r1.pto_sup_esq.x --;
		g_plot_rect(vars, vars->r1);
	}
	if (keycode == UP)
	{
		vars->r1.pto_sup_esq.y --;
		g_plot_rect(vars, vars->r1);
	}
	if (keycode == DN)
	{
		vars->r1.pto_sup_esq.y ++;
		g_plot_rect(vars, vars->r1);
	}

	return 0;
}

int main(int argc, char **argv)
//int main()
{
	t_vars vars;

	p_parse_argumentos(argc, argv);
	printf("argc: %d argv: %s\n",argc,argv[1]);
	printf("file: %s\n",argv[1]);
	p_parse_arquivo(&vars, argv[1]);


	// Inicializa pontos para teste da linha
	t_pto p0;
	t_pto p1;
	// fim dos pontos

	// Inicializa lib e window
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx,500,500,"Hello World !");
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
	p = mlx_get_data_addr(vars.sprite.img, &a, &b, &c);
	printf("ptr: %p  bits per pixel: %d, size_line: %d endian: %d\n",p,a,b,c);
	for (int i  = 0;i<64*8; i++)
		//*(p + 4*i) = 0x0F;
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
}

