/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 14:54:10 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/29 14:57:53 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == c)
			last = s;
		s++;
	}
	return (last);
}

// #include <stdio.h>

// int main()
// {
// 	printf("<%s>\n", ft_strrchr("Hello, world", ','));
// 	printf("<%s>\n", ft_strrchr("Hello, world", 'x'));
// 	printf("<%s>\n", ft_strrchr("Hello, world", 'l'));
// }
