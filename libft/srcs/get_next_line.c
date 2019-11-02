/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 12:01:05 by akrache           #+#    #+#             */
/*   Updated: 2019/03/27 16:33:51 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <limits.h>
#include <fcntl.h>

static int	ft_readline(char **res, int fd)
{
	char	*tmp;
	int		i;
	char	buf[GNL_BUFF_SIZE + 1];

	while (!(ft_strchr(res[fd], '\n')))
	{
		if ((i = (int)read(fd, buf, GNL_BUFF_SIZE)) <= 0)
			return (i);
		buf[i] = '\0';
		tmp = res[fd];
		if (!(res[fd] = ft_strjoin(res[fd], buf)))
			return (-1);
		free(tmp);
	}
	return (1);
}

static int	ft_gnl(const int fd, char **line, char **res)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = res[fd];
	while (res[fd][i] != '\n' && res[fd][i] != '\0')
		i++;
	if (i || res[fd][i] == '\n')
	{
		if (!(*line = ft_strsub(res[fd], 0, i)))
			return (-1);
	}
	else
		*line = 0;
	if (*line)
	{
		if (!(res[fd] = ft_strdup(res[fd] + i + (res[fd][i] == '\0' ? 0 : 1))))
			return (-1);
	}
	else
		res[fd] = 0;
	ft_strdel(&tmp);
	return (*line ? 1 : 0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*res[OPEN_MAX];
	int			i;
	char		tmp[1];

	if (fd < 0 || !line || fd >= OPEN_MAX)
		return (-1);
	if ((i = (int)read(fd, tmp, 0)) == -1)
		return (-1);
	if (!(res[fd]))
		if (!(res[fd] = ft_strnew(0)))
			return (-1);
	if ((i = ft_readline(res, fd)) == -1)
		return (-1);
	return (ft_gnl(fd, line, res));
}
