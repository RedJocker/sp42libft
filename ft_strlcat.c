/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:48:13 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/23 19:48:20 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	int		i;
	int		limit;

	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	len = ft_strlen(dst);
	if (len > dstsize)
	{
		len = dstsize + ft_strlen(src);
		return (len);
	}
	i = 0;
	limit = dstsize - len - 1;
	while (src[i] && i < limit)
	{
		dst[i + len] = src[i];
		i++;
	}
	dst[i + len] = '\0';
	len += ft_strlen(src);
	return (len);
}
