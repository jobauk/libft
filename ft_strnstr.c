/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 16:19:30 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/29 17:07:18 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (i + j < len && big[i + j] == little[j])
			if (!little[j++])
				return (big + i);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>

// int main() {
// 	printf("<%s>\n", ft_strnstr("Hellx, Helo, Hello", "llo", 19));
// 	printf("<%s>\n", ft_strnstr("Hellx, Helo, Hello", "llo", 10));
// 	printf("<%s>\n", ft_strnstr("Hellx, Helo, Hello", "llox", 19));
// }
