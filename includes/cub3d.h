/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:04:35 by user42            #+#    #+#             */
/*   Updated: 2021/01/30 17:57:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


// FF transparente    00 Opaco
// ========= DEFINES ======================
# define ABS(a) (((a) < 0) ? -(a) : (a))
# define WHITE 0x00FFFFFF
# define RED 0x80F00000
# define GREEN 0xFF00FF80
# define BLUE 0x000000FF
# define BLACK 0x00000000
# define UP 65362
# define DN 65364
# define LEFT 65361
# define RIGHT 65363
// ========================================


// ========= ERRORS ======================
enum e_error_num
{
	ZERO,
	INVALID_FILENAME,
	WRONG_ARGS
};
static char error[][50] = 
{
	"Zero\n",
	"Nome de arquivo invalido\n",
	"Argumentos devem ser [nome do arquivo] [--save]\n"
};


// ========================================

// ========= STRUCTS ======================
typedef struct s_ponto {
	int x;
	int y;
} t_pto;

typedef struct s_var_line {
	int dx;
	int sx;
	int dy;
	int sy;
	int err;
	int e2;
} t_var_line;

typedef struct s_input_rect {
	t_pto pto_sup_esq;
	int largura;
	int altura;
	unsigned int cor;
	int borda;
	unsigned int cor_borda;

} t_input_rect;

typedef struct s_sprite{
	void *img;
	int width;
	int height;
} t_sprite;

typedef struct s_vars {
	void *mlx;
	void *win;
	t_input_rect r1;
	t_input_rect r2;
	t_sprite sprite;
}	t_vars;

// ========================================


// ========= FUNCTIONS ====================
int funcao_a(int a);
int funcao_b(int b);

void	g_plot_line(t_vars *vars, t_pto p0, t_pto p1, unsigned int cor);
void	g_plot_rect(t_vars *vars, t_input_rect ip);
int		p_parse_arquivo(t_vars *vars, char *arquivo);
void		p_parse_argumentos(int argc, char *argv[]);
// ========================================
