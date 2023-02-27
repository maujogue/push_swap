/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:21:36 by maujogue          #+#    #+#             */
/*   Updated: 2023/01/17 13:44:59 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>

typedef struct num_list
{
	int				data;
	struct num_list	*next;
	struct num_list	*previous;
}	t_list;

/*libft functions */
long	ft_atoi(const char *str);
int		ft_strlen(char *str);
char	**ft_split(const char *str, char c);

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
void	ft_lstclear(t_list **lst);
int		ft_lstsize(t_list *lst);

/*printf functions */
void	ft_putnbr_count(int n, int *count);
void	ft_putnbr_unsigned_fd(unsigned int n, int fd, int *count);
void	ft_putnbr_hex_int(int nb, char *base, int *count);
void	ft_putnbr_hex_unsigned(unsigned long nb,
			char *base, int *count);
void	ft_putvoid_addrr(unsigned long nb, int *count);
void	ft_putnbr_hex(int nb, char *base, int *count);
void	ft_putchar_count(char c, int *count);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_count(char *s, int *count);
int		ft_printf(const char *str, ...);

/*push swap functions */
int		check_errors(char *str, long nb, t_list *tab);
int		is_sorted(t_list *tab);
void	print_chained_list(t_list *tab);
void	radix_sort(t_list **ta, t_list **tb);
void	sort_3(t_list **ta, int i);
void	sort_4(t_list **ta, t_list **tb, int i);
void	sort_5(t_list **ta, t_list **tb);
t_list	*sort_list(t_list *lst);
t_list	*cpy_list(t_list *lst);
void	replace_with_index(t_list *ta, t_list *tc);
void	push_swap(t_list **ta, t_list **tb, t_list **tc);

/*push swap instructions */
void	swap(t_list *tab, char c);
void	swap_ss(t_list *tab1, t_list *tab2);
void	push(t_list **ta, t_list **tb, char c);
void	rotate(t_list **ta, char c);
void	rotate_rr(t_list **ta, t_list **tb);
void	reverse_rotate(t_list **ta, char c);
void	reverse_rrr(t_list **ta, t_list **tb);

#endif