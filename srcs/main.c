/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 16:48:05 by mconnat           #+#    #+#             */
/*   Updated: 2016/01/07 10:13:13 by mlinhard         ###   ########.fr       */
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
	solve_it(tab);
	return (0);
}

void	print_snap(t_mapsnap *mapsnap, int id)
{
	int		i = 0;
	t_mapsnap *prev;
	t_mapsnap *next;

	prev = (t_mapsnap *)mapsnap->prev;
	next = (t_mapsnap *)mapsnap->next;

	printf("---------- PRINT MAPSNAP START ----------\n");
	printf("loopinstance: %d\n", id);
	printf("snap .....ID: %d\n", mapsnap->id);
	printf("snap .....ok: { ");while (mapsnap->ok[i] > -1) { printf("%d,", mapsnap->ok[i]); i++; } printf("-1 }\n");
	printf("snap ...last: %d\n", mapsnap->last);
	printf("snap map_str:\n%s", mapsnap->map_str);
	if (prev)
		printf("snap ...prev: %d\n", prev->id);
	else
		printf("snap ...prev: (null)\n");
	if (next)
		printf("snap ...next: %d\n", next->id);
	else
		printf("snap ...next: (null)\n");

	printf("---------- PRINT MAPSNAP .OVER ----------\n");
}
