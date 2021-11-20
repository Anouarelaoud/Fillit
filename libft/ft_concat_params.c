/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahsini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:19:22 by olahsini          #+#    #+#             */
/*   Updated: 2018/11/07 15:19:27 by olahsini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_indest(char *dest, int argc, char **argv)
{
	int			i;
	int			j;
	int			len;

	len = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			dest[len] = argv[i][j];
			j++;
			len++;
		}
		if (i != argc - 1)
		{
			dest[len] = '\n';
			len++;
		}
		i++;
	}
	dest[len] = '\0';
	return (dest);
}

char			*ft_concat_params(int argc, char **argv)
{
	char		*dest;
	int			len;
	int			i;
	int			j;

	len = 0;
	i = 1;
	if (argc < 1)
		return (0);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j++] != '\0')
			len++;
		i++;
	}
	dest = (char*)malloc(len * sizeof(char));
	if (dest)
	{
		dest = ft_indest(dest, argc, argv);
		return (dest);
	}
	return (0);
}
