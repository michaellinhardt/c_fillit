/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 16:48:05 by mconnat           #+#    #+#             */
/*   Updated: 2016/01/08 16:44:15 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	title(char *s, int *lol)
{
	printf("----------------------------------------\n");
	printf("---\t\t\t%s\n", s);
	printf("----------------------------------------\n");
	*lol = *lol + 1;
}

int		main(int ac, char **av)
{
	char 	**tab;
	char	*buf;
	int		***diez;
	int		lol;

	lol = 0;
	title("test", &lol);
	title("test", &lol);
	title("test", &lol);

	buf = ft_strnew(BUF_SIZE);
	tab = NULL;
	diez = NULL;
	if (ac != 2)
		call_error(1);
	buf = read_and_check(av, buf);
	tab = create_tab2(buf, tab);
	convert_tab(tab);
									//print_piece(tab);
	diez = create_diez_tab(tab);
	ft_strdel(&buf);
	solve_it(diez);
									//ft_putstr("----------------------------------------\n");
									//ft_putstr("---\t\t\tDEBUG\n");
									//ft_putstr("----------------------------------------\n");

	return (0);
}