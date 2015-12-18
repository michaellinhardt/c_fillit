/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconnat <mconnat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 15:16:02 by mconnat           #+#    #+#             */
/*   Updated: 2015/12/17 22:46:34 by mconnat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/fillit.h"

int		main(int ac, char **av)
{
	termi	*list;
	termi	*tmp;
	termi *new;
	char	*buf;

	buf = NULL;
	list = NULL;
	if (ac > 2)
	{
		ft_putstr_fd("Too many entries, end of process.\n", 2);
		return (0);
	}
	else if (ac < 2)
	{
		ft_putstr_fd("Not enough entries, end of process.\n", 2);
		return (0);
	}
	else
	buf = read_and_check(av);
	list = buffer_to_list(buf, list);
	tmp = list;
	while (tmp->next)
	{
		printf("\npos : %d\nstr :\n%s\n", tmp->pos, tmp->piece);
		tmp = tmp->next;
	}
	printf("\npos : %d\nstr :\n%s\n", tmp->pos, tmp->piece);
	convert_list(list);
	new = list;
	while (new->next)
	{
		printf("\npos : %d\nstr :\n%s\n", new->pos, new->piece);
		new = new->next;
	}
	printf("\npos : %d\nstr :\n%s\n", new->pos, new->piece);
	//solve_and_print(av);
	//ft_putstr("Can You fillit ?\nYes we can !\n");
	return (0);
}
