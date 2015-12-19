/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconnat <mconnat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 18:01:05 by mconnat           #+#    #+#             */
/*   Updated: 2015/12/19 17:38:56 by mconnat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define FILLIT_H

# include <fcntl.h>
# include "libft.h"
# define BUF_SIZE 545

typedef	struct 		s_termi
{
	char 			*piece;
	int				pos;
	struct s_termi	*next;
}					termi;


int					check_connect_termi(char *buf, int i, int valid2);
void				call_error(int info);
char				*read_and_check(char **path, char *buf);
int					check_file(char *buf, int ret);
int					check_map(int ret, int pieces);
int					check_termi(char *buf);
int					solve_and_print(char **path);
termi				*buffer_to_list(char *buf, termi *list);
termi				*create_termi_list(termi *list, char *str, int pos);
char				**create_tab(char *buf, char **tab);
void				del_split_tab(char **tab, int nb_termi);
int					check_char_and_format(char *buf, int line, int char_nb, int pieces);
void				convert_list(termi *list);
char				put_to_top(termi *list, int ok);
char				put_to_left(termi *list, int ok);
char				*up_once(char *tmp);
char				*left_once(char *tmp);
char				put_to_alphabet(termi *list, char c);

#endif

