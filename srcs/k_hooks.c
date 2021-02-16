/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_hooks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 22:23:35 by user42            #+#    #+#             */
/*   Updated: 2021/02/16 21:43:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_hook(int keycode, t_vars *vars)
{
	printf("keycode: %d\n", keycode);
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
	//update(vars);
	draw(vars);
	return (0);
}
