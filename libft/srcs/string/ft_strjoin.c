/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:03:16 by akrache           #+#    #+#             */
/*   Updated: 2019/03/27 16:31:56 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		t1;
	int		t2;
	int		i;

	t1 = (s1 ? ft_strlen(s1) : 0);
	t2 = (s2 ? ft_strlen(s2) : 0);
	if (!(res = (char *)malloc(sizeof(char) * (t1 + t2) + 1)))
		return (NULL);
	i = 0;
	while (i < t1)
	{
		res[i] = s1[i];
		i++;
	}
	t1 = 0;
	while (t1 < t2)
		res[i++] = s2[t1++];
	res[i] = '\0';
	return (res);
}
