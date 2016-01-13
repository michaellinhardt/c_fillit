/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconnat <mconnat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:43:10 by mconnat           #+#    #+#             */
/*   Updated: 2016/01/12 12:24:44 by mconnat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**parse(char **path)
{
	int		len;
	char	**tab;

	len = buf_len(path);
	tab = check_file(path, len);
	return (tab);
}

int		buf_len(char **path)
{
	int		fd;
	int		i;
	char	buf[BUF_SIZE + 1];

	i = 0;
	if ((fd = open(path[1], O_RDONLY)) < 0)
		call_error(4);
	while (read(fd, buf, BUF_SIZE) > 0)
	{
		if (i > 26)
			call_error(10);
		i++;
	}
	if ((close(fd) == -1))
		call_error(5);
	return (i);
}

char	**check_file(char **path, int len)
{
	int			fd;
	static int	line;
	char		**tab;

	if ((fd = open(path[1], O_RDONLY)) == -1)
		call_error(4);
	tab = read_file(fd, &line, len);
	check_ret(line, len);
	return (tab);
}

char	**read_file(int fd, int *line, int len)
{
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	**tab;
	int		i;

	ret = 0;
	i = -1;
	tab = (char **)malloc(sizeof(char *) * (len + 1));
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		ret_len(buf, line);
		if (find_error(buf) == 0)
			tab[++i] = ft_strdup(buf);
	}
	if (ret == -1)
		call_error(1);
	tab[len] = NULL;
	return (tab);
}

int		find_error(char *buf)
{
	if (buf[4] != '\n' || buf[9] != '\n' || buf[14] != '\n' || buf[19] != '\n')
		call_error(7);
	if (check_tetri(buf, 0, 0, 0) != 0)
		call_error(2);
	return (0);
}
