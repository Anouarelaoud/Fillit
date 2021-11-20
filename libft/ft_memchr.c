/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahsini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:15:10 by olahsini          #+#    #+#             */
/*   Updated: 2018/11/07 19:15:14 by olahsini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*src;
	char	cc;
	size_t	i;

	i = 0;
	src = (char *)s;
	cc = (char)c;
	while (i < n)
	{
		if (src[i] == cc)
			return ((void *)(src + i));
		i++;
	}
	return (NULL);
}
