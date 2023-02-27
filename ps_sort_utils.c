/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathisaujogue <mathisaujogue@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:24:48 by mathisaujog       #+#    #+#             */
/*   Updated: 2023/01/16 16:33:35 by mathisaujog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int	is_sorted(t_list *tab)
{
	int	i;

	if (!tab)
		return (1);
	i = tab->data;
	tab = tab->next;
	while (tab != NULL)
	{
		if (tab->data < i)
			return (0);
		i = tab->data;
		tab = tab->next;
	}
	return (1);
}

int	get_index(t_list *cpy, int nb)
{
	int	j;

	j = 0;
	while (cpy->data != nb)
	{
		cpy = cpy->next;
		j++;
	}
	return (j);
}

void	replace_with_index(t_list *ta, t_list *tc)
{
	int		i;
	int		j;
	t_list	*tmp;
	t_list	*tmp_cpy;
	t_list	*cpy;

	cpy = cpy_list(ta);
	tmp = ta;
	tmp_cpy = cpy;
	i = 0;
	while (tc != NULL)
	{
		j = 0;
		ta = tmp;
		cpy = tmp_cpy;
		j = get_index(cpy, tc->data);
		while (j--)
			ta = ta->next;
		ta->data = i;
		tc = tc->next;
		i++;
	}
	ft_lstclear(&cpy);
}
