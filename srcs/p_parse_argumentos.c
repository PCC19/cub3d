/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_argumentos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 23:34:33 by user42            #+#    #+#             */
/*   Updated: 2021/01/30 18:02:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	p_parse_argumentos(int argc, char *argv[])
{
	int		codigo;
	char	*str;
	char	*substr;

	codigo = 0;
	if (argc < 1 || argc > 3)
		codigo = WRONG_ARGS;
	if (argc > 0)
	{
		str = ft_strtrim(argv[1], " ./");
		substr = ft_strrchr(str, '.');
		if (ft_strncmp(".cub", substr, 6) != 0)
			codigo = INVALID_FILENAME;
		free(str);
	}
	if (argc == 3)
	{
		if (ft_strncmp("--save", argv[2], 6) != 0)
			codigo = WRONG_ARGS;
	}
	if (codigo != 0)
	{
		ft_putstr_fd(error[codigo], 1);
		exit(codigo);
	}
}
