/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahsini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:31:24 by olahsini          #+#    #+#             */
/*   Updated: 2019/02/14 22:48:59 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_conn(char **cube)
{
	int i;
	int j;
	int x;

	x = 0;
	i = -1;
	while (cube[++i])
	{
		j = -1;
		while (cube[i][++j])
		{
			if (cube[i][j] == '#')
			{
				((j < 3) && (cube[i][j + 1] == '#')) ? (x += 1) : (x = x * 1);
				((j > 0) && (cube[i][j - 1] == '#')) ? (x += 1) : (x = x * 1);
				((i < 3) && (cube[i + 1][j] == '#')) ? (x += 1) : (x = x * 1);
				((i > 0) && (cube[i - 1][j] == '#')) ? (x += 1) : (x = x * 1);
			}
		}
	}
	return (x);
}

int		file_check(char opt[27][22], int i)
{
	if (opt[i + 1][0] != '\0')
	{
		if ((ft_count_char(opt[i], '#') != 4) ||
				(ft_count_char(opt[i], '.') != 12) ||
				(ft_count_char(opt[i], '\n') != 5) || opt[i][0] == '\n')
			return (-1);
	}
	else if (opt[i][20] != '\0' || (ft_count_char(opt[i], '.') != 12) ||
		(ft_count_char(opt[i], '\n') != 4) ||
		(ft_count_char(opt[i], '\n') != 4) || opt[i][0] == '\n')
		return (-1);
	return (0);
}

int		read_file(int fd, char ***cube)
{
	int		i;
	int		rd;
	char	opt[27][22];

	i = 0;
	while ((rd = read(fd, opt[i], 21)) > 0)
		i++;
	if (i == 0 || i > 26)
		return (-1);
	opt[i][0] = '\0';
	i = -1;
	while (opt[++i][0] != '\0')
	{
		if (file_check(opt, i) != 0)
			return (-1);
	}
	i = -1;
	while (opt[++i][0] != '\0')
		cube[i] = ft_strsplit(opt[i], '\n');
	cube[i] = 0;
	return (0);
}
