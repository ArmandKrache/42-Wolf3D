/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:03:23 by akrache           #+#    #+#             */
/*   Updated: 2019/05/03 12:06:47 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	key_pressed_f(t_wolf *tab)
{
	if (tab->player->look > -600)
		tab->player->look -= 10;
}

void	key_pressed_r(t_wolf *tab)
{
	if (tab->player->look < 600)
		tab->player->look += 10;
}

void	key_pressed_space(t_wolf *tab)
{
	if (tab->player->hand.id == 9)
		tab->player->hand = tab->tex[10];
	else
		tab->player->hand = tab->tex[9];
}

void	key_pressed_rstrafe(t_wolf *tab)
{
	tab->player->pov -= 90;
	tab->player->speed >>= 1;
	key_pressed_uarrow(tab);
	tab->player->speed <<= 1;
	tab->player->pov += 90;
}

void	key_pressed_lstrafe(t_wolf *tab)
{
	tab->player->pov += 90;
	tab->player->speed >>= 1;
	key_pressed_uarrow(tab);
	tab->player->speed <<= 1;
	tab->player->pov -= 90;
}
