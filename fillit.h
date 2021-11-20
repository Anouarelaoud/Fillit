/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahsini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:53:20 by olahsini          #+#    #+#             */
/*   Updated: 2019/02/14 23:23:38 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "fcntl.h"
# include "unistd.h"
# include "stdlib.h"
# include "libft/libft.h"

void	ft_putendll(char **str, int p);
int		ft_helper(int fd);
void	cpy(char **dest, char **src);
int		file_check(char opt[27][22], int i);
void	ft_print_cube(char ***cube);
void	remove_cube(char **map, char **cube);
void	delete_map(char **map);
int		ft_count_char(char const *s, char c);
int		read_file(int fd, char ***cube);
int		check_conn(char **cube);
int		hash_count(char **cube);
int		hash_pos(char **cube);
int		cal_m(char ***cube);
char	**map_c(char ***cube, int p);
char	**ft_crop(char ***cube);
int		print_result(char ***cube, char **map, int p);
char	**new_map(int size);
char	ft_tetletter(char *tet);
char	**c_map(char **map, char **cube, int i, int j);
int		ft_chek_map(char **map, char **cube, int j, int i);
int		solver(char ***cube, char **map, int p);

#endif
