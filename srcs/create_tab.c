/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconnat <mconnat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 16:47:11 by mconnat           #+#    #+#             */
/*   Updated: 2015/12/29 16:47:14 by mconnat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_tab2(char *buf, char **tab)
{
	int		i;
	int		line;

	i = -1;
	line = 0;
	while (buf[++i] != '\0')
	{
		if (buf[i] == '\n')
			line++;
		if (line == 5)
		{
			line = 0;
			buf[i] = '*';
		}
	}
	tab = ft_strsplit(buf, '*');
	return (tab);
}
