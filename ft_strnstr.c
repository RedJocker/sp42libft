/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:55:03 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/16 00:32:23 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reset_match(char **match, char **p_needle, const char *needle)
{
	*match = NULL;
	*p_needle = (char *) needle;
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*match;
	char	*p_needle;
	size_t	i;

	match = (char *) haystack;
	p_needle = (char *) needle;
	i = 0;
	if (haystack == NULL && len == 0)
		return (NULL);
	while (haystack[i] && *p_needle && i < len)
	{
		if (match == NULL && haystack[i] == *p_needle)
			match = (char *)(haystack + i);
		else if (match != NULL && haystack[i] != *p_needle)
			reset_match(&match, &p_needle, needle);
		if (match != NULL)
			p_needle++;
		i++;
	}
	if (*p_needle == '\0')
		return (match);
	else
		return (NULL);
}
