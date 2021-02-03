/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 00:55:27 by user42            #+#    #+#             */
/*   Updated: 2021/02/03 03:01:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int calcula_linhas_mapa(t_vars *vars, int fd, char **linha)
{
	int tamanho;

	printf("line_cfg: %d\n",vars->line_cfg);
	while (get_next_line(fd, linha) && ft_strlen(*linha) == 0)
		vars->line_cfg++;
	tamanho = vars->line_count - vars->line_cfg;
	return (tamanho);
}

char	*salva_linha(char *linha)
{
	char *temp;
	int tamanho;

	tamanho = ft_strlen(linha);
	temp = (char *)malloc(sizeof(char) * (tamanho + 1));
	temp = ft_strdup(linha);
	free(linha);
	return temp;
}

void print_map(char **armazem)
{
	int i;

	i = 0;
	printf("=============\n");
	while(armazem[i])
	{
		printf("|%s\n",armazem[i]);
		i++;
	}
	printf("=============\n");
}
	
void p_parse_map(t_vars *vars, int fd)
{
	char *linha;
	int n_linhas;
	int tamanho;
	char **armazem;
	int i;

	n_linhas = calcula_linhas_mapa(vars, fd, &linha);

	printf("line_count: %d\n",vars->line_count);
	printf("line_cfg: %d\n",vars->line_cfg);
	printf("tamanho: %d\n", n_linhas);
	printf("linha %s\n",linha);
	armazem = (char **)malloc(sizeof(char*) * (n_linhas + 1));
	i = 0;
	//tamanho = ft_strlen(linha);
	//armazem[i] = (char *)malloc(sizeof(char) * (tamanho + 1));
	//armazem[i] = ft_strdup(linha);
	armazem[i] = salva_linha(linha);
	i++;
	while (get_next_line(fd, &linha))
	{
		tamanho = ft_strlen(linha);
		if (tamanho > 0)
		{
			//armazem[i] = (char *)malloc(sizeof(char) * (tamanho + 1));
			//armazem[i] = ft_strdup(linha);
			armazem[i] = salva_linha(linha);
			printf("|%s\n",armazem[i]);
			i++;
		}
	}
	free(linha);
	armazem[i] = 0;
	print_map(armazem);
}

