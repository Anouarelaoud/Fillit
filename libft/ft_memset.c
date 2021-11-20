/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahsini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:22:46 by olahsini          #+#    #+#             */
/*   Updated: 2018/11/07 19:22:49 by olahsini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	letter;

	str = (unsigned char *)b;
	letter = (unsigned char)c;
	while (len > 0)
	{
		str[len - 1] = letter;
		len--;
	}
	return ((void *)b);
}
