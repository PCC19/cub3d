/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:46:02 by user42            #+#    #+#             */
/*   Updated: 2021/02/16 16:56:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_tex(t_vars *v, int i, int strip_w, double strip_h)
{
	double	offset_x;
	double	offset_y;
	double		y;
	double		ymin;
	double		ymax;
	int		idx;
	uint	color;
	int		k;

	ymin = (v->window_height / 2) - (strip_h / 2);
	ymax = (v->window_height / 2) + (strip_h / 2);
//	if (ymin < 0)
//		ymin = 0;
//	if (ymax > v->window_height)
//		ymax = v->window_height;
	
	idx = v->rays[i].tex_idx;

	// calcula offset x
	if (v->rays[i].hit_v)
		offset_x = (int)v->rays[i].wallhit_y % v->tile_size;
	else
		offset_x = (int)v->rays[i].wallhit_x % v->tile_size;
	// loop para cada coluna do strip
	k = 0;
	while (k < strip_w)
	{
		// loop para cada y
		y = ymin;
			//	printf("================= render tex =============\n");
			//	printf("idx: %d\tymin: %d\tymax: %d\n",idx, y, ymax);
			//	printf("offset_x: %f\twhx: %f\twhy: %f\n",offset_x,
						//v->rays[i].wallhit_x, v->rays[i].wallhit_y);
			//	printf("tile size: %d\tvhit: %d\n",v->tile_size, v->rays[i].hit_v);
		while (y < ymax)
		{
			// calcula offset y
			offset_y = floor(((y - ymin) / (ymax - ymin)) * (v->tex[idx].h));
			//printf("offy:%f\ty: %f\tymin: %f\tymax: %f\t h %d\n",offset_y,y,ymin, ymax, v->tex[idx].h);
//			dist_from_top = y + (strip_h / 2) -  (v->window_height / 2);
//			offset_y = dist_from_top * (v->tex[idx].h) / strip_h;
				//printf("strip_h: %f\twh: %d\n",strip_h, v->window_height);
				//printf("tex[idx].h: %d\n",v->tex[idx].h);
				//printf("offset y: %f\n", offset_y);
			// plot pixel de acordo com offset
//		*((unsigned int*)p+i) = (unsigned int) GREEN;
			//printf("zzz:%d\n",(int)((offset_y * v->tex[idx].s_line) + offset_x)*4);
			color = *(uint*)(v->tex[idx].p + (int)((offset_y * v->tex[idx].s_line/4) + offset_x)*4);
			//color = RED;
			//printf("h: %d\ty:%f\toffy: %f\t offx: %f\tsline: %d\n",v->tex[idx].h,y, offset_y, offset_x, v->tex[idx].s_line);
			//printf("color: %0x\n",color);
			g_pixel_put_img(v->t, i * strip_w + k, y, color);
	//sai(1);
			y++;
		}	
//		sai(1);
		k++;
	}
}
