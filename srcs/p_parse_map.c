/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 00:55:27 by user42            #+#    #+#             */
/*   Updated: 2021/02/18 01:24:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		calcula_linhas_mapa(t_vars *vars, int fd, char **linha)
{
	int tamanho;

	while (get_next_line(fd, linha) && ft_strlen(*linha) == 0)
	{
		vars->line_cfg++;
		free(*linha);
	}
	tamanho = vars->line_count - vars->line_cfg;
	return (tamanho);
}

char	*salva_linha(char *linha)
{
	char	*temp;
	int		tamanho;

	tamanho = ft_strlen(linha);
	temp = ft_strdup(linha);
	return (temp);
}

void	p_parse_map(t_vars *vars, int fd)
{
	char	*linha;
	int		n_linhas;
	int		tamanho;
	int		i;

	n_linhas = calcula_linhas_mapa(vars, fd, &linha);
	vars->map_temp = (char **)malloc(sizeof(char*) * (n_linhas + 1));
	i = 0;
	vars->map_temp[i] = salva_linha(linha);
	i++;
	free(linha);
	while (get_next_line(fd, &linha))
	{
		tamanho = ft_strlen(linha);
		if (tamanho > 0)
		{
			vars->map_temp[i] = salva_linha(linha);
			i++;
		}
		free(linha);
	}
	vars->map_temp[i] = 0;
	free(linha);
}
