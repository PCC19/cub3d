/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:37:28 by pcunha            #+#    #+#             */
/*   Updated: 2020/02/11 15:49:52 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *nova;
	t_list *primeiro;
	t_list *temp;

	if (!lst || !(nova = ft_lstnew(f(lst->content))))
		return (NULL);
	primeiro = nova;
	lst = lst->next;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			ft_lstclear(&primeiro, del);
			return (NULL);
		}
		nova->next = temp;
		nova = nova->next;
		lst = lst->next;
	}
	return (primeiro);
}
