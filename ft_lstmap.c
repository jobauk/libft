/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 14:41:24 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/29 14:47:45 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*head;
	t_list	*cur;
	t_list	*next;
	(void)del;

	start = ft_lstnew(f(lst->content));
	cur = lst->next;
	head = start;
	free(lst);
	while (cur)
	{
		next = cur->next;
		head->next = ft_lstnew(f(cur->content));
		free(cur);
		cur = next;
		head = head->next;
	}
	return (start);
}

// #include <stdio.h>
//
// static void print_lst_item(void *content) {
// 	printf("  \"%s\",\n", (char *)content);
// }
//
// static void *to_upper(void *content) {
// 	char *str;
//
// 	str = content;
// 	while (*str) {
// 		*str = ft_toupper(*str);
// 		str++;
// 	}
// 	return (content);
// }
//
// int main() {
// 	t_list *start = ft_lstnew(ft_strdup("hello"));
// 	start->next = ft_lstnew(ft_strdup("world"));
// 	start->next->next = ft_lstnew(ft_strdup("test"));
//
// 	printf("[\n");
// 	ft_lstiter(start, print_lst_item);
// 	printf("]\n");
//
// 	t_list *mapped = ft_lstmap(start, to_upper, free);
//
// 	printf("[\n");
// 	ft_lstiter(mapped, print_lst_item);
// 	printf("]\n");
//
// 	ft_lstclear(&mapped, free);
// }
