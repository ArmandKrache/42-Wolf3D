/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:33:32 by akrache           #+#    #+#             */
/*   Updated: 2019/05/11 16:06:32 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static void		img_pixel_put(t_wolf *tab, int x, int y, int c)
{
	if (x >= 0 && x < WIDTH)
	{
		if (y >= 0 && y < HEIGHT)
			tab->img_adr[x + y * tab->sl] = c;
	}
}

static int		horiz_check(t_wolf *tab, double a, t_coord *res)
{
	double		x;
	double		y;
	double		xa;
	double		ya;

	if (a >= 180.0)
		y = (tab->player->pos_y / SIZE + 1) * SIZE;
	else
		y = (tab->player->pos_y / SIZE) * SIZE - 0.01;
	x = (tab->player->pos_x + (tab->player->pos_y - y) / tan(rad(a)));
	ya = a >= 180.0 ? SIZE : -SIZE;
	xa = a >= 180.0 ? -(SIZE / tan(rad(a))) : (SIZE / tan(rad(a)));
	while ((x >= 0 && x < tab->map->width * SIZE)
		&& (y >= 0 && y < tab->map->height * SIZE)
		&& tab->map->grid[(int)(y / SIZE)][(int)(x / SIZE)].type == 0)
	{
		x += xa;
		y += ya;
	}
	if ((x < 0 || x >= tab->map->width * SIZE)
		|| (y < 0 || y >= tab->map->height * SIZE))
		return (0);
	res->x = x;
	res->y = y;
	return (1);
}

static int		vert_check(t_wolf *tab, double a, t_coord *res)
{
	double		x;
	double		y;
	double		xa;
	double		ya;

	if (a >= 90.0 && a < 270.0)
		x = (tab->player->pos_x / SIZE) * SIZE - 0.01;
	else
		x = (tab->player->pos_x / SIZE + 1) * SIZE;
	y = (tab->player->pos_y + (tab->player->pos_x - x) * tan(rad(a)));
	xa = (a >= 90.0 && a < 270.0) ? -SIZE : SIZE;
	ya = a < 90.0 || a > 270.0 ? -(SIZE * tan(rad(a))) : (SIZE * tan(rad(a)));
	while ((x >= 0 && x < tab->map->width * SIZE)
		&& (y >= 0 && y < tab->map->height * SIZE)
		&& tab->map->grid[(int)(y / SIZE)][(int)(x / SIZE)].type == 0)
	{
		x += xa;
		y += ya;
	}
	if ((x < 0 || x >= tab->map->width * SIZE)
		|| (y < 0 || y >= tab->map->height * SIZE))
		return (0);
	res->x = x;
	res->y = y;
	return (1);
}

static void		slice(t_wolf *tab, int x, double dist, t_texture tex)
{
	int			p;
	int			y;
	int			top;

	p = dist == -1 ? 0 : (int)(tab->cons / dist);
	top = ((HEIGHT - p) / (tab->player->crouch ? 1.4 : 2)) + tab->player->look;
	y = -1;
	while (++y < top)
		img_pixel_put(tab, x, y, 0x404040);
	while (y < top + p && (y < HEIGHT - 1))
	{
		texturise_wall(tab, x, y, light(shading(tex.img_adr[(tab->offset
			+ (((y - top) * tex.h) / p)
			* tex.sl)], dist), dist));
		y++;
	}
	while (y < HEIGHT)
	{
		img_pixel_put(tab, x, y, 0x303030);
		y++;
	}
}

void			cast_ray(t_wolf *tab, double a, int x)
{
	double	d_v;
	double	d_h;
	t_coord	v;
	t_coord	h;

	d_v = !(vert_check(tab, a, &v)) ? -1 : sqrt((v.x - tab->player->pos_x)
		* (v.x - tab->player->pos_x) + (v.y - tab->player->pos_y)
		* (v.y - tab->player->pos_y)) * cos(rad((a - tab->player->pov)));
	d_h = !(horiz_check(tab, a, &h)) ? -1 : sqrt((h.x - tab->player->pos_x)
		* (h.x - tab->player->pos_x) + (h.y - tab->player->pos_y)
		* (h.y - tab->player->pos_y)) * cos(rad((a - tab->player->pov)));
	if (d_v == -1 && d_h == -1)
		slice(tab, x, -1, tab->tex[0]);
	else if (d_h == -1 || (d_v <= d_h && d_v != -1))
	{
		tab->offset = (int)v.y % SIZE;
		slice(tab, x, d_v, tab->tex[get_id(tab, a, v, 1)]);
	}
	else
	{
		tab->offset = (int)h.x % SIZE;
		slice(tab, x, d_h, tab->tex[get_id(tab, a, h, 0)]);
	}
}
