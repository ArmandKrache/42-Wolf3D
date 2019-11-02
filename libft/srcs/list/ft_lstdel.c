/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:47:17 by akrache           #+#    #+#             */
/*   Updated: 2019/03/27 16:30:26 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	**tmp;
	t_list	*next;

	tmp = alst;
	while ((*alst)->next)
	{
		next = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = next;
	}
	del((*alst)->content, (*alst)->content_size);
	free(*tmp);
	*tmp = NULL;
}
