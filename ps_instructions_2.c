/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instructions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathisaujogue <mathisaujogue@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:17:01 by maujogue          #+#    #+#             */
/*   Updated: 2023/01/16 15:52:32 by mathisaujog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void	rotate(t_list **ta, char c)
{
	t_list	*new;
	t_list	*old;

	if (!*ta)
		return ;
	old = *ta;
	new = ft_lstnew((*ta)->data);
	ft_lstadd_back(ta, new);
	*ta = (*ta)->next;
	free(old);
	if (c == 'a')
		ft_printf("ra\n");
	if (c == 'b')
		ft_printf("rb\n");
}

void	rotate_rr(t_list **ta, t_list **tb)
{
	rotate(ta, 'a');
	rotate(tb, 'b');
	ft_printf("rr\n");
}

void	reverse_rotate(t_list **ta, char c)
{
	t_list	*new;
	t_list	*old;

	if (!*ta)
		return ;
	old = ft_lstlast(*ta);
	new = ft_lstnew(old->data);
	ft_lstadd_front(ta, new);
	old->previous->next = NULL;
	free(old);
	if (c == 'a')
		ft_printf("rra\n");
	if (c == 'b')
		ft_printf("rrb\n");
}

void	reverse_rrr(t_list **ta, t_list **tb)
{
	reverse_rotate(ta, ' ');
	reverse_rotate(tb, ' ');
	ft_printf("rrr\n");
}
