NAME = cub3d

LIBFT = ./libft/libft.a

SDIR =	./srcs/
ODIR =	./objs/

SRCS =	$(SDIR)main.c\
		$(SDIR)funcao_a.c\
		$(SDIR)funcao_b.c\
		$(SDIR)g_plot_line.c\
		$(SDIR)g_plot_rect.c\
		$(SDIR)get_next_line.c\
		$(SDIR)get_next_line_utils.c\
		$(SDIR)p_parse_arquivo.c\
		$(SDIR)p_parse_argumentos.c\
		$(SDIR)p_init_config.c\
		$(SDIR)p_parse_config.c\
		$(SDIR)p_escolhe_parse.c\
		$(SDIR)u_free_array_bi.c\
		$(SDIR)p_parse_r.c\
		$(SDIR)p_parse_c.c\
		$(SDIR)u_check_palavras.c\
		$(SDIR)p_parse_f.c\
		$(SDIR)p_parse_tex.c\
		$(SDIR)p_conta_linhas.c\
		$(SDIR)p_parse_map.c\
		$(SDIR)u_print_map.c\
		$(SDIR)p_normaliza_map.c\
		$(SDIR)p_valida_map.c\
		$(SDIR)check_map_1.c\
		$(SDIR)check_map_2.c\
		$(SDIR)render_map.c\
		$(SDIR)u_free_map.c\
		$(SDIR)check_resolution.c\
		$(SDIR)g_image_utils.c\
		$(SDIR)p_init_player.c\
		$(SDIR)draw.c\
		$(SDIR)render_player.c\
		$(SDIR)u_norm_angle.c\
		$(SDIR)k_hooks.c\
		$(SDIR)u_wall_hit.c\
		$(SDIR)p_init_vars.c\
		$(SDIR)render_ray.c\
		$(SDIR)update.c\
		$(SDIR)cast_ray.c\
		$(SDIR)cast_all_rays.c\
		$(SDIR)u_is_inside.c\
		$(SDIR)horizontal_dist.c\
		$(SDIR)vertical_dist.c\
		$(SDIR)dist.c\
		$(SDIR)set_aj.c\
		$(SDIR)u_clear_screen.c\
		$(SDIR)render_floor_ceiling.c\
		$(SDIR)cor.c\
		$(SDIR)render3d.c\
		$(SDIR)render_all_rays.c\
		$(SDIR)p_load_textures.c\
		$(SDIR)check_if_sprite.c\
		$(SDIR)get_tex_idx.c\
		$(SDIR)render_tex.c\
		$(SDIR)moves1.c\
		$(SDIR)moves2.c\
		$(SDIR)save_bmp.c\
		$(SDIR)calculate_tile_size.c\
		$(SDIR)init_array_sprites.c\
		$(SDIR)p_parse_array_sprites.c\
		$(SDIR)sprite.c\

		
OBJS =	$(patsubst $(SDIR)%.c, $(ODIR)%.o, $(SRCS))		

CC = clang
HEADERS = -I./includes -I./libft
C_FLAGS = -Wall -Werror -Wextra -g
C_SANIT = -fsanitize=address
L_FLAGS = -lbsd -lmlx -lXext -lX11 -L ./libft -lft 

$(NAME):	$(OBJS) ./maps/arq1.cub
	$(CC) $(OBJS) $(C_FLAGS) $(C_SANIT) $(HEADERS) $(L_FLAGS) -o cub3d
	./$(NAME) ./maps/arq3.cub --save

$(ODIR)%.o: $(SDIR)%.c
		mkdir -p $(ODIR)
		$(CC) $(C_FLAGS) $(HEADERS) -c $< -o $@

libft:
	make re -C ./libft

all: cub3d

clean:
	rm -f $(OBJS)
	rmdir $(ODIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

roda:
	./cub3d ./maps/arq1.cub
