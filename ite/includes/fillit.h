/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 18:01:05 by mconnat           #+#    #+#             */
/*   Updated: 2016/01/11 13:22:22 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>

# include <fcntl.h>
# include "libft.h"
# define BUF_SIZE 545

// fichier read_file.c
char	*read_and_check(char **path, char *buf);
void	call_error(int info);

// fichier check_file.c
int		check_file(char *buf, int ret);
int		check_map(int ret, int pieces);
int		check_termi(char *buf);
int		check_char_and_format(char *buf, int line, int char_nb, int pieces);
int		check_connect_termi(char *buf, int i, int valid2);

// fichier convert_tab2.c
char	put_to_alphabet_tab(char *str, char c);

// fichier create_tab.c
char	**create_tab2(char *buf, char **tab);

// fichier convert_tab.c
void	convert_tab(char **tab);
char	put_to_top_tab(char *str, int ok);
char	*up_once_tab(char *tmp);
char	put_to_left_tab(char *str, int ok);
char	*left_once_tab(char *tmp);

// fichier create_diez_tab.c
int		***create_diez_tab(char **tab);
int		**found_coord(char *tab,int **diez);
int		**set_letter(int **diez);

// fichier free.c
void	free_tab(char **tab);
void	free_diez(int ***diez);

// fichier solve_it.c
void	solve_it(int ***diez);
int		fillit(char *map_str, int *ok, int ***diez, int map_size);

// fichier map.c
int		map_first_size(int ***diez);
char	*map_build(int map_size);
int		map_insert(char *map_str, int **diez, int map_size, size_t *j);
int		calc_check_pos(int i, int line, int row, int map_size);
char	*put_piece_on_map(char *map_str, int **diez, int i, int map_size);

// fichier map2.c
void	map_remove(char *map_str, int **diez, int map_size, size_t *j);

// fichier pieces.c
int		*ok_build(int ***diez);
int		*ok_remove(int *ok, int piece);

//debug
void	print_diez(int ***diez);
void	print_ok(int *ok);

typedef struct		s_guide
{
	int 			last;
	int 			nb;
	int 			max;
	struct s_guide	*prev;
}					t_guide;

typedef struct		s_tetri
{
	int 			id;
	int 			boo;
	struct s_tetri	*next;
}					t_tetri;

// ite test
t_tetri		*tetri_init(t_tetri *next, int nb);
void		testit(void);
void		tetri_print(t_tetri *t, int i);
void	generate(t_tetri *t, t_guide *g, int t_total);
t_guide	*guide_init(t_tetri *t);
void		guide_print(t_guide *t, int i);
int 	tetri_total(t_tetri *t, int i);
int 	tetri_insert(t_tetri *t, t_guide *g);

#endif
