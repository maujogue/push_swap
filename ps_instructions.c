/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathisaujogue <mathisaujogue@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 10:34:28 by maujogue          #+#    #+#             */
/*   Updated: 2023/01/16 15:52:54 by mathisaujog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void	swap(t_list *tab, char c)
{
	int		temp;

	if (!tab || !tab->next)
		return ;
	temp = tab->next->data;
	tab->next->data = tab->data;
	tab->data = temp;
	if (c == 'a')
		ft_printf("sa\n");
	if (c == 'b')
		ft_printf("sb\n");
}

void	swap_ss(t_list *tab1, t_list *tab2)
{
	swap(tab1, ' ');
	swap(tab2, ' ');
	ft_printf("ss\n");
}

void	push(t_list **ta, t_list **tb, char c)
{
	t_list	*tempb;
	t_list	*tempa;

	tempb = *tb;
	*tb = tempb->next;
	tempa = *ta;
	*ta = tempb;
	tempb->next = tempa;
	if (c == 'a')
		ft_printf("%s\n", "pa");
	else
		ft_printf("%s\n", "pb");
}
