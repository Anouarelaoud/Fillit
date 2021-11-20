/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahsini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:21:17 by olahsini          #+#    #+#             */
/*   Updated: 2018/11/07 19:21:22 by olahsini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*f;

	i = 0;
	d = (unsigned char *)dst;
	f = (unsigned char *)src;
	while (i < n)
	{
		d[i] = f[i];
		i++;
	}
	return (d);
}
