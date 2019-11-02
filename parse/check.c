/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 18:50:04 by akrache           #+#    #+#             */
/*   Updated: 2019/05/22 15:41:09 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

int					fl_strlen(char *str)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (str[i] && str[i] != '\n')
	{
		while (str[i] != ' ' && str[i] != '\n')
			i++;
		x++;
		if (str[i] == ' ')
			i++;
		else
			break ;
	}
	return (x);
}

int					checkdev(int i, char *buf)
{
	int x;

	if (i == -1)
		return (1);
	if (!(buf[0]))
		return (1);
	x = 0;
	while (buf[x])
	{
		if (buf[x] != '\n')
		{
			if (buf[x] < 0 || buf[x] > 126)
				return (1);
		}
		++x;
	}
	return (0);
}

static char			*readfile(char *arg)
{
	char	*tmp;
	int		i;
	char	*file;
	char	buf[BUFF_SIZE + 1];
	int		fd;

	if ((fd = open(arg, O_RDONLY | O_NOFOLLOW)) == -1)
		return (0);
	i = (int)read(fd, buf, BUFF_SIZE);
	buf[i] = '\0';
	if (checkdev(i, buf))
		return (0);
	if (!(file = ft_strdup(buf)))
		return (0);
	while (file && (i = (int)read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		tmp = file;
		file = ft_strjoin(file, buf);
		free(tmp);
	}
	close(fd);
	if (!ft_strchr(file, '\n'))
		return (0);
	return (file ? file : free_file(file));
}

static int			is_valid(char c, int *y, char prev)
{
	if (ft_isdigit(c))
		return (prev != '}');
	else if (c == '}' || c == '{')
		return (prev != c && prev != ',');
	else if (c == ' ')
		return (prev != ' ' && prev != ',');
	else if (c == '\n')
		return (++(*y) && prev != ' ');
	else if (c == ',')
		return (ft_isdigit(prev));
	return (0);
}

int					checking(char *arg, char **file)
{
	int		y;
	int		i;

	if (!(*file = readfile(arg)))
		return (0);
	i = 1;
	y = 0;
	if (!(ft_isdigit((*file)[0])) && (*file)[0] != '{')
		return ((int)free_file(*file));
	while ((*file)[i])
	{
		if (!(is_valid((*file)[i], &y, (*file)[i - 1])))
			return ((int)free_file(*file));
		i++;
	}
	(*file)[i - 1] != '\n' ? y++ : 0;
	return (y);
}
