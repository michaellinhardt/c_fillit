/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconnat <mconnat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 12:01:03 by mconnat           #+#    #+#             */
/*   Updated: 2015/12/30 12:25:35 by mconnat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_piece_table(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		*create_int_array(char **tab)
{
	int max;
	int min;
	int *piece;

	min = 0;
	max = count_piece_table(tab);
	piece = (int *)malloc(sizeof(int) * (max - min));
	while (piece[min] < max)
	{
		piece[min] = min;
		min++;			
	}
	return (piece);
}

int		*delete_piece(int *piece, int pos)
{
	
}
