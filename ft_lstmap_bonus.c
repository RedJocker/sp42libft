/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:03:44 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/31 19:30:52 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*fun)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*ptr;
	t_list	*temp;
	void	*content;

	if (!lst || !fun || !del)
		return (NULL);
	content = fun(lst->content);
	new_lst = ft_lstnew(content);
	if (!new_lst)
	{
		del(content);
		return (NULL);
	}
	ptr = new_lst;
	lst = lst->next;
	while (lst)
	{
		content = fun(lst->content);
		temp = ft_lstnew(content);
		if (!temp)
		{
			del(content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ptr->next = temp;
		ptr = ptr->next;
		lst = lst->next;
	}
	return (new_lst);
}
