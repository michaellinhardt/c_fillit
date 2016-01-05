/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 19:15:07 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/05 03:22:13 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			map_first_size(char **tab)
{
	int		nb_pieces;
	int		racine;

	nb_pieces = -1;
	while (tab[++nb_pieces])
		;
	nb_pieces *= 4;
	racine = 1;
	while ((racine * racine) < nb_pieces && racine++)
		;
	return (racine);
}

char		*map_build(int map_size)
{
	char	*map_str;
	int		newline;
	int		newline_count;

	newline = map_size + 1;
	newline_count = newline;
	map_size = map_size * map_size + map_size;
	map_str = ft_strnew((map_size));
	map_str[map_size] = '\0';
	while(map_size > -1 && map_size--)
	{
		map_str[map_size] = (newline_count == newline) ? '\n' : '.' ;
		newline_count = (newline_count == newline) ? 1 : newline_count + 1 ;
	}
	return (map_str);
}

t_mapsnap	*snapit(t_mapsnap *prev, int *ok, char *map_str, int last)
{
	static int	id;
	t_mapsnap	*newsnap;

	if (!id)
		id = 0;
	if (!(newsnap = (t_mapsnap *)ft_memalloc(sizeof(t_mapsnap))))
		return (NULL);
	newsnap->id = id++;
	newsnap->next = NULL;
	newsnap->prev = prev;
	newsnap->ok = ok;
	newsnap->map_str = map_str;
	newsnap->last = last;
	if (prev)
		prev->next = newsnap;
	return (newsnap);
}

void		free_mapsnap(t_mapsnap *mapsnap)
{
	t_mapsnap	*free_it;
	t_mapsnap	*test;

	test = mapsnap;
	while (mapsnap->next)
		mapsnap = mapsnap->next;
	while (mapsnap->prev)
	{
		free_it = mapsnap;
		mapsnap = mapsnap->prev;
		free_this_snap(free_it);
	}
	free_this_snap(mapsnap);
}

void		free_this_snap(t_mapsnap *free_it)
{
	free_it->id = (int)NULL;
	free_it->next = (t_mapsnap *)NULL;
	free_it->prev = (t_mapsnap *)NULL;
	free(free_it->ok);
	free_it->ok = NULL;
	free(free_it->map_str);
	free_it->map_str = NULL;
	free_it->last = (int)NULL;
	free(free_it);
	free_it = NULL;
}
