/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rmvspc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 18:23:43 by user42            #+#    #+#             */
/*   Updated: 2021/01/31 19:25:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_rmvspc(char **s)
{
	int i = 0;
	int j = 0;
	int tamanho;

	tamanho = ft_strlen(*s);
	i = 0;
	while (i < tamanho)
	{	
		if ((*s)[i] == ' ')
		{
			//shift
			for(j=i;j<tamanho-1;j++) (*s)[j] = (*s)[j+1];
		}
		if((*s)[i] != ' ') i++;
		}
		
}
/*
	
	
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (s[i] != 0)
	{
		if (s[i] == ' ')
		{
			j = i+1;
			while (s[j] != 0)
			{
				s[j-1] = s[j];
				k++;
				j++;
			}
		}
		else
			i++;
	}
}
*/
