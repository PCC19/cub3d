/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_is_inside.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 00:17:24 by user42            #+#    #+#             */
/*   Updated: 2021/02/19 01:04:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	u_is_inside(t_vars *vars, double x, double y)
{
	int flag;

	flag = 0;
	if (x >= 0 && x <= vars->window_width && y >= 0 && y <= vars->window_height)
		flag = 1;
	return (flag);
}
