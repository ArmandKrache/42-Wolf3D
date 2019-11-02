/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:42:36 by akrache           #+#    #+#             */
/*   Updated: 2019/05/07 18:41:02 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memset(void *b, unsigned int c, size_t len)
{
	unsigned int *tmp;

	tmp = b;
	while (len != 0)
	{
		*tmp = c;
		tmp++;
		len--;
	}
	return (b);
}
