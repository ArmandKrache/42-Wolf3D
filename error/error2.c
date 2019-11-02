/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clevaill <clevaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:35:03 by akrache           #+#    #+#             */
/*   Updated: 2019/05/22 12:42:01 by clevaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void		*free_file(char *str)
{
	free(str);
	str = 0;
	return (0);
}

void		*free_tab(t_wolf *tab, t_map *map, int x)
{
	(void)map;
	if (x == 2)
		mlx_destroy_window(tab->mlx_ptr, tab->win_ptr);
	free(tab);
	tab = 0;
	return (0);
}
