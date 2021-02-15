/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex_idx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:27:36 by user42            #+#    #+#             */
/*   Updated: 2021/02/15 17:43:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_tex_idx(t_vars *v, int i)
{
	if (v->rays[i].is_sprite)
		v->rays[i].tex_idx = 4;
	else
	{
		if (v->rays[i].is_up && !v->rays[i].hit_v)
			v->rays[i].tex_idx = 0;			
		if (v->rays[i].is_dn && !v->rays[i].hit_v)
			v->rays[i].tex_idx = 1;			
		if (v->rays[i].is_le && v->rays[i].hit_v)
			v->rays[i].tex_idx = 2;			
		if (v->rays[i].is_ri && v->rays[i].hit_v)
			v->rays[i].tex_idx = 3;			
	}
}
