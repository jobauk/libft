/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/28 16:18:44 by jaukes        #+#    #+#                 */
/*   Updated: 2026/11/11 21:39:50 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (*s++)
		n++;
	return (n);
}

// #include <stdio.h>

// int main() {
// 	printf("%ld", ft_strlen(""));
// }
