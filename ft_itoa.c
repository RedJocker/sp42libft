/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:47:31 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/18 18:56:44 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_number
{
	size_t		len;
	long long	num;
	char		*str_num;
	char		digit;
}	t_number;

static size_t	str_num_len(long long num)
{
	size_t		len;

	len = 0;
	if (num < 0)
	{
		len++;
		num = -num;
	}
	while (num > 9)
	{
		num /= 10;
		len++;
	}
	return (++len);
}

static inline char	ch_digit(char byte_digit)
{
	return (byte_digit + '0');
}

char	*ft_itoa(int n)
{
	t_number	x;

	x.num = (long long)n;
	x.len = str_num_len(x.num);
	x.str_num = malloc((x.len + 1) * sizeof(char));
	if (!(x.str_num))
		return (NULL);
	x.str_num[x.len--] = '\0';
	if (x.num < 0)
	{
		x.str_num[0] = '-';
		x.num = -x.num;
	}
	while (x.num > 9)
	{
		x.digit = (char)(x.num % 10);
		x.str_num[x.len--] = ch_digit(x.digit);
		x.num /= 10;
	}
	x.digit = (char)(x.num % 10);
	x.str_num[x.len] = ch_digit(x.digit);
	return (x.str_num);
}
