/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_arquivo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 00:49:19 by user42            #+#    #+#             */
/*   Updated: 2021/02/10 01:04:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>

int p_parse_arquivo(t_vars *vars, char *arquivo)
{
	int fd;
	
	p_conta_linhas(vars, arquivo);
		printf("Numero de linhas no arquivo: %d\n",vars->line_count);
	if((fd = open(arquivo, O_RDONLY)) < 0)
	{
		perror("Erro: ");
		exit(errno);
	}
	else
	{
		p_parse_config(vars, fd);
		p_parse_map(vars, fd);
		p_normaliza_map(vars);
		p_valida_map(vars);
		// codigo para inicializar player
		p_init_player(vars);
			printf("Angulo: %f\n",vars->player.angle);
		// codigo para carregar texturas
		// codigo para inicializar sprites

	}
	close(fd);

	return(0);
}
