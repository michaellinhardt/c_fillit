/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconnat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:43:10 by mconnat           #+#    #+#             */
/*   Updated: 2015/12/09 16:22:24 by mconnat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	read_file(char	**path)
{
	int 	fd;
	int 	ret;
	char	buf[BUF_SIZE + 1];

	fd = open(path[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Not enough entries, end of process.\n", 2);
		exit(0);
	}

	while ((ret = read(fd, buf, BUF_SIZE)))
			{
			buf[ret] = '\0';
			ft_putstr(buf);
			ft_putnbr(ret);
			}
}
