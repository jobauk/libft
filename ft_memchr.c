/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 15:54:36 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/29 16:10:44 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*us;

	us = s;
	while (*us != (unsigned char)c && n--)
		us++;
	if (*us == (unsigned char)c)
		return (us);
	return (NULL);
}

// int main()
// {

// }
