/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_wall_hit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 22:53:23 by user42            #+#    #+#             */
/*   Updated: 2021/02/13 23:00:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		u_wall_hit(t_vars *vars, int x, int y)
{
	int ts; 

	ts = vars->tile_size;
	printf("yi: %d\t\txi: %d\t\ti: %d\t\tj: %d\n",y,x, y / ts, x / ts);
	//printf("rows: %d cols: %d\n",vars->map_num_rows, vars->map_num_cols);
	if (!((y / ts) <= vars->map_num_rows && (x / ts) <= vars->map_num_cols))
		return (1);
	if (ft_is_in(vars->map[y / ts][x / ts], "12"))
		return (1);
	else
		return (0);
}
