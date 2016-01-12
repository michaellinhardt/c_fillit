/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 18:01:05 by mconnat           #+#    #+#             */
/*   Updated: 2016/01/12 01:56:05 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>

# include <fcntl.h>
# include "libft.h"
# define BUF_SIZE 21

/*
** fichier main.c
*/

void	call_error(int info);

/*
** fichier parse.c
*/

char	**parse(char **path);
int		buf_len(char **path);
char	**check_file(char **path, int len);
int		find_error(char *buf);
char	**read_file(int fd, int *line, int len);

/*
** fichier parse2.c
*/

void	ret_len(char *buf, int *line);
void	check_ret(int line, int len);
int		check_tetri(char *buf);
void	check_connect_tetri(char *buf, int i, int *valid2, int *valid);

/*
** fichier read_file.c
*/

char	*read_and_check(char **path, char *buf);

/*
** fichier check_file.c
*/

int		check_map(int ret, int pieces);
int		check_termi(char *buf);
int		check_char_and_format(char *buf, int line, int char_nb, int pieces);
int		check_connect_termi(char *buf, int i, int valid2);

/*
** fichier convert_tab2.c
*/

char	put_to_alphabet_tab(char *str, char c);

/*
** fichier create_tab.c
*/

char	**create_tab2(char *buf, char **tab);

/*
**fichier convert_tab.c
*/

void	convert_tab(char **tab);
char	put_to_top_tab(char *str, int ok);
char	*up_once_tab(char *tmp);
char	put_to_left_tab(char *str, int ok);
char	*left_once_tab(char *tmp);

/*
**fichier create_diez_tab.c
*/

int		***create_diez_tab(char **tab);
int		**found_coord(char *tab, int **diez);
int		**set_letter(int **diez);
void	line_counter(int *line, int *row, char c);

/*
** fichier free.c
*/

void	free_tab(char **tab);
void	free_diez(int ***diez);

/*
** fichier solve_it.c
*/

void	solve_it(int ***diez);
int		fillit(char *map_str, int *ok, int ***diez, int map_size);

/*
** fichier map.c
*/

int		map_first_size(int ***diez);
char	*map_build(int map_size);
int		map_insert(char *map_str, int **diez, int map_size, size_t i);
int		calc_check_pos(int i, int line, int row, int map_size);
char	*put_piece_on_map(char *map_str, int **diez, int i, int map_size);

/*
** fichier map2.c
*/

void	map_remove(char *map_str, int **diez, int map_size, size_t i);

/*
** fichier pieces.c
*/

int		*ok_build(int ***diez);
int		*ok_remove(int *ok, int piece);

#endif
