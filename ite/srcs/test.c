/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 16:48:05 by mconnat           #+#    #+#             */
/*   Updated: 2016/01/11 13:59:51 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	separator(char *s)
{
	printf("====================\n-> %s\n====================\n", s);
}

void		testit(void)
{
	t_tetri *t;

	
	t = tetri_init(NULL, 5);
	//separator("TETRI"); tetri_print(t, 1);
	generate(t, guide_init(t), tetri_total(t, 0));
}

void	generate(t_tetri *t, t_guide *g, int t_total)
{
	int t_done;
	t_tetri *f;

	separator("LOOP INIT");
	tetri_print(t, 0);
	guide_print(g, 0);
	separator("LOOP START");

	f = t;
	t_done = 0;
	while (t_done < t_total)
	{
		if (!g->last && g->nb > g->max)
		{
			printf("* Map incrémentation\n");
			break ;
		}
		t_done = 0;
		
			
		break;
	}
	printf("Over!\n");
	tetri_print(f, 0);
}

int 	tetri_insert(t_tetri *t, t_guide *g)
{
	while (t)
	{
		if (!t->boo && g->nb < g->max)
		{
			printf("insert: %d\n", t->id);
			g->nb += 1;
			return ((t->boo = 1));
		}
		t = t->next;
	}
	g->last += 1;
	return (0);
}

int 	tetri_total(t_tetri *t, int i)
{
	t_tetri *n;

	n = t;
	if (n->next)
		return (tetri_total(n->next, i + 1));
	return (i + 1);
}

t_guide	*guide_init(t_tetri *t)
{
	t_guide *g;

	g = (t_guide*)malloc(sizeof(t_guide) * 1);
	g->last = 0;
	g->nb = 1;
	g->max = tetri_total(t, 0);
	g->prev = NULL;
	return (g);
}

t_tetri		*tetri_init(t_tetri *next, int nb)
{
	t_tetri		*t;

	t = (t_tetri*)malloc(sizeof(t_tetri)*1);
	t->id = nb;
	t->boo = 0;
	t->next = next;
	if ((nb - 1) > 0)
		return (tetri_init(t, (nb -1)));
	else
		return (t);
}

void		tetri_print(t_tetri *t, int i)
{
	t_tetri		*n;

	if (!i)
		printf("* Tetriminos:\n");
	else
		printf("----------\n");
	printf("ID: %d\nboo: %d\n", t->id, t->boo);
	if ((n = t->next))
	{
		printf("next: (%d)\n", n->id);
		if (i)
			tetri_print(t->next, i);
	}
}

void		guide_print(t_guide *g, int i)
{
	t_guide		*n;

	if (!i)
		printf("* Guide:\n");
	else
		printf("----------\n");
	printf("last: %d\nnb: %d\nmax: %d\n", g->last, g->nb, g->max);
	if ((n = g->prev))
	{
		printf("g->prev->last: (%d)\n", n->last);
		if (i)
			guide_print(g->prev, i);
	}
}