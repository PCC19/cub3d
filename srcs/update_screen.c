/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:39:12 by user42            #+#    #+#             */
/*   Updated: 2021/02/18 15:39:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		update_screen(t_vars *v)
{
	mlx_put_image_to_window(v->mlx, v->win, v->t.id, 0, 0);
	return (0);
}
