/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathisaujogue <mathisaujogue@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:06:35 by maujogue          #+#    #+#             */
/*   Updated: 2023/01/16 16:33:44 by mathisaujog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void	radix_sort(t_list **ta, t_list **tb)
{
	int		i;
	int		j;
	int		size;
	int		num;

	i = 0;
	size = ft_lstsize(*ta);
	while (!is_sorted(*ta))
	{
		j = 0;
		while (j < size && !is_sorted(*ta))
		{
			num = (*ta)->data;
			if (((num >> i) & 1) == 1)
				rotate(ta, 'a');
			else
				push(tb, ta, 'b');
			j++;
		}
		while (*tb != NULL)
			push(ta, tb, 'a');
		i++;
	}
}

void	sort_3(t_list **ta, int i)
{
	if (!is_sorted(*ta))
	{
		if ((*ta)->data == i && (*ta)->next->data == i + 2)
		{
			reverse_rotate(ta, 'a');
			swap(*ta, 'a');
		}
		if ((*ta)->data == i + 2 && (*ta)->next->data == i + 1)
		{
			swap(*ta, 'a');
			reverse_rotate(ta, 'a');
		}
		if ((*ta)->data == i + 1 && (*ta)->next->data == i)
			swap(*ta, 'a');
		if ((*ta)->data == i + 2 && (*ta)->next->data == i)
			rotate(ta, 'a');
		if ((*ta)->data == i + 1 && (*ta)->next->data == i + 2)
			reverse_rotate(ta, 'a');
	}
}

void	sort_4(t_list **ta, t_list **tb, int i)
{
	if ((*ta)->next->data == i)
		rotate(ta, 'a');
	else if ((*ta)->next->next->data == i)
	{
		rotate(ta, 'a');
		rotate(ta, 'a');
	}
	else if ((*ta)->next->next->next->data == i)
		reverse_rotate(ta, 'a');
	if (!is_sorted(*ta))
	{
		push(tb, ta, 'b');
		sort_3(ta, i + 1);
		push(ta, tb, 'a');
	}
}

void	sort_5(t_list **ta, t_list **tb)
{
	if ((*ta)->next->data == 0)
		rotate(ta, 'a');
	if ((*ta)->next->next->data == 0)
	{
		rotate(ta, 'a');
		rotate(ta, 'a');
	}
	if ((*ta)->next->next->next->data == 0)
	{
		reverse_rotate(ta, 'a');
		reverse_rotate(ta, 'a');
	}
	if ((*ta)->next->next->next->next->data == 0)
		reverse_rotate(ta, 'a');
	push(tb, ta, 'b');
	sort_4(ta, tb, 1);
	push(ta, tb, 'a');
}
