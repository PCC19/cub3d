/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_load_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:28:45 by user42            #+#    #+#             */
/*   Updated: 2021/02/18 21:48:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	p_load_textures(t_vars *v)
{
	int i;

	i = 0;
	while (i < 5)
	{
		printf("%d |%s|\n",i, v->cfg.tex_file[i]);
		v->tex[i].id = mlx_xpm_file_to_image(v->mlx,
												v->cfg.tex_file[i],
												&v->tex[i].w,
												&v->tex[i].h);
		if (!v->tex[i].id)
			sai(INVALID_TEXTURE_FILE);
		else
		{
			v->tex[i].p = mlx_get_data_addr(v->tex[i].id,
											&v->tex[i].b,
											&v->tex[i].s_line,
											&v->tex[i].end);
		}
		i++;
	}
}
