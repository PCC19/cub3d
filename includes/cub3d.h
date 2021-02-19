/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:04:35 by user42            #+#    #+#             */
/*   Updated: 2021/02/19 13:50:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "get_next_line.h"
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/errno.h>
# include <math.h>

# define MAX_RAYS 2000
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
# define AKEY 97
# define DKEY 100
# define WKEY 119
# define SKEY 115
# define ESCKEY 65307

enum	e_error_num
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
	SPACE_ERROR,
	INVALID_TEXTURE_FILE
};
static char g_error[][50] =
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
	"Map has breaches\n",
	"Invalid texture file.\n"

};

typedef struct	s_ponto {
	int			x;
	int			y;
}				t_pto;

typedef struct	s_var_line {
	int			dx;
	int			sx;
	int			dy;
	int			sy;
	int			err;
	int			e2;
}				t_var_line;

typedef struct	s_input_re {
	t_pto		pto_sup_esq;
	int			largura;
	int			altura;
	int			cor;
	int			borda;
	int			cor_borda;

}				t_input_re;

typedef struct	s_sprite{
	void		*img;
	int			width;
	int			height;
}				t_sprite;

typedef struct	s_cor{
	int			r;
	int			g;
	int			b;
}				t_cor;

typedef struct	s_cfg{
	t_pto		res;
	t_cor		ceiling;
	t_cor		floor;
	char		*tex_file[5];
	int			all_set;
}				t_cfg;

typedef struct	s_tela {
	void		*id;
	void		*p;
	int			b;
	int			s_line;
	int			end;
}				t_tela;

typedef struct	s_tex {
	void		*id;
	void		*p;
	int			b;
	int			s_line;
	int			end;
	int			w;
	int			h;
}				t_tex;

typedef struct	s_player {
	int			x;
	int			y;
	int			radius;
	int			turn_dir;
	int			walk_dir;
	double		angle;
	int			move_speed;
	double		rotation_speed;
}				t_player;

typedef struct	s_ray
{
	double		angle;
	double		dist;
	double		wallhit_x;
	double		wallhit_y;
	int			is_dn;
	int			is_up;
	int			is_ri;
	int			is_le;
	int			hit_v;
	int			is_sprite;
	int			tex_idx;
}				t_ray;

typedef struct	s_aux_dist
{
	double		xstep;
	double		ystep;
	double		xi;
	double		yi;
	double		next_xi;
	double		next_yi;
	int			found_hit;
	int			wallhit_x;
	int			wallhit_y;
}				t_aux_dist;

typedef struct	s_aux_render_wall
{
	double		ray_dist;
	double		dist_proj_plane;
	double		proj_strip_height;
	int			wall_strip_height;
	float		ymin;
	float		ymax;
	float		offset_x;
	float		offset_y;
	float		dist_from_top;
	int			idx;
	uint		color;
}				t_aux_render_wall;

typedef struct	s_spr {
	float		x;
	float		y;
	float		dist;
	float		angle;
	float		angle_dif;
	float		height;
	float		width;
	int			visible;
	int			texture;
}				t_spr;

typedef struct	s_aux_draw_sprite {
	t_pto		t;
	t_pto		in;
	t_pto		c;
	uint		cor;
	int			ray_sprite;
}				t_aux_ds;

typedef struct	s_aux_tex {
	double		offset_x;
	double		offset_y;
	double		y;
	double		ymin;
	double		ymax;
	int			idx;
	uint		color;
	int			k;
}				t_aux_tex;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	t_input_re	r1;
	t_input_re	r2;
	t_sprite	sprite;
	t_cfg		cfg;
	int			line_count;
	int			line_cfg;
	char		**map;
	char		**map_temp;
	int			map_num_rows;
	int			map_num_cols;
	int			tile_size;
	int			window_width;
	int			window_height;
	t_tela		t;
	t_player	player;
	t_ray		rays[MAX_RAYS];
	double		fov;
	int			strip_width;
	int			num_rays;
	t_aux_dist	ah;
	t_aux_dist	av;
	float		sf;
	t_tex		tex[5];
	t_spr		sprites[100];
	int			n_sprites;
	t_aux_ds	s;
	t_aux_tex	e;
	int			argc;
	int			draw_minimap;

}				t_vars;

void			init_game(t_vars *v, int argc, char **argv);
void			p_parse_argumentos(int argc, char *argv[]);
void			check_resolution(t_vars *v);
void			p_init_cfg(t_vars *v);
void			p_print_cfg(t_vars *v);
void			p_parse_config(t_vars *vars, int fd);
int				p_parse_arquivo(t_vars *v, char *arquivo);
void			sai(int codigo);
void			p_escolhe_parse(t_vars *vars, char *str);
void			p_parse_r(t_vars *vars, char *str);
void			u_free_array_bi(char **s);
void			p_parse_c(t_vars *vars, char *str);
int				u_check_palavras(char **palavras, int *ii);
void			p_parse_f(t_vars *vars, char *str);
void			p_parse_ss(t_vars *vars, char *str);
void			p_parse_so(t_vars *vars, char *str);
void			p_parse_no(t_vars *vars, char *str);
void			p_parse_we(t_vars *vars, char *str);
void			p_parse_ea(t_vars *vars, char *str);
void			p_conta_linhas(t_vars *vars, char *arquivo);
void			p_parse_map(t_vars *vars, int fd);
void			p_normaliza_map(t_vars *var);
void			p_valida_map(t_vars *vars);
void			check_first_last_col(t_vars *vars);
void			check_first_last_line(t_vars *vars);
void			check_valid_chars_players(t_vars *vars);
int				c(t_vars *vars, int i, int j);
void			check_around_spaces_orto(t_vars *vars);
void			check_around_spaces_diag(t_vars *vars);
void			render_map(t_vars *vars);
void			u_free_map(t_vars *vars);
void			g_image_init(t_vars *v);
void			g_pixel_put_img(t_tela t, int x, int y, int color);
void			g_plot_line_img(t_vars *vars, t_pto p0, t_pto p1,
															unsigned int cor);
void			g_plot_re_aux_img(t_vars *vars, t_input_re ip,
															unsigned int color);
void			g_plot_rect_img(t_vars *vars, t_input_re ip);
void			p_init_player(t_vars *v);
int				draw(t_vars *v);
void			render_player(t_vars *vars);
double			u_norm_angle(double a);
int				key_hook (int keycode, t_vars *vars);
int				u_wall_hit(t_vars *vars, double x, double y);
void			p_init_vars(t_vars *vars);
void			render_ray(t_vars *vars, int x, int y, int color);
void			cast_ray(t_vars *vars, int i, double angle);
void			cast_all_rays(t_vars *vars);
int				u_is_inside(t_vars *vars, double x, double y);
void			set_ray_booleans(t_vars *v, int i, double angle);
void			horizontal_dist(t_vars *v, int i);
void			init_horizontal_dist(t_vars *v, int i, double angle);
void			vertical_dist(t_vars *v, int i);
void			init_vertical_dist(t_vars *v, int i, double angle);
double			dist(double x1, double y1, double x2, double y2);
void			pp(t_vars *v, int x, int y, int color);
void			u_clear_screen(t_vars *v, int altura, int largura);
void			render_floor_ceiling(t_vars *v);
void			render3d(t_vars *v);
void			render_all_rays(t_vars *v);
void			p_load_textures(t_vars *v);
void			check_if_sprite(t_vars *v, int i);
void			get_tex_idx(t_vars *v, int idx);
void			render_tex(t_vars *v, int i, int strip_w, double strip_h);
void			turn_right(t_vars *vars);
void			turn_left(t_vars *vars);
void			up(t_vars *vars);
void			down(t_vars *vars);
void			move_left(t_vars *vars);
void			move_right(t_vars *vars);
int				save_bmp_file(t_vars *vars);
void			calculate_tile_size(t_vars *v);
void			init_array_sprites(t_vars *v);
void			p_parse_array_sprites(t_vars *v);
void			put_sprites(t_vars *v);
void			calc_dist_sprites(t_vars *v);
void			sort_sprites(t_vars *v);
void			calculate_sprites(t_vars *v, int i);
void			draw_sprites(t_vars *v, int i, int x0);
int				free_and_exit(t_vars *vars);
unsigned int	cor(int r, int g, int b);
int				update_screen(t_vars *v);
void			check_minimap_size(t_vars *v);
#endif
