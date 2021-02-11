/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 00:17:23 by user42            #+#    #+#             */
/*   Updated: 2021/02/11 16:58:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update(t_vars *vars)
{
	// update player
	// feito pela funcao key_hook qdo alguma tecla eh pressionada

	// updaterays
	vars->player.x++;
	vars->player.x--;

}

