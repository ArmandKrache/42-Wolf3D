/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:20:45 by akrache           #+#    #+#             */
/*   Updated: 2019/05/22 16:01:52 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int		wolf_usage(int r)
{
	ft_putendl("usage: ./wolf3d <map>");
	return (r);
}

void			pos_init(t_wolf *tab, t_player *res)
{
	int i;
	int j;

	i = 1;
	res->pos_x = 0;
	res->pos_y = 0;
	while (i < tab->map->height - 1)
	{
		j = 1;
		while (j < tab->map->width - 1)
		{
			if (tab->map->grid[i][j].type == 0)
			{
				res->pos_y = i * SIZE + (SIZE >> 1);
				res->pos_x = j * SIZE + (SIZE >> 1);
				return ;
			}
			j++;
		}
		i++;
	}
}

t_player		*player_init(t_wolf *tab, double pov)
{
	t_player	*res;

	if (!(res = (t_player *)malloc(sizeof(t_player))))
		return (0);
	pos_init(tab, res);
	if (res->pos_x == 0)
		return (free_player(res));
	res->hand = tab->tex[10];
	res->pov = pov;
	res->height = SIZE / 2;
	res->speed = SIZE / 4;
	res->turn = 10;
	res->look = 0;
	res->crouch = 0;
	return (res);
}

static t_wolf	*tab_init(t_map *map)
{
	t_wolf *tab;

	if (!(tab = (t_wolf *)malloc(sizeof(t_wolf))))
		return (free_map(map));
	if (!(tab->mlx_ptr = mlx_init()))
		return (free_tab(tab, map, 0));
	if (!(tab->win_ptr = mlx_new_window(tab->mlx_ptr, WIDTH, HEIGHT, "Wolf3D")))
		return (free_tab(tab, map, 1));
	if (!(tab->img_ptr = mlx_new_image(tab->mlx_ptr, WIDTH, HEIGHT)))
		return (free_tab(tab, map, 2));
	tab->img_adr = (unsigned int *)mlx_get_data_addr(tab->img_ptr,
		&(tab->bpp), &(tab->sl), &(tab->endian));
	tab->sl = tab->sl >> 2;
	ft_memset(tab->null_tex, 0x4FFF49, SIZE);
	tab->pause = 0;
	tab->fov_rad = rad(FOV);
	tab->cons = SIZE * (int)((WIDTH / 2) / tan(tab->fov_rad / 2));
	tab->map = map;
	tab->tex = parse_textures(tab);
	if (!tab->tex)
		return (free_wolf(tab));
	if (!(tab->player = player_init(tab, 0)))
		return (free_wolf(tab));
	return (tab);
}

int				main(int argc, char *argv[])
{
	t_wolf	*tab;
	t_map	*map;

	if (argc != 2)
		return (wolf_usage(0));
	if (!(map = parsing(argv[1])))
		return (0);
	if (!(tab = tab_init(map)))
		return (0);
	display(tab);
	mlx_hook(tab->win_ptr, 2, 0, key_hook, tab);
	mlx_hook(tab->win_ptr, 17, 0, key_pressed_esc, tab);
	mlx_loop(tab->mlx_ptr);
	return (0);
}
