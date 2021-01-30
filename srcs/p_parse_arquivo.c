/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_arquivo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 00:49:19 by user42            #+#    #+#             */
/*   Updated: 2021/01/30 18:45:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>

int p_parse_arquivo(t_vars *vars, char *arquivo)
{
	int fd;
	char *linha;
	//printf("lixo %d\n",vars->sprite.width);
	
	// p_init_cfg
	// Abre arquivo
	if(!(fd = open(arquivo, O_RDONLY)))
		exit(perror("Erro: ",errno));
	else
	{
		printf("fd: %d\n",fd);
		get_next_line(fd, &linha);
		printf("linha: %s\n",linha);
		//parse configs
		//parse maps
	}
	close(fd);
	free(linha);

	return(0);
}
/*
Init_cfg
Abre arquivo

Parse configs
Le linhas enquanto for diferente de vazio
	faz trim de espacos
	Checa se 1o caracater e valido
	[R,C,F,S,E,W,N,S]
		se nao exit(err)
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

