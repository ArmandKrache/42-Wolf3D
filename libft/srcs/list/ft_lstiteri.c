/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 09:35:00 by akrache           #+#    #+#             */
/*   Updated: 2019/03/27 16:30:49 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_lstiteri(t_list *lst, void (*f)(t_list *lstelem),
		void *content_ref, int (*cmp)(void *, void *))
{
	while (lst)
	{
		if (cmp(lst->content, content_ref) == 0)
			f(lst);
		lst = lst->next;
	}
}
