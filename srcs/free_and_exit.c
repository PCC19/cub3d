/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 22:08:45 by user42            #+#    #+#             */
/*   Updated: 2021/02/17 22:28:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		close_program()
{
	exit(0);
	return (0);
}

int		free_and_exit(t_vars *vars)
{
	printf("%d\n",vars->player.x);
	printf(" TA DA !!!!!\n");
	return (close_program());
}

