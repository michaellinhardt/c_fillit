/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconnat <mconnat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 16:48:05 by mconnat           #+#    #+#             */
/*   Updated: 2015/12/29 16:48:09 by mconnat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	termi	*list;
	char 	**tab;
	char	*buf;

	buf = ft_strnew(BUF_SIZE);
	list = NULL;
	tab = NULL;
	if (ac != 2)
		call_error(1);
	buf = read_and_check(av, buf);
	tab = create_tab2(buf, tab);
	convert_tab(tab);
//	list = buffer_to_list(buf, list);
//	convert_list(list);
//	ft_putstr(list->piece);
	ft_strdel(&buf);	
	int i;
	i = 0;
	while(tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
	/* Segfault quand décommenté car buf est maintenant vide */
	//ft_putstr(buf);
//	solveit(list);
	return (0);
}
