/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 17:51:41 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/30 17:03:08 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static size_t	calc_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s)
		len += (*s++ == c);
	return (len + 1);
}

char	**ft_split(char const *s, char c)
{
	size_t		len;
	size_t		i;
	char const	*start;
	char		**arr;

	len = calc_len(s, c);
	i = 0;
	start = s;
	arr = malloc((len + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (*s)
	{
		if (*s == c)
		{
			arr[i] = malloc((s - start + 1) * sizeof(char));
			ft_strlcpy(arr[i++], start, (s - start + 1) * sizeof(char));
			start = s + 1;
		}
		s++;
	}
	arr[i] = malloc((s - start + 1) * sizeof(char));
	ft_strlcpy(arr[i++], start, (s - start + 1) * sizeof(char));
	arr[i] = NULL;

	return arr;
}

// #include <stdio.h>
//
// int main() {
// 	ft_split("hello world test", ' ');
//
// 	// printf("%ld\n", calc_len("Hello, world", ' '));
// 	// printf("%ld\n", calc_len("   Hello, x  world ", ' '));
// 	// printf("%ld\n", calc_len("Hello, world ", ' '));
// 	// printf("%ld\n", calc_len("Hello, world", '\0'));
// }
