/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_lst_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:28:03 by maujogue          #+#    #+#             */
/*   Updated: 2023/01/15 15:30:06 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*curr;
	int		i;

	curr = lst;
	i = 0;
	while (curr != NULL)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

t_list	*sort_list(t_list *lst)
{
	int		swap;
	t_list	*tmp;

	tmp = lst;
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		if (lst->data > lst->next->data)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}

t_list	*cpy_list(t_list *lst)
{
	t_list	*new_lst;

	new_lst = NULL;
	if (!lst)
		return (NULL);
	while (lst != NULL)
	{
		ft_lstadd_back(&new_lst, ft_lstnew(lst->data));
		lst = lst->next;
	}
	return (new_lst);
}
