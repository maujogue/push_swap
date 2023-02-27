/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:37:37 by maujogue          #+#    #+#             */
/*   Updated: 2023/01/08 10:27:18 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

static int	check_str(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			count--;
		if ((!(str[i] >= '0' && str[i] <= '9') && (str[i] != ' '
					&& str[i] != '+' && str[i] != '-')) || count < 0
			|| ((str[i] == '+' || str[i] == '-')
				&& !(str[i + 1] >= '0' && str[i + 1] <= '9')))
			return (0);
		i++;
	}
	return (1);
}

int	check_errors(char *str, long nb, t_list *tab)
{
	int	i;

	if (nb > 2147483647 || nb < -2147483648)
		return (0);
	while (tab != NULL)
	{
		if (tab->data == nb)
			return (0);
		tab = tab->next;
	}
	if (check_str(str) == 0)
		return (0);
	i = 0;
	while (str[i] == ' ')
		i++;
	while ((str[i] >= '0' && str[i] <= '9')
		|| (str[i] == '-' || str[i] == '+' ))
		i++;
	while (str[i] == ' ')
		i++;
	if (str[i])
		return (0);
	return (1);
}
