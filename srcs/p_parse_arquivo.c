/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_arquivo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 00:49:19 by user42            #+#    #+#             */
/*   Updated: 2021/01/30 22:36:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>

int p_parse_arquivo(t_vars *vars, char *arquivo)
{
	int fd;
	//printf("lixo %d\n",vars->sprite.width);
	
	 p_init_cfg(vars);
		p_print_cfg(vars); // APAGAR !!
	// Abre arquivo
	//if((fd = open("lixo", O_RDONLY)) < 0)
	if((fd = open(arquivo, O_RDONLY)) < 0)
	{
		perror("Erro: ");
		exit(errno);
	}
	else
	{
		//parse configs
		p_parse_config(vars, fd);
		//parse maps
	}
	close(fd);

	return(0);
}
/*
Init_cfg ok
Abre arquivo ok

Parse configs
Le linhas enquanto houver linhas e all_set ainda = 0
	faz trim de espacos
	Checa se 1o caracater e valido
	[R,C,F,S,E,W,N,S]
		se nao exit(err) <=========
		se sim escolhe funcao de acordo
			esta duplicando ? erro
			esta ok ?
				parse
				incrementa all_set
Termina loop quando struct estiver cheia

Parse Mapa
	Le linhas ate chegar em linha vazia
	Normaliza Mapa
	Valida mapa
*/

