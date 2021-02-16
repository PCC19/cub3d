/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 22:33:53 by user42            #+#    #+#             */
/*   Updated: 2021/02/16 22:57:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	little_endian_int(unsigned char *addr, unsigned int value)
{
	addr[0] = (unsigned char)(value);
	addr[1] = (unsigned char)(value >> 8);
	addr[2] = (unsigned char)(value >> 16);
	addr[3] = (unsigned char)(value >> 24);
}

static void	write_header(t_vars *vars, int fd)
{
	unsigned char	file[54];
	int				filesize;

	ft_bzero(&file, 54);
	filesize = 54 + vars->window_width * vars->window_height;
	file[0] = (unsigned char)('B');
	file[1] = (unsigned char)('M');
	little_endian_int(&file[2], filesize);
	file[10] = (unsigned char)(54);
	file[14] = (unsigned char)(40);
	little_endian_int(&file[18], vars->window_width);
	little_endian_int(&file[22], -vars->window_height);
	file[26] = (unsigned char)(1);
	file[28] = (unsigned char)(32);
	write(fd, &file, 54);
}

int			save_bmp_file(t_vars *v)
{
	int		fd;
	int		x;
	int		y;
	uint	color;

	if ((fd = open("img.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 777)) < 0)
		return (0);
	write_header(v, fd);
	y = 0;
	while (y < v->window_height)
	{
		x = 0;
		while (x < v->window_width)
		{
			color = *(uint*)(v->t.p + (int)((y * v->window_width) + x) * 4);
			write(fd, &color, 4);
			x++;
		}
		y++;
	}
	close(fd);
	return (1);
}
