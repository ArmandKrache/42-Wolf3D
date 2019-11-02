/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:28:44 by akrache           #+#    #+#             */
/*   Updated: 2019/05/03 12:06:21 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

int		key_pressed_esc(t_wolf *tab)
{
	free_wolf(tab);
	exit(0);
}

void	key_pressed_enter(t_wolf *tab)
{
	if (tab->pause)
		tab->pause = 0;
	else
		tab->pause = 1;
	display(tab);
}

void	key_hook2(int keycode, t_wolf *tab)
{
	if (keycode == 3)
		key_pressed_f(tab);
	else if (keycode == 49)
		key_pressed_space(tab);
	else if (keycode == 12)
		key_pressed_lstrafe(tab);
	else if (keycode == 14)
		key_pressed_rstrafe(tab);
}

int		key_hook(int keycode, t_wolf *tab)
{
	if (keycode == 53)
		key_pressed_esc(tab);
	else if (keycode == 36)
		key_pressed_enter(tab);
	else if (!tab->pause)
	{
		if (keycode == 123 || keycode == 0)
			key_pressed_larrow(tab);
		else if (keycode == 124 || keycode == 2)
			key_pressed_rarrow(tab);
		else if (keycode == 125 || keycode == 1)
			key_pressed_darrow(tab);
		else if (keycode == 126 || keycode == 13)
			key_pressed_uarrow(tab);
		else if (keycode == 259)
			key_pressed_crouch(tab);
		else if (keycode == 15)
			key_pressed_r(tab);
		else
			key_hook2(keycode, tab);
		display(tab);
	}
	return (keycode);
}
