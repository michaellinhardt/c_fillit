/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconnat <mconnat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 14:03:48 by mconnat           #+#    #+#             */
/*   Updated: 2015/12/17 22:24:03 by mconnat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

termi	*buffer_to_list(char *buf, termi *list)
{
	/*int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];*/
	char	**tab;
	int 	nb_termi;

	nb_termi = -1;
	tab = NULL;
	//fd = open(path[1], O_RDONLY);
	//ret = read(fd, buf, BUF_SIZE);
	//buf[ret] = '\0';
	tab = create_tab(buf, tab);
	while (tab[++nb_termi])
		list = create_termi_list(list, tab[nb_termi], nb_termi);
	del_split_tab(tab, nb_termi);
	return (list);
}


termi	*create_termi_list(termi *list, char *str, int pos)
{
	termi 	*new;
	termi	*tmp;

	new = (termi *)malloc(sizeof(termi));
	if (new)
	{
		new->piece = ft_strdup(str);
		new->pos = pos;
		new->next = NULL;
	}
	if (list == NULL)
		return (new);
	tmp = list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (list);
}

char	**create_tab(char *buf, char **tab)
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

void	del_split_tab(char **tab, int nb_termi)
{

	while (nb_termi > -1)
	{
		free(tab[nb_termi]);
		nb_termi--;
	}
	free(tab);
}
