/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:27:56 by akrache           #+#    #+#             */
/*   Updated: 2019/03/27 16:31:00 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*i;

	if (!lst)
		return (NULL);
	tmp = NULL;
	while (lst)
	{
		new = f(lst);
		if (!tmp)
		{
			tmp = new;
			i = tmp;
		}
		else
		{
			i->next = new;
			i = i->next;
		}
		lst = lst->next;
	}
	return (tmp);
}
