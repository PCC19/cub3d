/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_arquivo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 00:49:19 by user42            #+#    #+#             */
/*   Updated: 2021/02/19 21:45:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>

int	p_parse_arquivo(t_vars *v, char *arquivo)
{
	int fd;

	p_conta_linhas(v, arquivo);
	if ((fd = open(arquivo, O_RDONLY)) < 0)
	{
		perror("Erro: ");
		exit(errno);
	}
	else
	{
		p_parse_config(v, fd);
		p_parse_map(v, fd);
		if (v->codigo == INVALID_MAP)
			sai(INVALID_MAP);
		p_normaliza_map(v);
		p_valida_map(v);
	}
	close(fd);
	return (0);
}
