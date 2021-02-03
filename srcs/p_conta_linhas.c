/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conta_linhas.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 01:12:33 by user42            #+#    #+#             */
/*   Updated: 2021/02/03 01:21:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	p_conta_linhas(t_vars *vars, char *arquivo)
{
	int		fd;
	char	*linha;

	if ((fd = open(arquivo, O_RDONLY)) < 0)
	{
		perror("Erro: ");
		exit(errno);
	}
	else
	{
		while (get_next_line(fd, &linha))
		{
			free(linha);
			vars->line_count++;
		}
	}
	free(linha);
	close(fd);
}
