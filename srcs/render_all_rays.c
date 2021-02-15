/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_all_rays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 18:22:41 by user42            #+#    #+#             */
/*   Updated: 2021/02/15 00:47:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_all_rays(t_vars *v)
{
	int i;

	i = 0;
	while (i < v->num_rays)
	//while (i < 1)
	{
		render_ray(v, v->rays[i].wallhit_x, v->rays[i].wallhit_y, BLUE);
		i++;
	}
}
