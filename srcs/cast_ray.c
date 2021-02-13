/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 17:52:54 by user42            #+#    #+#             */
/*   Updated: 2021/02/13 01:07:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_ray(t_vars *v, int i, float angle)
{
	init_horizontal_dist(v, i, angle);
	horizontal_dist(v, i);
	init_vertical_dist(v, i, angle);
	vertical_dist(v, i);
}
