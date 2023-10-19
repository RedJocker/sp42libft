/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:05:33 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/19 19:38:52 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*fun)(void *))
{
	if (!lst || !fun)
		return ;
	while (lst)
	{
		fun(lst->content);
		lst = lst->next;
	}
}
