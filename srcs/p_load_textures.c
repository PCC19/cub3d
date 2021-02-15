/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_load_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:28:45 by user42            #+#    #+#             */
/*   Updated: 2021/02/15 15:42:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	p_load_textures(t_vars *v)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if((fd = open(arquivo, O_RDONLY)) < 0)
			sai(INVALID_TEXTURE_FILE);
		else
		{
		//carrega textura
	}
	close(fd);
}

typedef struct s_tex {
	void	*id;
	void	*p;
	int		b;
	int		s_line;
	int		end;
	int		w;
	int		h;
}			t_tex;
