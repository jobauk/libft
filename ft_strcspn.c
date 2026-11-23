/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcspn.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/22 20:25:54 by jaukes        #+#    #+#                 */
/*   Updated: 2026/11/23 23:11:57 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strcspn(const char *s, const char *c)
{
	const unsigned char	*u;
	size_t				tab[__FT_SPAN_TABSZ];
	size_t				i;

	i = 0;
	u = (unsigned char *)s;
	if (!c[0] || !c[1])
		return ((size_t)(ft_strchrnul(s, *c) - s));
	while (i < sizeof(tab) / sizeof(*tab))
		tab[i++] = 0;
	tab[0] = 1;
	while (*c)
	{
		tab[*(unsigned char *)c / __FT_SPAN_BITS]
			|= (size_t)1 << (*(unsigned char *)c % __FT_SPAN_BITS);
		c++;
	}
	while (1)
	{
		if (tab[*u / __FT_SPAN_BITS] & ((size_t)1 << (*u % __FT_SPAN_BITS)))
			break ;
		u++;
	}
	return ((size_t)((char *)u - s));
}
