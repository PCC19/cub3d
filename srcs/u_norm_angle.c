/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_norm_angle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:24:51 by user42            #+#    #+#             */
/*   Updated: 2021/02/10 17:30:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	u_norm_angle(double a)
{
	double angle;

	angle = fmod(a, (2 * M_PI));
	if (a < 0)
		angle = angle + (2 * M_PI);
	return (angle);
}

