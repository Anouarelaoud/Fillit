/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahsini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:29:46 by olahsini          #+#    #+#             */
/*   Updated: 2019/02/14 23:46:24 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putendll(char **str, int p)
{
	int i;
	int	j;

	i = 0;
	while (i < p)
	{
		j = 0;
		while (j < p)
		{
			ft_putchar(str[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		ft_helper(int fd)
{
	int		i;
	char	***cube;

	cube = (char ***)malloc(sizeof(char**) * 27);
	if (read_file(fd, cube) == -1)
		return (-1);
	i = -1;
	while (cube[++i])
		if (check_conn(cube[i]) != 6 && check_conn(cube[i]) != 8)
			return (-1);
	ft_crop(cube);
	solver(cube, new_map(cal_m(cube)), cal_m(cube));
	i = -1;
	while (cube[++i])
		ft_strdel(cube[i]);
	return (0);
}

int		main(int argc, char **argv)
{
	int fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			ft_putendl("error");
			return (0);
		}
		if (ft_helper(fd) != 0)
		{
			ft_putendl("error");
			return (0);
		}
	}
	else
		ft_putstr("usage: 	./fillit Source file\n");
	return (0);
}
