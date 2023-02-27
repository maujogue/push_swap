/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:52:45 by maujogue          #+#    #+#             */
/*   Updated: 2023/01/17 13:26:37 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int	get_list_one_arg(char *str, t_list **tab)
{
	int		i;
	char	**str_tab;

	str_tab = NULL;
	i = -1;
	str_tab = ft_split(str, ' ');
	while (str_tab[++i])
	{
		if (check_errors(str_tab[i], ft_atoi(str_tab[i]), *tab))
			ft_lstadd_back(tab, ft_lstnew(ft_atoi(str_tab[i])));
		else
		{
			ft_printf("Error\n");
			ft_lstclear(tab);
			break ;
		}
	}
	i = -1;
	while (str_tab[++i])
		free(str_tab[i]);
	free(str_tab);
	return (1);
}

int	get_list_multiple_arg(int argc, char **argv, t_list **tab)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (check_errors(argv[i], ft_atoi(argv[i]), *tab))
			ft_lstadd_back(tab, ft_lstnew(ft_atoi(argv[i])));
		else
		{
			ft_printf("Error\n");
			ft_lstclear(tab);
			return (0);
		}
		i++;
	}
	return (1);
}

void	push_swap(t_list **ta, t_list **tb, t_list **tc)
{
	*tc = cpy_list(*ta);
	sort_list(*tc);
	replace_with_index(*ta, *tc);
	if (ft_lstsize(*ta) == 3)
		sort_3(ta, 0);
	else if (ft_lstsize(*ta) == 4)
		sort_4(ta, tb, 0);
	else if (ft_lstsize(*ta) == 5)
		sort_5(ta, tb);
	else
		radix_sort(ta, tb);
}

int	main(int argc, char **argv)
{
	t_list	*ta;
	t_list	*tb;
	t_list	*tc;

	ta = NULL;
	tb = NULL;
	tc = NULL;
	if ((argc == 2 && get_list_one_arg(argv[1], &ta) == 0)
		|| (argc > 2 && get_list_multiple_arg(argc, argv, &ta) == 0))
		return (0);
	if (!is_sorted(ta))
		push_swap(&ta, &tb, &tc);
	ft_lstclear(&ta);
	ft_lstclear(&tb);
	ft_lstclear(&tc);
	return (0);
}
