/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconnat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:43:10 by mconnat           #+#    #+#             */
/*   Updated: 2015/12/19 17:47:17 by mconnat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	*read_and_check(char **path, char *buf)
{
	int		fd;
	int		ret;

	fd = open(path[1], O_RDONLY);
	if (fd == -1)
		call_error(4);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if (check_file(buf, ret) == 1)
		call_error(3);
	if (check_termi(buf) == 1)
		call_error(2);
	return (buf);
}

void	call_error(int info)
{
	if (info == 1)
		ft_putstr("error wrong arguments\n");
	if (info == 2)
		ft_putstr("error bad pieces\n");
	if (info == 3)
		ft_putstr("error bad map\n");
	if (info == 4)
		ft_putstr("error open\n");
	exit(0);
}
