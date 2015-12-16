/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconnat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:43:10 by mconnat           #+#    #+#             */
/*   Updated: 2015/12/15 22:53:58 by mconnat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	read_and_check(char	**path)
{
	int		fd;
	int 	ret;
	char	buf[BUF_SIZE + 1];

	fd = open(path[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("File openning error, end of process.\n", 2);
		exit(0);
	}
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if (check_file(buf, ret) == 1)
	{
		ft_putstr_fd("Invalid map file.\n", 2);
		exit(0);
	}
	if (check_termi(buf) == 1)
	{
		ft_putstr_fd("Invalid pieces file.\n", 2);
		exit(0);
	}
	if (close(fd) == -1)
		ft_putstr_fd("File closing error, end of process.\n", 2);
}
