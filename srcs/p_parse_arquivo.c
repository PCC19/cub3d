/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_arquivo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 00:49:19 by user42            #+#    #+#             */
/*   Updated: 2021/02/03 21:07:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>

int p_parse_arquivo(t_vars *vars, char *arquivo)
{
	int fd;
	
	 p_init_cfg(vars);
		p_print_cfg(vars); // APAGAR !!
	// conta_linhas
	p_conta_linhas(vars, arquivo);
		printf("Numero de linhas no arquivo: %d\n",vars->line_count);
	// Abre arquivo
	if((fd = open(arquivo, O_RDONLY)) < 0)
	{
		perror("Erro: ");
		exit(errno);
	}
	else
	{
		//parse configs
		p_parse_config(vars, fd);
		// parse maps
		p_parse_map(vars, fd);
		// normalize map
		p_normaliza_map(vars);
		// validate map
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

