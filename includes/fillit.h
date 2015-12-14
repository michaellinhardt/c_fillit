/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconnat <mconnat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 18:01:05 by mconnat           #+#    #+#             */
/*   Updated: 2015/12/09 16:23:38 by mconnat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define FILLIT_H

# include <fcntl.h>
# include "libft.h"
# define BUF_SIZE 545


void	read_and_check(char **path);
int		check_file(char *buf, int ret);
int		check_map(int ret, int pieces);
int		check_termi(char *buf);
int		solve_and_print(char **path);

#endif

