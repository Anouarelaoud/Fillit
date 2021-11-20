/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahsini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:40:23 by olahsini          #+#    #+#             */
/*   Updated: 2018/11/07 19:40:25 by olahsini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t		ft_ltyhsb(const char *s, char c)
{
	int		j;
	size_t	word;

	j = 0;
	word = 0;
	while (s[j] != '\0')
	{
		if (s[j] != c && (s[j + 1] == c || s[j + 1] == '\0'))
			word++;
		j++;
	}
	return (word);
}

static	char		**ft_lblsa(char const *s, char c, char **tbli)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		j = 0;
		if ((s[i] != c && s[i - 1] == c) || (i == 0 && s[i] != c))
		{
			while (s[i + j] != c && s[i + j] != '\0')
				j++;
			tbli[k] = ft_strsub(s, i, j);
			if (tbli[k] == NULL)
				free(tbli[k]);
			k++;
			i = i + j;
		}
		if (s[i] == '\0')
			break ;
		i++;
	}
	tbli[k] = (NULL);
	return (tbli);
}

char				**ft_strsplit(char const *s, char c)
{
	char		**tbli;
	size_t		z;

	if (!s)
		return (NULL);
	z = ft_ltyhsb(s, c);
	tbli = (char **)malloc(sizeof(char *) * (z + 1));
	if (tbli == (NULL))
		return (NULL);
	tbli = ft_lblsa(s, c, tbli);
	return (tbli);
}
