/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 18:09:51 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/30 13:14:44 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_cap(const char *str, size_t cap)
{
	size_t	n;

	n = 0;
	while (str[n] && cap--)
		n++;
	return (n);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	substr_len;
	char	*substr;

	substr_len = ft_strlen_cap(s + start, len);
	substr = (char *)malloc((substr_len + 1) * sizeof(char));
	if (substr)
		ft_strlcpy(substr, s + start, substr_len + 1);
	return (substr);
}

// #include <stdio.h>
//
// int main() {
// 	char str[] = "Hello, world";
//
// 	printf("%s\n", ft_substr(str, 0, 5));
// 	printf("%s\n", ft_substr(str, 1, 5));
// 	printf("%s\n", ft_substr(str, 7, 5));
// 	printf("%s\n", ft_substr(str, 3, 10));
// }
