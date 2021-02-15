/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex_idx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:27:36 by user42            #+#    #+#             */
/*   Updated: 2021/02/15 17:34:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_tex_idx(t_vars *v, int i)
{
	// se raio bateu em sprite, idx = 4)
	if (v->rays[i].is_sprite)
		v->rays[i].tex_idx = 4;
	
	// se raio bateu em parede
	if (!v->rays[i].is_sprite)
	{
		// se bateu h e up -> norte
		if (v->rays[i].is_up && !v->rays[i].hit_v)
			v->rays[i].tex_idx = 0;			
		// se bateu h e dn -> south
		if (v->rays[i].is_dn && !v->rays[i].hit_v)
			v->rays[i].tex_idx = 1;			
		// se bateu v e le -> east
		if (v->rays[i].is_le && v->rays[i].hit_v)
			v->rays[i].tex_idx = 2;			
		// se bateu v e ri -> west
		if (v->rays[i].is_ri && v->rays[i].hit_v)
			v->rays[i].tex_idx = 3;			
	}
}
