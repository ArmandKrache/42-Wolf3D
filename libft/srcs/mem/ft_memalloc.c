/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:35:51 by akrache           #+#    #+#             */
/*   Updated: 2019/03/27 16:31:10 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memalloc(size_t size)
{
	void *res;

	if (!(res = (void *)malloc(size)))
		return (NULL);
	ft_bzero(res, size);
	return (res);
}
