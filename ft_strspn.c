/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strspn.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/23 23:13:10 by jaukes        #+#    #+#                 */
/*   Updated: 2026/11/23 23:13:11 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strspn(const char *s, const char *c)
{
	const unsigned char	*u;
	size_t				tab[__FT_SPAN_TABSZ];
	size_t				i;

	i = 0;
	u = (unsigned char *)s;
	if (!c[0])
		return (0);
	if (!c[1])
	{
		while (*s == *c)
			s++;
		return ((size_t)(s - (char *)u));
	}
	while (i < sizeof(tab) / sizeof(*tab))
		tab[i++] = 0;
	while (*c)
	{
		tab[*(unsigned char *)c / __FT_SPAN_BITS]
			|= (size_t)1 << (*(unsigned char *)c % __FT_SPAN_BITS);
		c++;
	}
	while (tab[*u / __FT_SPAN_BITS] & ((size_t)1 << (*u % __FT_SPAN_BITS)))
		u++;
	return ((size_t)((char *)u - s));
}
/* ************************************************************************** */
