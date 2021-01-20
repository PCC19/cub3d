/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:01:47 by pcunha            #+#    #+#             */
/*   Updated: 2020/01/31 19:40:44 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *a;

	a = (t_list *)malloc(sizeof(t_list));
	if (a == NULL)
		return (NULL);
	(*a).content = content;
	(*a).next = NULL;
	return (a);
}
