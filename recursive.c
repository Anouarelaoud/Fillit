/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahsini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:35:10 by olahsini          #+#    #+#             */
/*   Updated: 2019/02/18 14:38:37 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	remove_cube(char **map, char **cube)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (cube[0][++i])
		if (cube[0][i] != '.')
			c = cube[0][i];
	j = -1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
			if (map[j][i] == c)
				map[j][i] = '.';
	}
}

int		cal_m(char ***cube)
{
	int i;
	int p;

	p = 0;
	while (cube[p])
		p++;
	i = 0;
	while ((i * i) < p)
		i++;
	return (i);
}

char	ft_tetletter(char *tet)
{
	int i;

	i = 0;
	while (tet[i] == '.')
		i++;
	return (tet[i]);
}

int		print_result(char ***cube, char **map, int p)
{
	if (*cube == NULL)
	{
		ft_putendll(map, p);
		return (1);
	}
	return (0);
}

int		solver(char ***cube, char **map, int p)
{
	int i;
	int j;

	i = 0;
	if (print_result(cube, map, p) == 1)
		return (1);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_chek_map(*cube, map, i, j))
			{
				c_map(*cube, map, i, j);
				if (solver(cube + 1, map, p))
					return (1);
				remove_cube(map, *cube);
			}
			j++;
		}
		i++;
	}
	if (ft_tetletter((*cube)[0]) == 'A')
		solver(cube, new_map(p + 1), p + 1);
	return (0);
}
