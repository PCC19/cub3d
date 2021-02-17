/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_hooks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 22:23:35 by user42            #+#    #+#             */
/*   Updated: 2021/02/17 22:30:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_hook(int keycode, t_vars *vars)
{
	if (keycode == RIGHT)
		turn_right(vars);
	if (keycode == LEFT)
		turn_left(vars);
	if (keycode == WKEY)
		up(vars);
	if (keycode == SKEY)
		down(vars);
	if (keycode == AKEY)
		move_left(vars);
	if (keycode == DKEY)
		move_right(vars);
	if (keycode == ESCKEY)
		free_and_exit(vars);
	draw(vars);
	return (0);
}
