/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconnat <mconnat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 15:16:02 by mconnat           #+#    #+#             */
/*   Updated: 2015/12/09 16:44:49 by mconnat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		main(int ac, char **av)
{
	if (ac > 2)
	{
		ft_putstr("Too many entries, end of process.\n");
		return (0);
	}
	else if (ac < 2)
	{
		ft_putstr("Not enough entries, end of process.\n");
		return (0);
	}

	else
	read_file(av);
	return (0);
}
