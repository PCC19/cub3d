/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_wall_hit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 22:53:23 by user42            #+#    #+#             */
/*   Updated: 2021/02/18 01:27:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		u_wall_hit(t_vars *vars, double x, double y)
{
	int ts;

	ts = vars->tile_size;
	if (!(floor(y / ts) < vars->map_num_rows && floor(x / ts) <
															vars->map_num_cols))
		return (1);
	if (ft_is_in(vars->map[(int)floor(y / ts)][(int)floor(x / ts)], "1"))
		return (1);
	else
		return (0);
}
