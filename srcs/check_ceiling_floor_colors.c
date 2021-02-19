/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ceiling_floor_colors.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 21:55:49 by user42            #+#    #+#             */
/*   Updated: 2021/02/19 21:59:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_ceiling_floor_colors(t_vars *v)
{
	if (v->cfg.ceiling.r < 0 || v->cfg.ceiling.r > 255)
		sai(INVALID_COLOR);
	if (v->cfg.ceiling.g < 0 || v->cfg.ceiling.g > 255)
		sai(INVALID_COLOR);
	if (v->cfg.ceiling.b < 0 || v->cfg.ceiling.b > 255)
		sai(INVALID_COLOR);
	if (v->cfg.floor.r < 0 || v->cfg.floor.r > 255)
		sai(INVALID_COLOR);
	if (v->cfg.floor.g < 0 || v->cfg.floor.g > 255)
		sai(INVALID_COLOR);
	if (v->cfg.floor.b < 0 || v->cfg.floor.b > 255)
		sai(INVALID_COLOR);
}
