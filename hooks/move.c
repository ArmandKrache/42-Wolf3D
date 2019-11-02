/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:30:32 by akrache           #+#    #+#             */
/*   Updated: 2019/05/02 14:59:59 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	key_pressed_larrow(t_wolf *tab)
{
	tab->player->pov = (tab->player->pov + tab->player->turn) % 360;
}

void	key_pressed_rarrow(t_wolf *tab)
{
	tab->player->pov = tab->player->pov - tab->player->turn;
	tab->player->pov += (int)(tab->player->pov < 0 ? 360.0 : 0);
}

void	key_pressed_darrow(t_wolf *tab)
{
	int x;
	int y;
	int u;
	int v;

	x = (tab->player->pos_x - cos(rad(tab->player->pov)) * tab->player->speed);
	y = (tab->player->pos_y + sin(rad(tab->player->pov)) * tab->player->speed);
	u = (x - tab->player->pos_x) << 2;
	v = (y - tab->player->pos_y) << 2;
	if (!tab->map->grid[(y + v) / SIZE][tab->player->pos_x / SIZE].type
		&& (y + v) / SIZE > 0 && (y + v) / SIZE < tab->map->height - 1)
	{
		tab->player->pos_y = y;
		if (!tab->map->grid[tab->player->pos_y / SIZE][(x + u) / SIZE].type
			&& (x + u) / SIZE > 0 && (x + u) / SIZE < tab->map->width - 1)
			tab->player->pos_x = x;
	}
	else if (!tab->map->grid[tab->player->pos_y / SIZE][(x + u) / SIZE].type
		&& (x + u) / SIZE > 0 && (x + u) / SIZE < tab->map->width - 1)
	{
		tab->player->pos_x = x;
		if (!tab->map->grid[(y + v) / SIZE][tab->player->pos_x / SIZE].type
			&& (y + v) / SIZE > 0 && (y + v) / SIZE < tab->map->height - 1)
			tab->player->pos_y = y;
	}
}

void	key_pressed_uarrow(t_wolf *tab)
{
	int x;
	int y;
	int u;
	int v;

	x = (tab->player->pos_x + cos(rad(tab->player->pov)) * tab->player->speed);
	y = (tab->player->pos_y - sin(rad(tab->player->pov)) * tab->player->speed);
	u = (x - tab->player->pos_x) << 2;
	v = (y - tab->player->pos_y) << 2;
	if (!tab->map->grid[(y + v) / SIZE][tab->player->pos_x / SIZE].type
		&& (y + v) / SIZE > 0 && (y + v) / SIZE < tab->map->height - 1)
	{
		tab->player->pos_y = y;
		if (!tab->map->grid[tab->player->pos_y / SIZE][(x + u) / SIZE].type
			&& (x + u) / SIZE > 0 && (x + u) / SIZE < tab->map->width - 1)
			tab->player->pos_x = x;
	}
	else if (!tab->map->grid[tab->player->pos_y / SIZE][(x + u) / SIZE].type
		&& (x + u) / SIZE > 0 && (x + u) / SIZE < tab->map->width - 1)
	{
		tab->player->pos_x = x;
		if (!tab->map->grid[(y + v) / SIZE][tab->player->pos_x / SIZE].type
			&& (y + v) / SIZE > 0 && (y + v) / SIZE < tab->map->height - 1)
			tab->player->pos_y = y;
	}
}

void	key_pressed_crouch(t_wolf *tab)
{
	if (tab->player->crouch)
	{
		tab->player->crouch = 0;
		tab->player->speed = tab->player->speed << 1;
	}
	else
	{
		tab->player->crouch = 1;
		tab->player->speed = tab->player->speed >> 1;
	}
}
