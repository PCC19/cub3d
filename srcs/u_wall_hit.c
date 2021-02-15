/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_wall_hit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 22:53:23 by user42            #+#    #+#             */
/*   Updated: 2021/02/15 00:43:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		u_wall_hit(t_vars *vars, double x, double y)
{
	int ts; 

	ts = vars->tile_size;
	printf("yi: %f\t\txi: %f\t\ti: %f\t\tj: %f\n",y,x, floor(y / ts), floor(x / ts));
	//printf("rows: %d cols: %d\n",vars->map_num_rows, vars->map_num_cols);
	if (!(floor(y / ts) < vars->map_num_rows && floor(x / ts) < vars->map_num_cols))
		return (1);
	if (ft_is_in(vars->map[(int)floor(y / ts)][(int)floor(x / ts)], "12"))
		return (1);
	else
		return (0);
}
