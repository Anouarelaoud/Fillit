/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_function.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahsini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:30:47 by olahsini          #+#    #+#             */
/*   Updated: 2019/02/14 22:46:01 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_char(char const *s, char c)
{
	unsigned int	i;
	int				cntr;

	i = -1;
	cntr = 0;
	while (s[++i])
		if (s[i] == c)
			cntr++;
	return (cntr);
}

int		hash_count(char **cube)
{
	int i;
	int j;
	int x;

	x = 0;
	j = 0;
	i = -1;
	while (cube[j][++i])
	{
		if (cube[j][i] == '#' || cube[j + 1][i] == '#' ||
			cube[j + 2][i] == '#' || cube[j + 3][i] == '#')
			x++;
	}
	return (x);
}

int		hash_pos(char **cube)
{
	int i;
	int j;

	j = 0;
	i = -1;
	while (cube[j][++i])
	{
		if (cube[j][i] == '#' || cube[j + 1][i] == '#' ||
			cube[j + 2][i] == '#' || cube[j + 3][i] == '#')
			return (i);
	}
	return (0);
}

void	ft_indice_copy(char ***cube, char **tmp, int k)
{
	static int	x;
	int			j;
	int			i;

	j = -1;
	while (tmp[++j])
	{
		cube[k][j] = ft_strdup(tmp[j]);
		ft_strclr(tmp[j]);
		i = -1;
		while (cube[k][j][++i])
			if (cube[k][j][i] == '#')
				cube[k][j][i] = (char)(x + 65);
	}
	cube[k][j] = 0;
	x++;
}

char	**ft_crop(char ***cube)
{
	int		i;
	int		j;
	int		k;
	char	**tmp;

	tmp = (char **)malloc(sizeof(char*) * 5);
	k = -1;
	while (cube[++k])
	{
		j = -1;
		i = -1;
		while (cube[k][++j])
			if (ft_count_char(cube[k][j], '#') > 0)
				tmp[++i] = ft_strdup(
				ft_strsub(cube[k][j], hash_pos(cube[k]), hash_count(cube[k])));
		tmp[++i] = 0;
		j = -1;
		while (cube[k][++j])
			ft_strclr(cube[k][j]);
		j = -1;
		ft_indice_copy(cube, tmp, k);
	}
	return (NULL);
}
