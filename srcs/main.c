/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconnat <mconnat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 16:48:05 by mconnat           #+#    #+#             */
/*   Updated: 2016/01/12 12:25:42 by mconnat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	char	**tab;
	int		***diez;

	tab = NULL;
	diez = NULL;
	if (ac != 2)
		call_error(1);
	tab = parse(av);
	convert_tab(tab);
	diez = create_diez_tab(tab);
	free_tab(tab);
	solve_it(diez);
	free_diez(diez);
	return (0);
}

void	call_error(int info)
{
	ft_putstr("error\n");
	exit(1);
	if (info == 1)
		ft_putstr("error wrong arguments\n");
	if (info == 2)
		ft_putstr("error bad pieces\n");
	if (info == 3)
		ft_putstr("error bad map\n");
	if (info == 4)
		ft_putstr("error open\n");
	if (info == 5)
		ft_putstr("error close\n");
	if (info == 6)
		ft_putstr("error char\n");
	if (info == 7)
		ft_putstr("error line\n");
	if (info == 8)
		ft_putstr("error modulo\n");
	if (info == 42)
		ft_putstr("malloc error\n");
	if (info == 10)
		ft_putstr("lolilol error\n");
	exit(1);
}
