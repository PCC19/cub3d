/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_arquivo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 00:49:19 by user42            #+#    #+#             */
/*   Updated: 2021/01/29 01:06:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>

int p_parse_arquivo(t_vars *vars, char *arquivo)
{
	int fd;
	char *linha;
	printf("lixo %d\n",vars->sprite.width);

	fd = open(arquivo, O_RDONLY);
		printf("fd: %d\n",fd);
	get_next_line(fd, &linha);
	printf("linha: %s\n",linha);
	close(fd);
	free(linha);
	return(0);
}
