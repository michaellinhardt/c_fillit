/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 15:16:02 by mconnat           #+#    #+#             */
/*   Updated: 2015/12/28 08:02:52 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int		main(int ac, char **av)
{
	termi	*list;
	//termi	*tmp;
	termi	*new;
	char	*buf;

	buf = ft_strnew(BUF_SIZE);
	list = NULL;
	if (ac != 2)
		call_error(1);
	buf = read_and_check(av, buf);
	list = buffer_to_list(buf, list);
	/*
	tmp = list; while (tmp->next) {
		printf("\npos : %d\nstr :\n%s\n", tmp->pos, tmp->piece);
		tmp = tmp->next;
	} printf("\npos : %d\nstr :\n%s\n", tmp->pos, tmp->piece);
	*/
	convert_list(list);

	new = list;	while (new->next) {
		printf("pos : %d\nstr :\n%s\n", new->pos, new->piece);
		new = new->next;
	} printf("pos : %d\nstr :\n%s\n", new->pos, new->piece);
	return (0);
}
