/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahsini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:30:10 by olahsini          #+#    #+#             */
/*   Updated: 2019/02/14 23:49:50 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_chek_map(char **cube, char **map, int j, int i)
{
	int x;
	int y;
	int tmp_i;

	tmp_i = i;
	y = -1;
	while (cube[++y])
	{
		x = -1;
		i = tmp_i;
		if (map[j] == NULL)
			return (0);
		while (cube[y][++x])
		{
			if (((i || j) >= ft_strlen(map[0])) ||
			(map[j][i] != '.' && cube[y][x] != '.'))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

char	**c_map(char **cube, char **map, int j, int i)
{
	int x;
	int y;
	int tmp_i;

	tmp_i = i;
	y = -1;
	while (cube[++y])
	{
		x = -1;
		i = tmp_i;
		while (cube[y][++x])
		{
			if (map[j][i] == '.' && cube[y][x] != '.')
				map[j][i] = cube[y][x];
			i++;
		}
		j++;
	}
	return (map);
}

char	**new_map(int size)
{
	int		i;
	int		j;
	char	**map;

	map = (char **)malloc(sizeof(char*) * (size + 1));
	ft_bzero(map, size);
	i = -1;
	while (++i < size)
	{
		j = -1;
		map[i] = (char *)malloc(sizeof(char));
		while (++j < size)
			map[i][j] = '.';
	}
	map[i] = 0;
	i = -1;
	return (map);
}

void	cpy(char **dest, char **src)
{
	int	i;

	i = 0;
	delete_map(dest);
	while (src[i])
	{
		dest[i] = ft_strdup(src[i]);
		i++;
	}
	dest[i] = NULL;
}

void	delete_map(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		ft_strclr(map[i]);
		i++;
	}
}
