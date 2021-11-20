/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahsini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:35:39 by olahsini          #+#    #+#             */
/*   Updated: 2018/11/07 19:35:41 by olahsini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0 || (*str1 == '\0' && *str2 == '\0'))
		return (0);
	if (*str1 == *str2)
		return (ft_strncmp(s1 + 1, s2 + 1, n - 1));
	else
		return (*str1 - *str2);
}
