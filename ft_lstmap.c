/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:09:54 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/19 19:43:43 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*fun)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*ptr;
	t_list	*temp;

	if (!lst || !fun || !del)
		return (NULL);
	new_lst = ft_lstnew(fun(lst->content));
	if (!new_lst)
		return (NULL);
	ptr = new_lst;
	lst = lst->next;
	while (lst)
	{
		temp = ft_lstnew(fun(lst->content));
		if (!temp)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ptr->next = temp;
		ptr = ptr->next;
		lst = lst->next;
	}
	return (new_lst);
}
