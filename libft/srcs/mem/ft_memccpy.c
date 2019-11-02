/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:12:49 by akrache           #+#    #+#             */
/*   Updated: 2019/03/27 16:31:13 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	i = 0;
	tmp1 = (unsigned char *)dst;
	tmp2 = (unsigned char *)src;
	while (i < n)
	{
		tmp1[i] = tmp2[i];
		if (tmp2[i] == (unsigned char)c)
			return ((void *)&tmp1[i + 1]);
		i++;
	}
	return (NULL);
}
