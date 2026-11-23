/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchrnul.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/23 23:05:27 by jaukes        #+#    #+#                 */
/*   Updated: 2026/11/23 23:05:38 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchrnul(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return ((char *)s);
}
