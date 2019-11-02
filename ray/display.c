/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 13:29:40 by akrache           #+#    #+#             */
/*   Updated: 2019/05/08 13:56:02 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

double		rad(double angle)
{
	return (angle * (M_PI / 180.0));
}

int			get_id(t_wolf *tab, double a, t_coord v, int verti)
{
	if (verti)
	{
		if (a >= 90 && a <= 270)
			return (tab->map->grid[(int)v.y / SIZE][(int)v.x / SIZE].east);
		else
			return (tab->map->grid[(int)v.y / SIZE][(int)v.x / SIZE].west);
	}
	else
	{
		if (a >= 180)
			return (tab->map->grid[(int)v.y / SIZE][(int)v.x / SIZE].north);
		else
			return (tab->map->grid[(int)v.y / SIZE][(int)v.x / SIZE].south);
	}
	return (0);
}

static void	display_sprites(t_wolf *tab)
{
	if (tab->player->hand.img_ptr)
		mlx_put_image_to_window(tab->mlx_ptr, tab->win_ptr,
			tab->player->hand.img_ptr,
			(WIDTH + (tab->player->hand.id == 10
			? tab->player->hand.w : 0)) / 2, HEIGHT - tab->player->hand.h);
	else
		ft_memset(tab->null_tex, (unsigned int)random(), SIZE);
	if (tab->pause)
	{
		if (tab->tex[11].img_ptr)
			mlx_put_image_to_window(tab->mlx_ptr, tab->win_ptr,
				tab->tex[11].img_ptr, (WIDTH >> 1) - (tab->tex[11].w >> 1),
				(HEIGHT >> 1) - (tab->tex[11].h >> 1));
		if (tab->tex[12].img_ptr)
			mlx_put_image_to_window(tab->mlx_ptr,
				tab->win_ptr, tab->tex[12].img_ptr,
				(WIDTH >> 1) - (tab->tex[12].w >> 1),
				HEIGHT - tab->tex[12].h);
	}
}

void		display(t_wolf *tab)
{
	int		x;
	double	angle;
	double	dist;

	x = WIDTH - 1;
	angle = (tab->player->pov - (FOV >> 1));
	angle < 0 ? angle += 360.0 : 0;
	dist = 0;
	while (x >= 0)
	{
		cast_ray(tab, angle, x);
		x--;
		angle += RAY_ANGLE;
		angle >= 360.0 ? angle -= 360.0 : 0;
	}
	mlx_put_image_to_window(tab->mlx_ptr, tab->win_ptr, tab->img_ptr, 0, 0);
	display_sprites(tab);
}
