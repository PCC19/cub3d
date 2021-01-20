/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:04:35 by user42            #+#    #+#             */
/*   Updated: 2021/01/20 22:21:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include <stdio.h>

// ========= DEFINES ======================
#define ABS(a) (((a) < 0) ? -(a) : (a))
#define WHITE 0xFFFFFF
#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF
#define BLACK 0x000000
// ========================================


// ========= STRUCTS ======================
struct s_ponto {
	int x;
	int y;
};

typedef struct s_ponto t_pto;

struct s_var_line {
	int dx;
	int sx;
	int dy;
	int sy;
	int err;
	int e2;
	};

typedef struct s_var_line t_var_line;

struct t_mw_ptr {
	void *mlx_ptr;
	void *win_ptr;
};

struct s_input_rect {
	t_pto pto_sup_esq;
	int largura;
	int altura;
	int cor;
	int borda;
	int cor_borda;

};
typedef struct s_input_rect t_input_rect;

// ========================================


// ========= FUNCTIONS ====================
int funcao_a(int a);
int funcao_b(int b);

void	g_plot_line(struct t_mw_ptr mw_ptr, t_pto p0, t_pto p1, int cor);
void	g_plot_rect(struct t_mw_ptr mw_ptr, t_input_rect ip);
// ========================================
