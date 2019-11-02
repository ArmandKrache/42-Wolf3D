/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:53:34 by akrache           #+#    #+#             */
/*   Updated: 2019/05/07 18:49:37 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

int			light(int color, double dist)
{
	double lux;

	lux = (SIZE >> 1) / dist;
	lux > 0.30 ? lux = 0.30 : 0;
	if (lux < 0.01)
		return (color);
	return ((int)((color & 255) + lux * (229 - (color & 255)))
	+ ((int)((color >> 8 & 255) + lux * (229 - (color >> 8 & 255))) << 8)
	+ ((int)((color >> 16 & 255) + lux * (182 - (color >> 16 & 255))) << 16));
}

int			shading(int color, double dist)
{
	double nox;

	nox = (SIZE << 2) / dist;
	if (nox > 1)
		return (color);
	return ((int)(nox * (color & 255)) + ((int)(nox
		* (color >> 8 & 255)) << 8) + ((int)(nox * (color >> 16 & 255)) << 16));
}

void		texturise_wall(t_wolf *tab, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH)
	{
		if (y >= 0 && y < HEIGHT)
			tab->img_adr[x + y * tab->sl] = color;
	}
}

t_texture	texture_init(t_wolf *tab, char *file, unsigned char id)
{
	t_texture t;

	if (!(t.img_ptr = mlx_xpm_file_to_image(tab->mlx_ptr,
		file, &(t.w), &(t.h))))
	{
		t.w = 0;
		t.h = 0;
	}
	if (t.img_ptr)
	{
		t.img_adr = (unsigned int *)mlx_get_data_addr(t.img_ptr,
			&(t.bpp), &(t.sl), &(t.endian));
		t.sl = t.sl >> 2;
	}
	else
	{
		t.img_adr = tab->null_tex;
		t.sl = SIZE;
	}
	t.id = id;
	return (t);
}

t_texture	*parse_textures(t_wolf *tab)
{
	t_texture	*res;

	if (!(res = (t_texture *)malloc(sizeof(t_texture) * TEX_MAX)))
		return (0);
	res[0] = texture_init(tab, "texture/wall/void.xpm", 0);
	res[1] = texture_init(tab, "texture/wall/wood.xpm", 1);
	res[2] = texture_init(tab, "texture/wall/redbrick.xpm", 2);
	res[3] = texture_init(tab, "texture/wall/bluestone.xpm", 3);
	res[4] = texture_init(tab, "texture/wall/bricks.xpm", 4);
	res[5] = texture_init(tab, "texture/wall/colorstone.xpm", 5);
	res[6] = texture_init(tab, "texture/wall/eagle.xpm", 6);
	res[7] = texture_init(tab, "texture/wall/greystone.xpm", 7);
	res[8] = texture_init(tab, "texture/wall/mossy.xpm", 8);
	res[9] = texture_init(tab, "texture/sprites/shotgun.xpm", 9);
	res[10] = texture_init(tab, "texture/sprites/hand.xpm", 10);
	res[11] = texture_init(tab, "texture/sprites/pause.xpm", 11);
	res[12] = texture_init(tab, "texture/sprites/credit.xpm", 12);
	return (res);
}
