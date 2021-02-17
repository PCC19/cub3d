/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 22:08:45 by user42            #+#    #+#             */
/*   Updated: 2021/02/17 22:54:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		close_program()
{
	exit(0);
	return (0);
}

int		free_and_exit(t_vars *v)
{
	int i;

	u_free_map(v);
	i = 0;
	while (i < 5)
	{
		mlx_destroy_image(v->mlx, v->tex[i].id);
		i++;
	}
	mlx_destroy_image(v->mlx, v->t.id);
	mlx_destroy_window(v->mlx, v->win);
	free(v->mlx);
	printf(" PLAY AGAIN !!!!!\n");
	return (close_program());
}
