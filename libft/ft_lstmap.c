/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:40:09 by fleblanc          #+#    #+#             */
/*   Updated: 2022/04/14 13:04:03 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*following;
	void	*tmp;

	if (!lst)
		return (NULL);
	tmp = f(lst->content);
	result = ft_lstnew(tmp);
	if (result == NULL)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		tmp = f(lst->content);
		following = ft_lstnew(tmp);
		if (following == NULL)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, following);
		lst = lst->next;
	}
	following->next = NULL;
	return (result);
}
