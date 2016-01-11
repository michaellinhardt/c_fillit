/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 16:48:05 by mconnat           #+#    #+#             */
/*   Updated: 2016/01/09 21:06:59 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_diez(int ***diez)
{
		int i = -1; int j = -1; int k = -1;
	while (diez[++i])
	{
		printf("Piece: %d\n", i);
		while (diez[i][++j])
				printf("%d - %d - %d\n", diez[i][j][0], diez[i][j][1], diez[i][j][2]);
		j = -1;
	}
	j++; k++;
}

void	print_ok(int *ok)
{
	int i = -1;
	printf("{ "); while (ok[++i] > -1) printf("%d,", ok[i]); printf("-1 }\n");
}

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
	free_tab(tab);
	ft_strdel(&buf);
	solve_it(diez);
	free_diez(diez);

	return (0);
}