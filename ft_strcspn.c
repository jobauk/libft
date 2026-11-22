/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcspn.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/22 20:25:54 by jaukes        #+#    #+#                 */
/*   Updated: 2026/11/22 20:26:38 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *s, const char *charset)
{
	size_t			size_t_bits;
	size_t			tab[32 / sizeof(size_t)];
	size_t			i;
	unsigned char	c;

	size_t_bits = (256 / (32 / sizeof(size_t)));
	i = 0;
	while (i < sizeof(tab) / sizeof(size_t))
		tab[i++] = 0;
	tab[0] = 1;
	while (*charset)
	{
		c = *(unsigned char *)charset++;
		tab[c / size_t_bits] |= (size_t)1 << (c % size_t_bits);
	}
	i = 0;
	while (1)
	{
		c = (unsigned char)s[i];
		if (tab[c / size_t_bits] & ((size_t)1 << ((size_t)c % size_t_bits)))
			break ;
		i++;
	}
	return (i);
}
