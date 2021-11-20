/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahsini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:35:14 by olahsini          #+#    #+#             */
/*   Updated: 2018/11/07 19:35:16 by olahsini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	n;
	int				i;
	char			*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	i = 0;
	n = 0;
	while (s[i])
	{
		str[i] = f(n, s[i]);
		i++;
		n++;
	}
	str[i] = '\0';
	return (str);
}
