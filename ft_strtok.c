/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtok.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/23 23:12:19 by jaukes        #+#    #+#                 */
/*   Updated: 2026/11/23 23:12:48 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strtok(char *s, const char *sep)
{
	static char	*p;
	size_t		idx;

	if (!s && !p)
		return (NULL);
	if (s)
		p = s;
	p += ft_strspn(p, sep);
	if (!*p)
	{
		p = NULL;
		return (NULL);
	}
	s = p;
	idx = ft_strcspn(p, sep);
	if (p[idx])
	{
		p[idx] = 0;
		p += idx + 1;
	}
	else
		p = NULL;
	return (s);
}
