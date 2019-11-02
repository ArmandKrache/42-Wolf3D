/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:59:25 by akrache           #+#    #+#             */
/*   Updated: 2019/05/07 18:28:39 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	*free_player(t_player *player)
{
	free(player);
	player = 0;
	return (0);
}

void	*free_grid(t_map *map, int height)
{
	int j;

	j = 0;
	while (j < height)
	{
		if (map->grid[j])
			free(map->grid[j]);
		j++;
	}
	free(map->grid);
	map->grid = 0;
	return (0);
}

void	*free_map(t_map *map)
{
	if (map)
	{
		if (map->grid)
			free_grid(map, map->height);
		free(map);
		map = 0;
	}
	return (0);
}

void	*free_tex(t_wolf *tab)
{
	int	i;

	if (tab->tex)
	{
		i = 0;
		while (i < TEX_MAX)
		{
			if (tab->tex[i].img_ptr)
				mlx_destroy_image(tab->mlx_ptr, tab->tex[i].img_ptr);
			tab->tex[i].img_ptr = 0;
			i++;
		}
		free(tab->tex);
		tab->tex = 0;
	}
	return (0);
}

void	*free_wolf(t_wolf *tab)
{
	if (tab)
	{
		if (tab->player)
			free_player(tab->player);
		if (tab->map)
			free_map(tab->map);
		if (tab->tex)
			free_tex(tab);
		if (tab->img_ptr)
			mlx_destroy_image(tab->mlx_ptr, tab->img_ptr);
		if (tab->win_ptr)
			mlx_destroy_window(tab->mlx_ptr, tab->win_ptr);
		free(tab);
		tab = 0;
	}
	return (0);
}
