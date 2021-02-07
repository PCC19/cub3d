/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 00:55:27 by user42            #+#    #+#             */
/*   Updated: 2021/02/07 17:26:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int calcula_linhas_mapa(t_vars *vars, int fd, char **linha)
{
	int tamanho;

	printf("line_cfg: %d\n",vars->line_cfg);
	while (get_next_line(fd, linha) && ft_strlen(*linha) == 0)
	{
		printf("antes: %p ",*linha);
		printf("antes: %s ",*linha);
		vars->line_cfg++;
		free(*linha);
		//printf("depois: %s\n",*linha);
	}
	tamanho = vars->line_count - vars->line_cfg;
	//free(*linha);
	return (tamanho);
}

char	*salva_linha(char *linha)
{
	char *temp;
	int tamanho;

	tamanho = ft_strlen(linha);
	temp = ft_strdup(linha);
	return temp;
}

void	p_parse_map(t_vars *vars, int fd)
{
	char *linha;
	int n_linhas;
	int tamanho;
	int i;

	n_linhas = calcula_linhas_mapa(vars, fd, &linha);

	printf("p_parse_map\n");
	printf("line_count: %d\n",vars->line_count);
	printf("line_cfg: %d\n",vars->line_cfg);
	printf("tamanho: %d\n", n_linhas);
	printf("linha %s\n",linha);
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
			printf("|%s\n",vars->map_temp[i]);
			i++;
			//free(linha);
		}
		free(linha);
	}
	vars->map_temp[i] = 0;
	u_print_map(vars->map_temp);
	free(linha);
}

