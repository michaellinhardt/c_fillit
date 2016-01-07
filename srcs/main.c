/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 16:48:05 by mconnat           #+#    #+#             */
/*   Updated: 2016/01/07 16:42:34 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	termi	*list;
	char 	**tab;
	char	*buf;
	int		***diez;

	buf = ft_strnew(BUF_SIZE);
	list = NULL;
	tab = NULL;
	diez = NULL;
	if (ac != 2)
		call_error(1);
	buf = read_and_check(av, buf);
	tab = create_tab2(buf, tab);
	convert_tab(tab);
//	list = buffer_to_list(buf, list);
//	convert_list(list);
//	ft_putstr(list->piece);
	diez = create_diez_tab(tab);
	//test(diez);
	ft_strdel(&buf);	
	solve_it(tab);
	return (0);
}

void		test(int ***diez)
{
	int i = 0;

	while (diez[i])
	{
		printf("-------------------------------\n");
		printf("Numeros-piece : %d\n", i);
		printf("diez 1 : %d - %d\n", diez[i][0][0], diez[i][0][1]);
		printf("diez 2 : %d - %d\n", diez[i][1][0], diez[i][1][1]);
		printf("diez 3 : %d - %d\n", diez[i][2][0], diez[i][2][1]);
		printf("diez 4 : %d - %d\n", diez[i][3][0], diez[i][3][1]);
		printf("-------------------------------\n");
		i++;
	}
}

void		print_snap(t_mapsnap *mapsnap, int id)
{
	int		i = 0;
	t_mapsnap *prev;
	t_mapsnap *next;

	prev = (t_mapsnap *)mapsnap->prev;
	next = (t_mapsnap *)mapsnap->next;

	printf("---------- PRINT MAPSNAP START ----------\n");
	printf("loopinstance: %d\n", id);
	printf("snap .....ID: %d\n", mapsnap->id);
	printf("snap .....ok: { "); while (mapsnap->ok[i] > -1) { printf("%d,", mapsnap->ok[i]); i++; } printf("-1 }\n");
	printf("snap ...last: %d\n", mapsnap->last);
	if (prev)
		printf("snap ...prev: %d\n", prev->id);
	else
		printf("snap ...prev: (null)\n");
	if (next)
		printf("snap ...next: %d\n", next->id);
	else
		printf("snap ...next: (null)\n");
	printf("snap map_str:\n%s", mapsnap->map_str);

	printf("---------- PRINT MAPSNAP .OVER ----------\n");
}