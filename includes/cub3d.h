/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:04:35 by user42            #+#    #+#             */
/*   Updated: 2021/02/10 15:41:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/errno.h>
#include <math.h>


// FF transparente    00 Opaco
// ========= DEFINES ======================
# define ABS(a) (((a) < 0) ? -(a) : (a))
# define WHITE 0x00FFFFFF
# define RED 0x80F00000
# define GREEN 0xFF00FF80
# define BLUE 0x000000FF
# define BLACK 0x00000000
# define GREY 0x008c8c8c
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
	WRONG_ARGS,
	INVALID_CMD,
	INVALID_RES,
	INVALID_CEILING,
	INVALID_FLOOR,
	DUP_TEX,
	WALL_ERROR,
	INVALID_MAP_CHAR,
	INVALID_PLAYER,
	INVALID_MAP_SIZE,
	SPACE_ERROR
};
static char error[][50] = 
{
	"Zero\n",
	"Nome de arquivo invalido\n",
	"Argumentos devem ser [nome do arquivo] [--save]\n",
	"Comando invalido no arquivo .cub\n",
	"Invalid resolution\n",
	"Invalid ceiling\n",
	"Invalid floor\n",
	"Duplicated texture cfg\n",
	"Map not enclosed by walls\n",
	"Invalid char in map[' ',0,1,2,N,S,E,W]\n",
	"Invalid number of players\n",
	"Invalid map size (at least 3x3)\n",
	"Map has breaches\n"

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

typedef struct s_cor{
	int r;
	int g;
	int b;
} t_cor;

typedef struct s_cfg{
	t_pto res;
	t_cor ceiling;
	t_cor floor;
	char *no_tex;
	char *so_tex;
	char *ea_tex;
	char *we_tex;
	char *sprite_tex;
	int all_set;
} t_cfg;

typedef struct s_tela {
	void	*id;
	void	*p;
	int		b;
	int		s_line;
	int		end;
}	t_tela;
	
typedef struct s_player {
	int		x;
	int		y;
	int		radius;
	int		turn_dir;
	int		walk_dir;
	float	angle;
	int		move_speed;
	int		rotation_speed;
}			t_player;

typedef struct s_vars {
	void			*mlx;
	void			*win;
	t_input_rect	r1;
	t_input_rect	r2;
	t_sprite		sprite;
	t_cfg			cfg;
	int				line_count;
	int				line_cfg;
	char			**map;
	char			**map_temp;
	int				map_num_rows;
	int				map_num_cols;
	int				tile_size;
	int				window_width;
	int				window_height;
	t_tela			t; 
	t_player		player;

}	t_vars;

// ========================================


// ========= FUNCTIONS ====================
int funcao_a(int a);
int funcao_b(int b);

void	g_plot_line(t_vars *vars, t_pto p0, t_pto p1, unsigned int cor);
void	g_plot_rect(t_vars *vars, t_input_rect ip);
int		p_parse_arquivo(t_vars *vars, char *arquivo);
void	p_parse_argumentos(int argc, char *argv[]);
void	p_init_cfg(t_vars *vars);
void	p_print_cfg(t_vars *vars);
void	p_parse_config(t_vars *vars, int fd);
void	sai(int codigo);
void	p_escolhe_parse(t_vars *vars, char *str);
void	p_parse_r(t_vars *vars, char *str);
void	u_free_array_bi(char **s);
void	p_parse_c(t_vars *vars, char *str);
int		u_check_palavras(char **palavras, int *ii);
void	p_parse_f(t_vars *vars, char *str);
void	p_parse_S(t_vars *vars, char *str);
void	p_parse_SO(t_vars *vars, char *str);
void	p_parse_NO(t_vars *vars, char *str);
void	p_parse_WE(t_vars *vars, char *str);
void	p_parse_EA(t_vars *vars, char *str);
void	p_conta_linhas(t_vars *vars, char *arquivo);
void	p_parse_map(t_vars *vars, int fd);
void	p_normaliza_map(t_vars *var);
void	u_print_map(char **map_temp);
void	p_valida_map(t_vars *vars);
void	check_first_last_col(t_vars *vars);
void	check_first_last_line(t_vars *vars);
void	check_valid_chars_players(t_vars *vars);
int		c(t_vars *vars, int i, int j);
void	check_around_spaces_orto(t_vars *vars);
void	check_around_spaces_diag(t_vars *vars);
void	render_map(t_vars *vars);
void	u_free_map(t_vars *vars);
void	check_resolution(t_vars *vars);
void	g_image_init(t_vars *v);
void	g_pixel_put_img(t_tela t, int x, int y, int color);
void	g_plot_line_img(t_vars *vars, t_pto p0, t_pto p1, unsigned int cor);
void	g_plot_rect_aux_img(t_vars *vars, t_input_rect ip, unsigned int color);
void	g_plot_rect_img(t_vars *vars, t_input_rect ip);
void	p_init_player(t_vars *vars);
void	draw(t_vars *vars);
void	render_player(t_vars *vars);

// ========================================
