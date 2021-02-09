/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_image_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:38:06 by user42            #+#    #+#             */
/*   Updated: 2021/02/09 17:28:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	g_image_init (t_vars *v)
{
	v->t.id = mlx_new_image(v->mlx, v->window_width, v->window_height);
	v->t.p = mlx_get_data_addr(v->t.id, &v->t.b, &v->t.s_line, &v->t.end);
}

void	g_pixel_put_img(t_tela t, int x, int y, int color)
{
	*((unsigned int*)t.p + (t.s_line / 4 * y + x)) = (unsigned int) color;
}

