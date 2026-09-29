/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 14:49:11 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/29 14:53:54 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != c)
		s++;
	if (*s == c)
		return (s);
	return (NULL);
}

// #include <stdio.h>

// int main()
// {
// 	printf("<%s>\n", ft_strchr("Hello, world", ','));
// 	printf("<%s>\n", ft_strchr("Hello, world", 'x'));
// 	printf("<%s>\n", ft_strchr("Hello, world", 'l'));
// }
