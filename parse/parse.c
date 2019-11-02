/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clevaill <clevaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:59:29 by akrache           #+#    #+#             */
/*   Updated: 2019/05/22 12:46:19 by clevaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static int		w_atoi(char *str, int *i)
{
	unsigned int	res;

	res = 0;
	if (str[*i] == '{' || str[*i] == ',')
		(*i)++;
	while (ft_isdigit(str[*i]))
	{
		res *= 10;
		res += (str[*i] - '0');
		(*i)++;
	}
	if (str[*i] == ',')
		(*i)++;
	return (res >= TEX_MAX ? 1 : (int)res);
}

static t_block	init_cardi(char *file, int *i)
{
	t_block		res;

	if (!(res.north = w_atoi(file, i)))
		res.type = 0;
	else
		res.type = 2;
	res.east = w_atoi(file, i);
	res.south = w_atoi(file, i);
	res.west = w_atoi(file, i);
	while (file[*i] != '}')
		(*i)++;
	if (file[*i] == '}')
		(*i)++;
	if (file[*i] != ' ')
		res.floor = w_atoi(file, i);
	else
		res.floor = w_atoi(file, i);
	if (file[*i] != ' ')
		res.ceil = w_atoi(file, i);
	else
		res.ceil = w_atoi(file, i);
	return (res);
}

static t_block	init_block(char *file, int *i)
{
	t_block		res;

	if (file[*i] == '{')
		return (init_cardi(file, i));
	if (!(res.north = w_atoi(file, i)))
		res.type = 0;
	else
		res.type = 1;
	if (file[*i] != ' ')
		res.floor = w_atoi(file, i);
	else
		res.floor = w_atoi(file, i);
	if (file[*i] != ' ')
		res.ceil = w_atoi(file, i);
	else
		res.ceil = w_atoi(file, i);
	res.south = res.north;
	res.east = res.north;
	res.west = res.north;
	return (res);
}

int				fill_grid(t_map *map, char *file)
{
	int	i;
	int	j;
	int	index;

	i = -1;
	index = 0;
	while (++i < map->height)
	{
		if (!(map->grid[i] = (t_block *)malloc(sizeof(t_block) * map->width)))
			return ((int)free_grid(map, i));
		j = -1;
		while (++j < map->width)
		{
			map->grid[i][j] = init_block(file, &index);
			index++;
		}
	}
	return (1);
}

t_map			*parsing(char *arg)
{
	t_map	*map;
	char	*file;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	file = 0;
	map->grid = 0;
	if (!(map->height = checking(arg, &file)))
		return (free_map(map));
	map->width = fl_strlen(file);
	if (!(map->grid = (t_block **)malloc(sizeof(t_block *) * map->height)))
	{
		free_file(file);
		return (free_map(map));
	}
	if (!(fill_grid(map, file)))
	{
		free_file(file);
		return (free_map(map));
	}
	free_file(file);
	return (map);
}
