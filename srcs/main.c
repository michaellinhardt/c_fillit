/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 16:48:05 by mconnat           #+#    #+#             */
/*   Updated: 2016/01/07 22:53:23 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	char 	**tab;
	char	*buf;
	int		***diez;

	buf = ft_strnew(BUF_SIZE);
	tab = NULL;
	diez = NULL;
	if (ac != 2)
		call_error(1);
	buf = read_and_check(av, buf);
	tab = create_tab2(buf, tab);
	convert_tab(tab);
	diez = create_diez_tab(tab);
	ft_strdel(&buf);	
	solve_it(diez);
	return (0);
}
